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
#include <numeric>

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

vector<vector<int>> e;
vector<int> du, dv;
map<int, vector<int>> mp;
int n;


tuple<int, int> get(vector<int>& a) {
    random_shuffle(all(a));
    assert(a.size());
    cout << "? " << a.size();
    for (auto& x : a) {
        assert(0 <= x);
        assert(x < n);
        cout << " " << x + 1;
    }
    cout << endl;
    cout.flush();

    int x, d;
    x = d = -1;

#ifdef LOCAL
    d = 1e+9 + 42;
    for (auto& v : a) {
        if (chmin(d, du[v] + dv[v])) {
            x = v;
        }
    }
#else
    cin >> x >> d;
    if (x == -1) {
        exit(0);
    }
    --x;
#endif

#ifdef LOCAL
    cout << "= " << x << " " << d << endl;
#endif

    return {x, d};
}

void dfs(int x, int p, int d) {
    mp[d].push_back(x);
    for (auto& y : e[x]) {
        if (y == p) {
            continue;
        }
        dfs(y, x, d + 1);
    }
}


int main(int /* argc */, char** /* argv */)
{
    srand(time(NULL));
#ifdef LOCAL
    assert(freopen("inp", "r", stdin));
#endif

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        e = vector<vector<int>>(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        auto get_dists = [&](int st) {
            vector<int> d(n, -1);
            queue<int> q;
            d[st] = 0;
            q.push(st);
            while (q.size()) {
                int x = q.front();
                q.pop();
                for (auto& y : e[x]) {
                    if (d[y] == -1) {
                        d[y] = d[x] + 1;
                        q.push(y);
                    }
                }
            }
            return d;
        };
#ifdef LOCAL
        int U, V;
        // cin >> U >> V;
        // --U;
        // --V;
        do {
            U = rand() % n;
            V = rand() % n;
        } while (U == V);
        du = get_dists(U);
        dv = get_dists(V);
        dbg(du);
        dbg(dv);
#endif
        int root;
        int dist;
        {
            vector<int> a(n);
            iota(all(a), 0);
            tie(root, dist) = get(a);
        }
        mp.clear();
        dfs(root, -1, 0);
        int left = (dist + 1) / 2;
        int right = min(mp.rbegin()->first, dist);
        int fs;
        while (left <= right) {
            int middle = (left + right + 1) / 2;
            vector<int> a;
            for (auto& [d, v] : mp) {
                if (d >= middle) {
                    a.insert(a.end(), all(v));
                }
            }
            int val;
            tie(fs, val) = get(a);
            if (left == right) {
                break;
            }
            if (val == dist) {
                left = middle;
            } else {
                right = middle - 1;
            }
        }
        auto dists = get_dists(fs);
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            if (dists[i] == dist) {
                b.push_back(i);
            }
        }
        auto [sc, _] = get(b);
        cout << "! " << fs + 1 << " " << sc + 1 << endl;
        cout.flush();
#ifdef LOCAL
        assert(fs == U || fs == V);
        assert(sc == U || sc == V);
#endif
        string s;
        cin >> s;
        if (s == "Incorrect") {
            exit(0);
        }
    }
    return 0;
}