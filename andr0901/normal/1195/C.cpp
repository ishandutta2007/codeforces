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
#define int long long

int nxt() {
    int x;
    cin >> x;
    return x;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n = nxt();
    vector <vector <int>> a(n, vector <int> (2));
    forn (i, 0, n) 
        a[i][0] = nxt();
    forn (i, 0, n) 
        a[i][1] = nxt();
    int ans = 0;
    vector <vector <int>> dp(n, vector <int> (2));
    vector <int> mx(2);
    forn (i, 0, n) {
        dp[i][0] = mx[1] + a[i][0];
        dp[i][1] = mx[0] + a[i][1];
        ans = max({ans, dp[i][0], dp[i][1]});
        mx[0] = max(mx[0], dp[i][0]);
        mx[1] = max(mx[1], dp[i][1]);
    }
    cout << ans;
    return 0;
}