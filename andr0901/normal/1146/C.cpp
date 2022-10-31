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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
    	int n;
    	cin >> n;
    	int mx = 0;
    	vector <int> a(n);
    	forn (i, 0, n)
    		a[i] = i + 1;
    	forn (i, 0, 9) {
    		vector <int> b, c;
    		forn (j, 0, n) {
    			if (a[j] % 2)
    				b.pb(j + 1);
    			else 
    				c.pb(j + 1);
    		}
    		if (!b.empty() && !c.empty()) {
    			cout << sz(b) << " " << sz(c) << " ";
    			forn (i, 0, sz(b))
    				cout << b[i] << " ";
    			forn (i, 0, sz(c)) 
    				cout << c[i] << " ";
    			cout << endl;
    			int ans;
    			cin >> ans;
    			mx = max(mx, ans);
    		} else {
    			cout << "-1 " << mx << endl;
    			break;
    		}
    		forn (j, 0, n) 
    			a[j] /= 2;
    	}
    }
    return 0;
}