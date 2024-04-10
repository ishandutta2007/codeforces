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
#define N 100005
#define INF 101111111111111
using namespace std;
vector<ll> d[N];
ll dsup[N], dsuz[N];
ll _parent(ll a){
	return (dsup[a] == a ? a : dsup[a] = _parent(dsup[a]));
}
set<ll> acmp;
void _union(ll a, ll b){
	a = _parent(a);
	b = _parent(b);
	if(a != b) {
		dsuz[a]+=dsuz[b], dsup[b] = a;
		acmp.erase(b);
	}
}
int main(){
	FAST;
	ll n, m;
	cin >> n >> m;
	for(ll i =0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		d[u].pb(v);
		d[v].pb(u);
	}
	for(ll i =1;i<=n;i++){
		dsup[i] = i;
		dsuz[i] = 1;
		acmp.insert(i);
		map<ll, ll> comps;
		for(auto j : d[i]){
			if(j < i) comps[_parent(j)]++;
		}
		set<ll> oac = acmp;
		for(auto j : oac){
			j = _parent(j);
			if(comps[j] < dsuz[j]) _union(j, i);
		}
	}
	cout << acmp.size()-1 << endl;
}