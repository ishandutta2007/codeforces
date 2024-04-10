#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector <pii> a(n);
    forn (i, 0, n) 
        cin >> a[i].fs >> a[i].sc;
    vector <vector <int>> dp(1 << n, vector <int> (4));
    dp[0][0] = 1;
    int ans = 0;
    forn (mask, 0, 1 << n) {
        forn (i, 0, n) 
            if ((mask >> i) & 1) 
                forn (j, 0, 4) 
                    if (j != a[i].sc) 
                        dp[mask][a[i].sc] = add(dp[mask][a[i].sc], dp[mask ^ (1 << i)][j]);
        int cnt = 0;
        forn (i, 0, n) 
            if ((mask >> i) & 1)
                cnt += a[i].fs;
        if (cnt == t) 
            forn (j, 1, 4)  
                ans = add(ans, dp[mask][j]);
    }
    cout << ans;
    return 0;
}