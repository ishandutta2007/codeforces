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
    int n, m, h;
    cin >> n >> m >> h;
    vector <int> a(m);
    forn (i, 0, m)
    	cin >> a[i];
    vector <int> b(n);
    forn (i, 0, n)
    	cin >> b[i];
    vector <vector <int>> c(n, vector <int> (m));
    forn (i, 0, n) {
    	forn (j, 0, m) {
    		cin >> c[i][j];
    		if (c[i][j]) 
    			c[i][j] = min(a[j], b[i]);
    	}
    }
    forn (i, 0, n) {
    	forn (j, 0, m)
    		cout << c[i][j] << " ";
    	cout << "\n";
    }

    return 0;
}