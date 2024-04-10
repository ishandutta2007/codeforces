#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e5 + 10;
const ll Inf = 2e16;
const ll Log = 30;

vector<pll> V;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll x, y, ax, ay, bx, by;
	cin >> x >> y >> ax >> ay >> bx >> by;
	
	while(max(x, y) <= Inf){
		V.pb({x, y});
		x = x * ax + bx;
		y = y * ay + by;
	}
	ll m = V.size();
	ll X, Y, T;
	cin >> X >> Y >> T;
	ll ans = 0;
	ll rt;
	for(int i = 0; i < m; i++){
		for(int j = i; j < m; j++){
			ll rt = abs(V[i].F - V[j].F) + abs(V[i].S - V[j].S) + min(abs(V[i].F - X) + abs(V[i].S - Y), abs(V[j].F - X) + abs(V[j].S - Y));	
			if(rt <= T) ans = max(ans, j - i + 1ll);
		}
	}
	
	
	cout << ans << '\n';
	return 0;
}