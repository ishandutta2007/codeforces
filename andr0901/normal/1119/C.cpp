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
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m));
    forn (i, 0, n) 
    	forn (j, 0, m) 
    		cin >> a[i][j];
    vector <vector <int>> b(n, vector <int> (m));
    forn (i, 0, n)
    	forn (j, 0, m)
    		cin >> b[i][j];
    forn (i, 0, n - 1) {
    	forn (j, 0, m - 1) {
    		if (a[i][j] != b[i][j]) {
    			a[i][j] ^= 1;
    			a[i + 1][j] ^= 1;
    			a[i][j + 1] ^= 1;
    			a[i + 1][j + 1] ^= 1;
    		}
    	}
    }
    forn (i, 0, n)
    	forn (j, 0, m)
    		if (a[i][j] != b[i][j])
    			return cout << "No", 0;
    cout << "Yes";
    return 0;
}