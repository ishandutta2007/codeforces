#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <random>
#include <bitset>

#define sqr(x) ((x) * (x))
#define F first
#define S second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
//#define int ll
#define mp(a) make_pair(a)

#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const int INF = 1e9 + 7;
const ld PI = 3.141592653589793;
const ld EPS = 1e-9;
const int N = 1e3 + 5;

void dfs(int v, vvi& g, vi& ts, vc& used) {
    used[v] = 1;
    for (int u : g[v]) {
        if (!used[u])
            dfs(u, g, ts, used);
    }
    ts.push_back(v);
}

void solution() {
    int n;
    cin >> n;
    vvi a(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    }
    vvi dp = a;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][k] && dp[k][j])
                    dp[i][j] = 1;
            }
        }
    }
    vi c(n, -1);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] != -1)
            continue;
        c[i] = k;
        for (int j = 0; j < n; ++j) {
            if (j != i && dp[i][j] && dp[j][i])
                c[j] = k;
        }
        ++k;
    }
    vvi g(k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] && c[i] != c[j]) {
                g[c[i]].push_back(c[j]);
            }
        }
    }
    for (int i = 0; i < k; ++i)
        g[i].erase(unique(all(g[i])), g[i].end());
    vi ts;
    vc used(k);
    for (int i = 0; i < k; ++i) {
        if (!used[i])
            dfs(i, g, ts, used);
    }
    reverse(all(ts));
    vi bck(k);
    for (int i = 0; i < k; ++i) {
        bck[ts[i]] = i;
    }
    vvi layers(k);
    vvi g1(k);
    int m = k;
    for (int i = 0; i < k; ++i)
        layers[i] = { i };
    for (int i = 0; i < k; ++i) {
        for (int u : g[ts[i]]) {
            int j = bck[u];
            int prev = i;
            for (int x = i + 1; x < j; ++x) {
                g1[prev].push_back(layers[x].size());
                layers[x].push_back(m);
                prev = m;
                g1.push_back({});
                ++m;
            }
            g1[prev].push_back(0);
        }
    }
    int sz = 9;
    for (int i = 0; i < k; ++i) {
        sz = max(sz, (int)layers[i].size() * 3);
    }
    vector<vector<string>> ans(k * 2);
    vector<string> empty(sz), full(sz);
    {
        string s1, s2;
        for (int j = 0; j < sz; ++j) {
            s1 += '.';
            s2 += '#';
        }
        for (int i = 0; i < sz; ++i) {
            empty[i] = s1;
            full[i] = s2;
        }
    }
    for (int i = 0; i < k; ++i) {
        ans[i * 2] = empty;
        ans[i * 2 + 1] = full;
        for (int j = 0; j < sz / 3; ++j) {
            for (int x = 0; x < sz; ++x) {
                if (i % 2)
                    ans[i * 2][j * 3][x] = '#';
                else
                    ans[i * 2][x][j * 3] = '#';
            }
        }
        for (int v = 0; v < layers[i].size(); ++v) {
            for (int u : g1[layers[i][v]]) {
                if (i % 2)
                    ans[i * 2 + 1][v * 3 + 2][u * 3 + 1] = '.';
                else
                    ans[i * 2 + 1][u * 3 + 1][v * 3 + 2] = '.';
            }
        }
    }
    vi used1(k);
    for (int i = 0; i < n; ++i) {
        int x = bck[c[i]];
        if (x % 2)
            ans[x * 2][1][used1[x]] = '0' + i + 1;
        else
            ans[x * 2][used1[x]][1] = '0' + i + 1;
        ++used1[x];
    }
    cout << sz << ' ' << sz << ' ' << k * 2 << '\n';
    for (int i = 0; i < k * 2; ++i) {
        for (int j = 0; j < sz; ++j)
            cout << ans[i][j] << '\n';
        cout << '\n';
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i)
        solution();

    return 0;
}