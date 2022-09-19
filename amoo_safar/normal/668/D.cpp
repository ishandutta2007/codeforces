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
const int Maxn = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[Maxn], t[Maxn], x[Maxn], ans[Maxn];

ll fen[Maxn];
vector<ll> Vt, Vx;

void add(ll idx, ll d){
	for(;idx < Maxn; idx += (idx & (-idx))) fen[idx] += d;	
}
ll get(ll idx){
	ll res = 0;
	for(; idx; idx -= (idx & (-idx))) res += fen[idx];
	return res;
}
vector< pair<pll, ll> > Q[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> t[i] >> x[i];
		Vt.pb(t[i]);
		Vx.pb(x[i]);
	}
	sort(all(Vt));
	Vt.resize(unique(all(Vt)) - Vt.begin());
	sort(all(Vx));
	Vx.resize(unique(all(Vx)) - Vx.begin());
	
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		t[i] = (lower_bound(all(Vt), t[i]) - Vt.begin() ) + 1;
		x[i] = (lower_bound(all(Vx), x[i]) - Vx.begin() ) + 1;
		if(a[i] == 3) cnt ++;
		Q[x[i]].pb({{a[i], t[i]}, cnt});		
	}
	for(int i = 0; i < Maxn; i++){
		for(auto X : Q[i]){
			if(X.F.F == 1) add(X.F.S, 1);
			if(X.F.F == 2) add(X.F.S, -1);
			if(X.F.F == 3) ans[X.S] = get(X.F.S);
		}
		for(auto X : Q[i]){
			if(X.F.F == 1) add(X.F.S, -1);
			if(X.F.F == 2) add(X.F.S, 1);
		}
	}
	//cerr << cnt << '\n';
	for(int i = 1; i <= cnt; i++) cout << ans[i] << '\n';
	return 0;
}
/*
3
0.25 0 0.75
0.75 0 0.25

2
0 1
1 0
*/