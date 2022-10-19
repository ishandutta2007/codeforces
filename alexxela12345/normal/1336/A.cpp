#ifndef DEBUG
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
typedef long long ll;
typedef long double ldb;

int n, k;
vector<vector<int>> g;
vector<int> p;
vector<int> d;
vector<int> ch;
vector<int> sz;

void dfs(int v, int pp = -1) {
    p[v] = pp;
    sz[v] = 1;
    for (int u : g[v]) {
        if (u != pp) {
            ch[v]++;
            d[u] = d[v] + 1;
            dfs(u, v);
            sz[v] += sz[u];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(12);
    cin >> n >> k;
    ch.resize(n);
    d.resize(n);
    p.resize(n);
    g.resize(n);
    sz.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    d[0] = 0;
    dfs(0, -1);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        if (!ch[i]) {
            s.insert({-d[i], i});
        }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        auto pp = *s.begin();
        s.erase(s.begin());
        ans -= pp.first;
        if (p[pp.second] != -1) {
             d[p[pp.second]] -= sz[pp.second];
             ch[p[pp.second]] -= 1;
             if (!ch[p[pp.second]]) {
                 s.insert({-d[p[pp.second]], p[pp.second]});
             }
        }
    }
    cout << ans << endl;
}

// If interactive problem remove #define endl '\n'
// CopyPasted part from BenQ:

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/