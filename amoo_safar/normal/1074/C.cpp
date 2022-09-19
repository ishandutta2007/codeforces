#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 1e15;
const ld EPS = (ld) 1e-8;

pll a[MAXN];

ll d(ll i, ll j){
	return abs(a[i].F - a[j].F) + abs(a[i].S - a[j].S);
}
ll d3(ll i, ll j, ll k){
	return d(i,j) + d(j,k) + d(k,i);
}

vector<ll> g;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	ll minx = INF;
	ll maxx = -INF;
	ll miny = INF;
	ll maxy = -INF;
	ll minxi = 0;
	ll maxxi = 0;
	ll minyi = 0;
	ll maxyi = 0;
	debug(abs(-INF-INF));
	for(int i = 0;i<n;i++){
		cin >> a[i].F >> a[i].S;
		if(a[i].F < minx){
			minx = a[i].F;
			minxi = i;
		}
		if(a[i].F > maxx){
			maxx = a[i].F;
			maxxi = i;
		}
		if(a[i].S > maxy){
			maxy = a[i].S;
			maxyi = i;
		}
		if(a[i].S < miny){
			miny = a[i].S;
			minyi = i;
		}
	}
	
	if(n == 3){
		return cout << d(0,1)+d(1,2)+d(2,0), 0;
	}
	
	for(int i = 0; i < n; i++){
		if(a[i].F == minx) g.pb(i);
		if(a[i].F == maxx) g.pb(i);
		if(a[i].S == miny) g.pb(i);
		if(a[i].S == maxy) g.pb(i);
	}
	/*ll f = 0;
	ll ind[4] = {minxi, maxxi,minyi,maxyi};
	for(int i = 0;i<4;i++){
		for(int j = 0;j<4;j++){
			if((ind[i] == ind[j]) and (i != j)) f = 1;
		}
	}*/
	ll ans2 = 0, an;
	ll t = (ll)g.size();
	debug(t);
	for(int i = 0;i<t;i++){
		for(int j = i + 1; j < t; j++){
			for(int k = j + 1; k < t;k++){
				
				ans2 = max(ans2, d(g[i],g[j]) + d(g[j],g[k]) + d(g[k],g[i]));
			}
		}
	}
	for(int i = 0;i<n;i++){
		an = max(d3(i,maxxi,maxyi), d3(i, maxxi, minyi));
		an = max(an ,max(d3(i,minxi,maxyi), d3(i, minxi, maxyi)));
		//an = 0;
		for(int k = 0;k<t;k++){
			for(int j = k + 1; j < t; j++){
				an = max(an , d3(i, g[k],g[j]));
			}
		}
		ans2 = max(ans2, an);
	}
	
	//ll a1 = minxi;
	//ll a2 = maxyi;
	
	//ll a3 = maxxi;
	//ll a4 = minyi;
	//ll ans = d(minxi, minyi) + d(minxi,maxyi) + d(maxxi,minyi) + d(maxxi,maxyi);
	ll ans = 2ll * ((maxx - minx) + (maxy-miny));
	//ll ans2 = max(max(d(a1,a2) + d(a2,a3) + d(a3,a1), d(a1,a2) + d(a2,a4) + d(a4,a1)),  max(d(a1,a3) + d(a3,a4) + d(a4,a1), d(a2,a3) + d(a3,a4) + d(a4,a2)));
	cout << ans2 << " ";
	for(int i = 0;i < n-3; i++) cout << ans << " ";
	return 0;
}


/*
5
0 0
1 -2
0 -3
-10 -2
-10 -1
                                 ____              ,----..               ,----..
   ,---,                       ,'  , `.           /   /   \             /   /   \
  '  .' \                   ,-+-,.' _ |          /   .     :           /   .     :
 /  ;    '.              ,-+-. ;   , ||         .   /   ;.  \         .   /   ;.  \
:  :       \            ,--.'|'   |  ;|        .   ;   /  ` ;        .   ;   /  ` ;
:  |   /\   \          |   |  ,', |  ':        ;   |  ; \ ; |        ;   |  ; \ ; |
|  :  ' ;.   :         |   | /  | |  ||        |   :  | ; | '        |   :  | ; | '
|  |  ;/  \   \        '   | :  | :  |,        .   |  ' ' ' :        .   |  ' ' ' :
'  :  | \  \ ,'        ;   . |  ; |--'         '   ;  \; /  |        '   ;  \; /  |
|  |  '  '--'          |   : |  | ,             \   \  ',  /          \   \  ',  /
|  :  :                |   : '  |/               ;   :    /            ;   :    /
|  | ,'                ;   | |`-'                 \   \ .'              \   \ .'
`--''                  |   ;/                      `---`                 `---`
                       '---'

*/