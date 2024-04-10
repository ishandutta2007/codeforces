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
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m));
    forn (i, 0, n) 
    	forn (j, 0, m) 
    		cin >> a[i][j];
    int s = 0;
    forn (i, 0, n)
    	s ^= a[i][0];
    if (s) {
    	cout << "TAK\n";
    	forn (i, 0, n)
    		cout << "1 ";
    	return 0;
    }
    forn (i, 0, n) {
    	forn (j, 1, m) {
    		if (a[i][j] != a[i][0]) {
    			cout << "TAK\n";
    			forn (k, 0, i)
    				cout << "1 ";
    			cout << j + 1 << " ";
    			forn (k, i + 1, n)
    				cout << "1 ";
    			return 0;
    		}
    	}
    }
    cout << "NIE";
    return 0;
}