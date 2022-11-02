#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

int n;
int x1, x2, y1, y2;

ll x[2222], y[2222];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> x1 >> y1 >> x2 >> y2;
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    }
    ll ans = (1ll<<60);
    x[n] = x1;
    y[n] = y1;
    for(int i = 0; i <= n; i++){
    	ll dist = (x1 - x[i]) * 1ll * (x1-x[i]) + (y1 - y[i] ) * 1ll * (y1-y[i]);
    	ll dist2 = 0;
    	for(int j = 0; j < n; j++){
	    	ll cur = (x1 - x[j]) * 1ll * (x1-x[j]) + (y1 - y[j] ) * 1ll * (y1-y[j]);
	    	if(cur <= dist) continue;
	    	dist2 = max(dist2, (x2 - x[j]) * 1ll * (x2-x[j]) + (y2 - y[j] ) * 1ll * (y2-y[j]));
    	}
    	ans = min(ans, dist + dist2);
    }
    cout << ans << endl;
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}