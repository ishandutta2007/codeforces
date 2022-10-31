#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
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
    int n;
    cin >> n; 
    vector <pii> a(n);
    forn (i, 0, n)
    	cin >> a[i].fs >> a[i].sc;
    sort(rall(a), [&](pii a, pii b){return a.fs - a.sc < b.fs - b.sc;});
    ll ans = 0;
    forn (i, 0, n)
    	ans += (i + 1) * (a[i].fs - a[i].sc) + a[i].sc * n - a[i].fs;
    cout << ans;
    return 0;
}