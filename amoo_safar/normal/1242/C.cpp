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
 
const ll Mod = 1e9 + 7;
const ll Inf = 2242545357980376863LL;
const ll Log = 20;
//const ll N = 1ll << Log;
const int Maxn = 34e3;
const int Base = 101;
typedef pair<pll, ll> node;

vector<ll> b[Maxn];

ll S[20];
map<ll, ll> mp;
ll mk[20];
ll dp[Maxn];
bool val[Maxn];

bool OK[Maxn];
ll par[Maxn];

ll C[Maxn], P[Maxn], K,DD;

void solve(ll mak){
	//cerr << mak << '\n';
	if(mak == 0) return ;
	if(val[mak]){
		ll y = dp[mak]; 
		ll x = y;
		memset(mk, 0, sizeof mk);
		ll i = mp[y];
		ll to, nx, nw = i;
		mk[i] = 1;
		bool fl = true;
		while(true){
			nx = DD - (S[nw] - x);
			if(!mp.count(nx)) {
				fl = false;
				break;
			}
			to = mp[nx];
			
			C[to] = nx;
			P[to] = nw;
			if(to == i){
				if(nx != y) fl = false;
				break;
			}
			if(mk[to]) {
				fl = false;
				break;
			}
			mk[to] = 1;
			x = nx;
			nw = to;
		}		
		return ;
	}
	solve(mak ^ par[mak]);
	solve(par[mak]);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll k;
	cin >> k;
	K = k;
	ll v;
	ll sm = 0;
	ll n;
	for(int i = 1; i <= k; i++){
		cin >> n;
		for(int j = 1; j <= n; j++){
			cin >> v;
			b[i].pb(v);
			mp[v] = i;
			sm += v;
			S[i] += v;
		}
	}
	ll d = sm / k;
	DD = d;
	if(sm % k != 0) return cout << "No\n", 0;
	//cerr << "S : " << d << '\n';
	ll nx, to;
	for(int i = 1; i <= k; i++){
		//S = 0;
		//for(auto x : b[i]) S += x;
		for(auto y : b[i]){
			ll x = y;
			memset(mk, 0, sizeof mk);
			ll nw = i;
			mk[i] = 1;
			bool fl = true;
			while(true){
				nx = d - (S[nw] - x);
				if(!mp.count(nx)) {
					fl = false;
					break;
				}
				to = mp[nx];
				if(to == i){
					if(nx != y) fl = false;
					break;
				}
				if(mk[to]) {
					fl = false;
					break;
				}
				mk[to] = 1;
				x = nx;
				nw = to;
			}
			if(fl){
				ll res = 0;
				for(int i = 0; i < k; i++) if(mk[i + 1]) res |= (1 << i);
				val[res] = true;
				dp[res] = y;
				//cerr << res << '\n';
			}
		}
	}
	OK[0] = true;
	for(int i = 1; i < (1 << k); i++){
		if(val[i]){
			OK[i] = true;
			par[i] = -1;
		}
		ll sub = i;
		while(sub != 0){
			sub = (sub - 1) & i;
			if(OK[sub] && OK[sub ^ i] && sub){
				OK[i] = true;
				par[i] = sub;
			}
		}
	}
	ll all = (1<<k) - 1;
	if(!OK[all]) return cout << "No\n", 0;
	cout << "Yes\n";
	//cerr << par[all] << '\n';
	solve(all);
	for(int i = 1; i <= K; i++) cout << C[i] << ' ' << P[i] << '\n';
	return 0;
}