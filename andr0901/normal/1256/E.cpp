#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
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
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a(n + 1);
    forn (i, 1, n + 1) {
        cin >> a[i].fs;
        a[i].sc = i;
    }
    sort(all(a));
    /*forn (i, 1, n + 1)
        cout << a[i].fs << " ";
    cout << "\n";*/
    vector <int> dp(n + 5, 1e18), par(n + 5, -1);
    dp[0] = 0;
    forn (i, 1, n + 1) {
        forn (j, 2, 5) {
            if (dp[i - 1] + a[i + j].fs - a[i].fs < dp[i + j]) {
                dp[i + j] = dp[i - 1] + a[i + j].fs - a[i].fs;
                par[i + j] = j;
            }
        }
        //cout << dp[i] << " ";
    }
    /*forn (i, 1, n + 1)
        cout << par[i] << " ";
    cout << dp[n];*/
    int commands = 0;
    vector <int> ans(n);
    int i = n;
    while (par[i] != -1) {
        forn (j, i - par[i] - 1, i) {
            ans[a[j + 1].sc - 1] = commands;
        }
        commands++;
        i -= par[i] + 1;
    }
    cout << dp[n] << " " << commands << "\n";
    for (int i : ans)
        cout << i + 1 << " ";
    return 0;
}