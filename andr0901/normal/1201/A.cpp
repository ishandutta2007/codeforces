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

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(m, vector <int> (5));
    forn (i, 0, n) {
        string s;
        cin >> s;
        forn (j, 0, m)
            a[j][s[j] - 'A']++;
    }
    vector <int> b(m);
    forn (i, 0, m)
        cin >> b[i];
    int ans = 0;
    forn (i, 0, m) {
        int mx = 0;
        forn (j, 0, 5)
            mx = max(mx, a[i][j]);
        ans += b[i] * mx;
    }
    cout << ans;
    return 0;
}