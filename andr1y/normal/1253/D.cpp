#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200005
#define INF 101111111111111
using namespace std;
vector<ll> d[N];
ll minf[N], maxf[N];
ll belongs[N];
bool was[N];
void dfs(ll v, ll p, ll cp){
	was[v] = 1;
	minf[cp] = min(minf[cp], v);
	maxf[cp] = max(maxf[cp], v);
	belongs[v] = cp;
	for(auto i : d[v])
		if(i!=p && !was[i]) dfs(i, v, cp);
}

ll dsup[N], dsus[N];
ll _parent(ll fr){
	return (dsup[fr] == fr ? fr : dsup[fr] = _parent(dsup[fr]));
}
void _union(ll a, ll b){
	a = _parent(a);
	b = _parent(b);
	if(a != b) dsus[a]+=dsus[b], dsup[b] = a;
}

int main(){
	FAST;
	ll n, m;
	cin >> n >> m;
	for(ll i =0;i<m;i++){
		ll a, b;
		cin >> a >> b;
		d[a].pb(b);
		d[b].pb(a);
	}
	ll comps = 0;
	for(ll i = 1;i<=n;i++){
		if(!was[i]){
			minf[comps] = INF;
			maxf[comps] = -INF;
			dfs(i, -1, comps);
			++comps;
		}
	}
	for(ll i = 0;i<comps;i++) dsup[i] = i, dsus[i] = 1;
	/*for(ll i = 0;i<comps;i++){
		for(ll j = minf[i]; j<= maxf[i];j++) if(belongs[j] != i) _union(i, belongs[j]);
	}*/
	ll expect = -1, pred = -1;
	map<ll, bool> scan_allow;
	for(ll i = 1;i<=n;i++){
		if(expect == -1){
			scan_allow[belongs[i]] = 1;
			expect = maxf[belongs[i]];
			pred = belongs[i];
		}
		if(expect != -1){
			if(!scan_allow[belongs[i]]){
				scan_allow[belongs[i]] = 1;
				expect = max(expect, maxf[belongs[i]]);
				_union(belongs[i], pred);
			}
		}
		if(i == expect){
			scan_allow.clear();
			expect = -1;
			pred = -1;
		}
	}
	set<ll> resz;
	ll resx = 0;
	for(ll i = 0;i<comps;i++){
		ll osz = resz.size();
		resz.insert(_parent(i));
		if(resz.size() > osz){
			resx += dsus[_parent(i)]-1;
		}
	}
	cout << resx << endl;
}