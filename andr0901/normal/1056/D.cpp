#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <vector <int>> gr;
vector <int> dp;

int dfs(int v, int p = -1) {
    for (auto u : gr[v])
        dp[v] += dfs(u, v);
    if (!sz(gr[v]))
        dp[v]++;
    return dp[v];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    gr.resize(n);
    forn (i, 1, n) {
        int t;
        cin >> t, t--;
        gr[t].pb(i);
    }
    dp.resize(n);
    dfs(0);
    sort(all(dp));
    forn (i, 0, n) 
        cout << dp[i] << " ";
    return 0;
}