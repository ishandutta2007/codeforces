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


const vector<tuple<int, int, char>> dxyc = {{1, 0, 'U'}, {0, 1, 'L'}, {-1, 0, 'D'}, {0, -1, 'R'}};

vector<vector<int>> e;
vector<int> c;
vector<int> lft, rht;
vector<int> q;
ll ans = 0;
int n, m, k;
int root = 1;


void dfs(int x, int& t) {
    lft[x] = ++t;
    for (auto& y : e[x]) {
        dfs(y, t);
    }
    rht[x] = t;
}


vector<int> ct;
vector<int> mn;
vector<int> delta;

void push(int x) {
    for (auto& y : {2 * x + 0, 2 * x + 1}) {
        delta[y] += delta[x];
        mn[y] += delta[x];
    }
    delta[x] = 0;
}

void build(int curr, int l, int r) {
    if (l < r) {
        int c = (l + r) / 2;
        build(2 * curr + 0, l + 0, c);
        build(2 * curr + 1, c + 1, r);
    }
    ct[curr] = r - l + 1;
}

void merge(int x) {
    int l = 2 * x + 0;
    int r = 2 * x + 1;

    mn[x] = min(mn[l], mn[r]);
    ct[x] = (mn[x] == mn[l]? ct[l] : 0) + (mn[x] == mn[r]? ct[r] : 0);
}

void modify(int curr, int l, int r, int lq, int rq, int dq) {
    if (r < lq || rq < l) {
        return;
    }
    if (lq <= l && r <= rq) {
        delta[curr] += dq;
        mn[curr] += dq;
        return;
    }

    int c = (l + r) / 2;
    push(curr);

    modify(2 * curr + 0, l + 0, c, lq, rq, dq);
    modify(2 * curr + 1, c + 1, r, lq, rq, dq);

    merge(curr);
}


void rec(int x) {
    modify(root, 1, k, lft[q[x]], rht[q[x]], 1);

    if (mn[root] == 0) {
        ans += k - ct[root];
    }
    for (auto& y : e[x]) {
        rec(y);
    }

    modify(root, 1, k, lft[q[x]], rht[q[x]], -1);
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    while (cin >> n >> m) {
        vector<string> s(n);
        for(int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        vector<vector<int>> a(n, vector<int>(m, 0));
        k = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = k++;
            }
        }

        e = vector<vector<int>>(k);
        c = vector<int>(k, 0);
        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                for (auto& [dx, dy, ch] : dxyc) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x < 0 || n <= x || y < 0 || m <= y || s[x][y] != ch) {
                        continue;
                    }
                    int v = a[x + dx][y + dy];
                    e[a[i][j]].push_back(v);
                    c[v] += 1;
                }
            }
        }

        lft = vector<int>(k, 0);
        rht = vector<int>(k, 0);
        int t = 0;
        for (int i = 0; i < k; ++i) {
            if (c[i] == 0) {
                dfs(i, t);
            }
        }
        q = vector<int>(k, -1);
        ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == 'U') {
                    q[a[i][j]] = a[i + 1][j];
                    q[a[i + 1][j]] = a[i][j];
                }
                if (s[i][j] == 'L') {
                    q[a[i][j]] = a[i][j + 1];
                    q[a[i][j + 1]] = a[i][j];
                }
            }
        }

        ct = vector<int>(4 * k + 1, 0);
        mn = vector<int>(4 * k + 1, 0);
        delta = vector<int>(4 * k + 1, 0);
        build(root, 1, k);

        for (int i = 0; i < k; ++i) {
            if (c[i] == 0) {
                rec(i);
            }
        }
        cout << ans / 2 << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}