#pragma GCC optimize("Ofast")
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
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    int s = 0;
    vector <int> b(101);
    forn (i, 0, n) {
        s += a[i];
        int cur_s = s, ans = 0;
        for (int j = 100; j > 0; j--) {
            if (cur_s - j * b[j] <= m) {
                ans += max(0LL, (cur_s - m + j - 1) / j);
                //cout << j << ": " << ans + (cur_s - m + j - 1) / j << "\n";
                break;
            } else {
                cur_s -= j * b[j];
                ans += b[j];
            }
        }
        b[a[i]]++;
        cout << ans << " ";
    }
    return 0;
}