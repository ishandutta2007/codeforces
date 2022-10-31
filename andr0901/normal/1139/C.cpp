#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

vector <vector <int>> gr;
const int MOD = 1e9 + 7;

int bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    int t = bin_pow(a, p / 2);
    return (1LL * t * t) % MOD;
}

vector <int> col;
int cur = 1;

void dfs(int v, int p) {
    col[v] = cur;
    for (auto u : gr[v])
        if (u != p)
            dfs(u, v);
}


main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    gr.resize(n);
    forn (i, 1, n) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        t1--, t2--;
        if (!t3)
            gr[t1].pb(t2), gr[t2].pb(t1);
    }
    col.resize(n);
    forn (i, 0, n)
        if (!col[i])
            dfs(i, -2), cur++;
    vector <int> a(n + 1);
    /*forn (i, 0, n)
        cout << col[i] << " ";*/
    forn (i, 0, n + 1)
        a[i] = bin_pow(i, k);
    int ans = a[n];
    map <int, int> mp;
    forn (i, 0, n)
        mp[col[i]]++;
    for (auto i : mp)
        ans = (ans - a[i.sc] + 2 * MOD) % MOD;
    cout << ans;
    return 0;
}