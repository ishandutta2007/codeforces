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
    int n;
    cin >> n;
    vector <int> a, b;
    int s = 0;
    forn (i, 0, n) {
    	int t;
    	cin >> t;
    	if (t % 2)
    		a.pb(t);
    	else 
    		b.pb(t);
    	s += t;
    }
    sort(rall(a)), sort(rall(b));
    int ans1;
    int i, j, f;
    ans1 = 0, i = 0, j = 0, f = 1;
    while (true) {
    	if (f) {
    		if (i == sz(a))
    			break;
    		ans1 += a[i++];
    	} else {
    		if (j == sz(b)) 
    			break;
    		ans1 += b[j++];
    	}
    	f ^= 1;
    }
    int ans2;
    ans2 = 0, i = 0, j = 0, f = 0;
    while (true) {
    	if (f) {
    		if (i == sz(a))
    			break;
    		ans2 += a[i++];
    	} else {
    		if (j == sz(b)) 
    			break;
    		ans2 += b[j++];
    	}
    	f ^= 1;
    }
    cout << s - max(ans1, ans2);
    return 0;
}