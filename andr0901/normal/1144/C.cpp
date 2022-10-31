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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n)
    	cin >> a[i];
    sort(all(a));
    vector <int> b, c;
    b.pb(-INF), c.pb(INF);
    forn (i, 0, n) {
    	if (a[i] == c.back())  
    		return cout << "NO", 0;
    	if (a[i] == b.back()) 
    		c.pb(a[i]);
    	else 
    		b.pb(a[i]);
    }
    cout << "YES\n";
    cout << sz(b) - 1 << "\n";
    forn (i, 1, sz(b))
    	cout << b[i] << " ";
    cout << "\n";
    sort(rall(c));
    cout << sz(c) - 1 << "\n";
    forn (i, 1, sz(c))
    	cout << c[i] << " ";	
    return 0;
}