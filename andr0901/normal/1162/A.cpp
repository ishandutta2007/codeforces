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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, h, m;
    cin >> n >> h >> m;
    vector <int> a(n, h);
    forn (i, 0, m) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        forn (j, l, r)
            a[j] = min(a[j], x);
    }
    int ans = 0;
    forn (i, 0, n)
        ans += a[i] * a[i];
    cout << ans;
    return 0;
}