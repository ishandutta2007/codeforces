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
    int n, t;
    cin >> n >> t;
    int mn = 1e9, idx;
    forn (i, 0, n) {
    	int a, b;
    	cin >> a >> b;
    	while (a < t) 
    		a += b;
    	if (a < mn) 
    		mn = a, idx = i;
    }
    cout << idx + 1;
    return 0;
}