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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int MAXN = 2 * 1e+5 + 42;
const int MOD = 1000000007;

vector <vector<pair<int, int>>> e;
ll f[MAXN][2];
int s[MAXN];
int u[MAXN];

int dfs(int x, int p = 0) {
    int res = 0;
    s[x] = 1;
    u[x] = true;
    for (auto& i : e[x]) {
        int y = i.first;
        int k = i.second;
        if (p == k) {
            continue;
        }
        if (u[y]) {
            res = y == x? 1 : 2;
            continue;
        }
        res |= dfs(y, k);
        s[x] += s[y];
    }
    return res;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    while (cin >> n && n) {
        e = vector<vector<pair<int, int>>>(MAXN, vector<pair<int, int>>(0));
        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            e[u].emplace_back(v, i);
            e[v].emplace_back(u, i);
        }
        memset(u, 0, sizeof(u));
        memset(s, 0, sizeof(s));
        ll ans = 1;
        for (int i = 1; i < MAXN; ++i) {
            if (!u[i] && e[i].size()) {
                int res = dfs(i, -1);
                (ans *= (res? res : s[i])) %= MOD;
            }
        }
        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}