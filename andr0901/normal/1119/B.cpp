#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
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
    int n, h;
    cin >> n >> h;
    vector <int> a(n);
    forn (i, 0, n)
    	cin >> a[i];
    forn (i, 0, n + 1) {
    	vector <int> b;
    	forn (j, 0, i)
    		b.pb(a[j]);
    	sort(all(b));
    	int l = 0, r = 0;
    	for (int j = 0; j < sz(b); j += 2)
    		l += b[j];
    	for (int j = 1; j < sz(b); j += 2)
    		r += b[j];
    	if (max(l, r) > h)
    		return cout << i - 1, 0;
    }
    cout << n;
    return 0;
}