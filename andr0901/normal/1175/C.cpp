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
#define int long long

int n, k;

int f(int x, vector <int>& a) {
    vector <int> d(n);
    forn (i, 0, n)
        d[i] = abs(a[i] - x);
    sort(all(d));
    return d[k];
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        cin >> n >> k;
        vector <int> a(n);
        forn (i, 0, n) 
            cin >> a[i];
        int ans = 2e9, ans_x;
        forn (i, 0, n - k) {
            if ((a[i + k] - a[i] + 1) / 2 < ans) {
                ans = (a[i + k] - a[i] + 1) / 2;
                ans_x = (a[i] + a[i + k]) / 2;
                //cout << ans_x << " ";
            }
        }
        cout << ans_x << "\n";
        /*int l = 0, r = 1e9 + 1;
        while (r - l > 2) {
            int m1 = l + (r - l) / 3, m2 = l + 2 * (r - l) / 3;
            if (f(m1, a) < f(m2, a))
                r = m2;
            else 
                l = m1;
        }
        int ans = l;
        forn (i, l, r + 1)
            if (f(i, a) < f(ans, a))
                ans = i;
        cout << ans << f(ans, a) << "\n";*/
    }
    return 0;
}