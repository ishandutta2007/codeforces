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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n --> 0) {
    	string s;
    	cin >> s;
    	vector <char> a;
    	forn (i, 0, sz(s))
    		a.pb(s[i]);
    	sort(all(a));
    	bool f = 1;
    	forn (i, 1, sz(a)) 
    		if (a[i] != a[i - 1] + 1)
 				f = 0;
    	if (f)
    		cout << "Yes\n";
    	else 
    		cout << "No\n";
    }
    return 0;
}