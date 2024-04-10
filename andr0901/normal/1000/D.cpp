#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int n;

bool valid(int i) {
    return (0 <= i && i <= n);
}

const int MOD = 998244353;

int add(int a, int b) {
    if (a + b >= MOD)
        return a + b - MOD;
    return a + b;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector <vector <int>> c(n + 1, vector <int> (n + 1));
    forn (i, 0, n + 1) {
        c[i][0] = c[i][i] = 1;
        forn (j, 1, i)
            c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
    }
    //forn (i, 0, n)
      //  forn (j, 0, n)
        //    cout << i << " " << j << ": " << c[i][j] << "\n";
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    vector <int> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        int st = i + 1 + a[i];
        //cout << st << "\n";
        if (!valid(st) || a[i] <= 0)
            continue;
        forn (j, st, n + 1) {
            //cout << c[j - i - 1][a[i]] << "\n";
            dp[i] = add(dp[i], mul(dp[j], c[j - i - 1][a[i]]));
        }
    }
    int ans = 0;
    forn (i, 0, n)
        ans = add(ans, dp[i]);
    cout << ans;
    return 0;
}