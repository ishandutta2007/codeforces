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

const int MOD = 998244353;

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    forn (i, 0, n) {
        cin >> a[i];
        a[i] *= (i + 1) * (n - i);
    }
    sort(all(a));
    forn (i, 0, n) 
        cin >> b[i];
    sort(rall(b));
    int ans = 0;
    forn (i, 0, n)
        ans = (ans + (a[i] % MOD) * b[i]) % MOD;
    cout << ans;
    return 0;
}