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
const int Maxn = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> V[Maxn];

ll p[Maxn], w[Maxn], b[Maxn], c[Maxn], d[Maxn], x[Maxn];

int get(int u){
	if(p[u] == u) return u;
	int v;
	v = get(p[u]);
	x[u] = x[u] ^ x[p[u]];
	p[u] = v;
	return v;
}
void merge(int u, int v, int W){
	int pu = get(u);
	int pv = get(v);
	if(u == v) return ;
	if((d[pu] == 0 && d[pv] == 0) || (d[pv] == 1)){
		p[pu] = pv;
		x[pu] = x[u] ^ x[v] ^ W;
		if(x[pu] ^ c[pv] != c[pu]){
			w[pv] += b[pu];
			b[pv] += w[pu];
		} else {
			w[pv] += w[pu];
			b[pv] += b[pu];
		}
		return ;
	}
	swap(u, v); swap(pu, pv);
	p[pu] = pv;
	x[pu] = x[u] ^ x[v] ^ W;
	if(x[pu] ^ c[pv] != c[pu]){
		w[pv] += b[pu];
		b[pv] += w[pu];
	} else {
		w[pv] += w[pu];
		b[pv] += b[pu];
	}
	return ;
}
void deter(int u, int W){
	int pu = get(u);
	W ^= x[u];
	if(d[pu]) return ;
	d[pu] = 1;
	c[pu] = W;
	if(W) swap(b[pu], w[pu]);
	return ;
}
int calc(int u){
	int pu = get(u);
	if(d[pu]) return w[pu];
	return min(b[pu], w[pu]);
}
ll ans = 0;

void Merge(int u, int v, int W){
	if(get(u) == get(v)) return ;
	ans -= calc(u);
	ans -= calc(v);
	merge(u, v, W);
	ans += calc(u);
}
void Deter(int u, int W){
	//cerr << "!!! " << u << " " << W << '\n';
	ans -= calc(u);
	deter(u, W);
	ans += calc(u);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	iota(p, p + Maxn, 0);
	fill(b, b + Maxn, 1);
	ll n, k;
	cin >> n >> k;
	str s;
	cin >> s; s = '1' + s;
	ll v;
	for(int i = 0; i < k; i++){
		ll sz;
		cin >> sz;
		for(int j = 0; j < sz; j++){
			cin >> v;
			V[v].pb(i);
		}
	}
	for(int i = 1; i <= n; i++){
		ll deg = V[i].size();
		if(deg != 0){
			if(deg == 1){
				if(s[i] == '0') Deter(V[i][0], 1);
				else Deter(V[i][0], 0);
			} else {
				if(s[i] == '0') Merge(V[i][0], V[i][1], 1);
				else Merge(V[i][0], V[i][1], 0);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}