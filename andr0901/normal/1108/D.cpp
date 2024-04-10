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

int char_to_int(char c) {
    if (c == 'R')
        return 0;
    if (c == 'B')
        return 1;
    if (c == 'G')
        return 2;
}

char int_to_char(int a) {
    if (a == 0)
        return 'R';
    if (a == 1)
        return 'B';
    if (a == 2)
        return 'G';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n) {
        char c;
        cin >> c;
        a[i] = char_to_int(c);
    }
    vector <vector <int>> dp(n, vector <int> (3, 1e9)), par(n, vector <int> (3));
    forn (i, 0, 3)
        dp[0][i] = 1;
    dp[0][a[0]] = 0;
    forn (i, 1, n) {
        forn (j, 0, 3) {
            forn (k, 0, 3) {
                if (j == k) 
                    continue;
                int delta = (k != a[i]);
                if (dp[i - 1][j] + delta < dp[i][k]) {
                    dp[i][k] = dp[i - 1][j] + delta;
                    par[i][k] = j;
                }
            }
        }
    }
    cout << *min_element(all(dp[n - 1])) << "\n";
    vector <int> ans;
    int j = min_element(all(dp[n - 1])) - dp[n - 1].begin();
    for (int i = n - 1; i >= 0; i--) {
        ans.pb(j);
        j = par[i][j];
    }
    while (!ans.empty()) {
        cout << int_to_char(ans.back());
        ans.pop_back();
    }
    return 0;
}