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

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    a.pb(-1);
    vector <int> b;
    forn (i, 0, n)
        if (a[i] != a[i + 1])
            b.pb(a[i]);
    vector <int> c = b;
    reverse(all(c));
    n = b.size();
    vector <vector <int>> dp(n + 1, vector <int> (n + 1));
    forn (i, 1, n + 1) {
        forn (j, 1, n + 1) {
            if (b[i - 1] == c[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i][j]});
        }
    }
    cout << n - (dp[n][n] + 1) / 2;
    return 0;
}