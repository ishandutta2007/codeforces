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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    ll ans = 0;
    forn (i, 0, n) {
        cin >> a[i];
        ans += 1LL * a[i] * m;
    }
    sort(rall(a));
    forn (i, 0, m) {
        cin >> b[i];
        if (b[i] < a[0])
            return cout << -1, 0;
    }
    sort(all(b));
    forn (i, 1, m) 
        ans += b[i] - a[0];
    if (b[0] != a[0])
        ans += b[0] - a[1];
    cout << ans;
    return 0;
}