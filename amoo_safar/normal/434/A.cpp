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
const ll N = 1ll << Log;
const int Maxn = 1e5 + 10;
const int Base = 101;

map<ll, vector<ll>> mp;
ll a[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	ll ans = Inf;
	ll v = 0;
	for(int i = 1; i < m; i++) if(a[i] != a[i + 1]){
		mp[a[i]].pb(a[i + 1]);
		mp[a[i + 1]].pb(a[i]);
		v += abs(a[i + 1] - a[i]);
	}
	ans = v;
	//ll ans = 0;
	ll v2;
	//cerr << v << '\n';
	for(auto x : mp){
		sort(all(x.S));
		ll X = x.S[((int) x.S.size()) / 2];
		v2 = v;
		for(auto y : x.S){
			v2 -= abs(x.F - y);
			v2 += abs(X - y);
		}
		ans = min(ans, v2);
		//cerr << v2 << " " << x.F << '\n';
	}
	cout << ans;
	return 0;
}