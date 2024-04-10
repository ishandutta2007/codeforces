#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#define idbg(x) #x " = " << x
#include "pretty_print.h"
#else
#define dbg(x)
#define idbg(x) ""
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

struct TLine {
    int id;
    int x, y;
    int x1, y1, x2, y2;
};

map<int, vector<int>> mp[2];

vector<TLine> lines[2];

vector<vector <int>> e;
vector<vector <int>> r;
vector<int> nxt;
vector<int> prv;
vector<int> upd;


int cnt;

int n, m;

bool rec(int x, bool dry_run=false) {
    if (x == -2 || upd[x] == cnt) {
        return false;
    }
    upd[x] = cnt;
    for (auto& y : e[x]) {
        if (prv[y] == -1 || rec(prv[y], dry_run)) {
            if (!dry_run) {
                prv[y] = x;
                nxt[x] = y;
            }
            return true;
        }
    }
    return false;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    srand(42);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        mp[0][x].push_back(y);
        mp[1][y].push_back(x);
    }

    for (int it = 0; it < 2; ++it) {
        int c = 0;
        for (auto& iter : mp[it]) {
            int k = iter.first;
            vector<int>& v = iter.second;
            sort(all(v));
            for (int i = 1; i < v.size(); ++i) {
                TLine line;
                line.id = c++;
                if (it == 0) {
                    line.x = line.x1 = line.x2 = k;
                    line.y1 = v[i - 1];
                    line.y2 = v[i];
                } else {
                    line.y = line.y1 = line.y2 = k;
                    line.x1 = v[i - 1];
                    line.x2 = v[i];
                }
                lines[it].push_back(line);
            }
        }
        random_shuffle(all(lines[it]));
        dbg(c);
    }

    n = lines[0].size();
    m = lines[1].size();
    dbg(n);
    dbg(m);
    e.resize(n);
    r.resize(m);

    nxt.resize(n, -1);
    prv.resize(m, -1);

    for (auto& l0 : lines[0]) {
        for (auto& l1 : lines[1]) {
            if (l1.x1 < l0.x && l0.x < l1.x2 && l0.y1 < l1.y && l1.y < l0.y2) {
                int u = l0.id;
                int v = l1.id;
                e[u].push_back(v);
                r[v].push_back(u);
                if (nxt[u] == -1 && prv[v] == -1) {
                    nxt[u] = v;
                    prv[v] = u;
                }
            }
        }
    }

    upd.resize(n, 0);
    cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (nxt[i] == -1) {
            ++cnt;
            rec(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nxt[i] >= 0) {
            ++cnt;
            if (rec(i, true)) {
                queue<int> q;
                q.push(nxt[i]);
                while (q.size()) {
                    int y = q.front();
                    q.pop();
                    nxt[prv[y]] = -2;
                    for (auto& x : r[y]) {
                        if (nxt[x] >= 0) {
                            q.push(nxt[x]);
                        }
                    }
                }
            } else {
                queue<int> q;
                q.push(i);
                while (q.size()) {
                    int x = q.front();
                    q.pop();
                    prv[nxt[x]] = -2;
                    for (auto& y : e[x]) {
                        if (prv[y] >= 0) {
                            q.push(prv[y]);
                        }
                    }
                }
            }
        }
    }

    for (int it = 1; it >= 0; --it) {
        lines[it].clear();
        int c = 0;
        for (auto& iter : mp[it]) {
            int k = iter.first;
            vector<int>& v = iter.second;
            sort(all(v));
            int last = v[0];
            for (int i = 1; i <= v.size(); ++i) {
                if (i == v.size() || (it == 0? nxt : prv)[c] == -2) {
                    TLine line;
                    if (it == 0) {
                        line.x = line.x1 = line.x2 = k;
                        line.y1 = last;
                        line.y2 = v[i - 1];
                    } else {
                        line.y = line.y1 = line.y2 = k;
                        line.x1 = last;
                        line.x2 = v[i - 1];
                    }
                    lines[it].push_back(line);

                    if (i == v.size()) {
                        break;
                    }
                    last = v[i];
                }
                ++c;
            }
        }
        dbg(c);

        cout << lines[it].size() << "\n";
        for (auto& line : lines[it]) {
            cout << line.x1 << " " << line.y1 << " " << line.x2 << " " << line.y2 << "\n";
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}