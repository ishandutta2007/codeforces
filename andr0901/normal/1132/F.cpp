#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

string s;
vector <vector <int>> dp;

int solve(int l, int r) {
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l >= r)
        return dp[l][r] = 0;
    if (l == r - 1)
        return dp[l][r] = 1;
    dp[l][r] = 1 + solve(l + 1, r);
    forn (i, l + 1, r)
        if (s[l] == s[i])
            dp[l][r] = min(dp[l][r], solve(l + 1, i) + solve(i, r));
    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> s;
    dp.resize(n, vector <int> (n + 1, -1));
    cout << solve(0, n);
    return 0;
}