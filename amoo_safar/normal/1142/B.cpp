#include <bits/stdc++.h>

#define pb push_back

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 92233720368545;
const ld EPS = (ld) 1e-8;
const ll LOG = 20;

ll nx[MAXN][LOG], RMQ[MAXN][LOG];
ll p[MAXN], nex[MAXN], a[MAXN];
ll vis[MAXN], val[MAXN];

ll lift(ll ind, ll x){
	for(int i = 0; i < LOG; i++){
		if(x & (1ll << i)) ind = nx[ind][i];
	}
	return ind;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i < n; i++) nex[p[i]] = p[i + 1];
	nex[p[n]] = p[1];
	for(int i = 1; i <= m; i++) cin >> a[i];
	//debug(nex[1]);
	fill(vis, vis + MAXN, m + 1);
	for(int i = m; i > 0; i--){
		nx[i][0] = vis[nex[a[i]]];
		vis[a[i]] = i;// debug(a[i]);
		//debug(vis[a[i]]);
		//cerr << nx[i][0] << " " ;
	}
	//cerr << '\n';
	//debug(vis[2]);
	nx[m + 1][0] = m + 1;
	
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= m + 1; j++) nx[j][i] = nx[ nx[j][i - 1] ][i - 1];
	}
	for(int i = 1; i <= m; i++) val[i] = lift(i, n - 1);

	memset(RMQ, 31, sizeof RMQ);

	for(int i = 1; i <= m; i++) RMQ[i][0] = val[i];
	
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= m + 1; j++) RMQ[j][i] = min(RMQ[j][i - 1], RMQ[min(m + 1ll, j + (1ll << (i - 1)))][i - 1]);
	}
	ll l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		ll len = r - l + 1;
		ll mx = val[l];
		ll ind = l;
		for(int j = 0; j < LOG; j++){
			if(len & (1ll << j)){
				mx = min(mx, RMQ[ind][j]);
				ind += (1ll << j);
			}
		}
		
		if(mx <= r) cout << "1";
		else cout << "0";
	}
	return 0;
}