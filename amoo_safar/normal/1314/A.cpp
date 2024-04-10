#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

map<ll, ll> mp;
void C(ll i){
	if(!mp.count(i)) mp[i] = i;
}
ll Get(ll u){
	C(u);
	if(mp[u] == u) return u;
	return mp[u] = Get(mp[u]);
}
void Merge(ll u, ll v){
	u = Get(u);
	v = Get(v);
	if(u == v) return ;
	mp[u] = v;
}
ll Fill(ll x){
	C(x);
	C(x + 1);
	Merge(x, x + 1);
}

vector<pll> V;
ll a[N], b[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >>a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		V.pb({b[i], a[i]});
	}
	sort(all(V));
	reverse(all(V));
	ll ans = 0;
	for(auto x : V){
		C(x.S);
		ll idx = Get(x.S);
		ans += (idx - x.S) * x.F;
		Fill(idx);
	}
	cout<< ans << '\n';
	return 0;
}