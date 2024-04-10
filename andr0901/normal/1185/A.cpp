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
    vector <int> a(3);
    forn (i, 0, 3)
        cin >> a[i];
    int d;
    cin >> d;
    sort(all(a));
    int ans = 0;
    if (a[2] - a[1] <= d)
        ans += d - (a[2] - a[1]);
    if (a[1] - a[0] <= d)
        ans += d - (a[1] - a[0]);
    cout << ans;
    return 0;
}