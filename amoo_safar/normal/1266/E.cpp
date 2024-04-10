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
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

map<pll, ll> mp;

ll a[Maxn];

ll get(ll i){
	if(i == 0) return 0;
	return max(0LL, a[i]);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ans += get(i);
	}
	ll q;
	cin >> q;
	ll s, t, u;
	for(int i = 0; i < q; i++){
		cin >> s >> t >> u;
		ans -= get(mp[pll(s, t)]);
		a[mp[pll(s, t)]] ++;
		ans += get( mp[pll(s, t)] );
		mp[pll(s, t)] = u;
		
		ans -= get(u);
		a[u] --;
		ans += get(u);
		cout << ans<<'\n';
	}
	return 0;
}