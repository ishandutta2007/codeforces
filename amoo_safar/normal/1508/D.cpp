// faz lati nemigire bache shir !
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
const ll Inf = 2'000'000'000'000'000'000ll;
const ll Log = 30;

pll po[N];
int p[N];
pll operator -(pll A, pll B){
	return {A.F - B.F, A.S - B.S};
}
bool Right(pll A, pll B){ // is A right of B?
	return A.F * B.S - A.S * B.F > 0;
}
struct DisjointSet {
	int par[N];
	DisjointSet(){
		iota(par, par + N, 0);
	}
	int operator [](int u){
		return Find(u);
	}
	int Find(int u){
		return (par[u] == u ? u : par[u] = Find(par[u]));
	}
	bool Unite(int u, int v){
		u = Find(u); v = Find(v);
		if(u == v) return false;
		par[u] = v;
		return true;
	}
};
DisjointSet dsu;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int st = -1;
	for(int i = 1; i <= n; i++){
		cin >> po[i].F >> po[i].S >> p[i];
		if(p[i] != i) st = i;
		dsu.Unite(i, p[i]);
	}
	if(st == -1) return cout << "0\n", 0;

	vector<int> I;
	for(int i = 1; i <= n; i++) if(i != st) I.pb(i);
	for(int i = 1; i <= n; i++) if(i != st) po[i] = po[i] - po[st];

	sort(all(I), [&](int i, int j){
		int fi = (po[i]) > pll(0, 0);
		int fj = (po[j]) > pll(0, 0);
		if(fi == fj)
			return Right(po[i], po[j]);
		return fi == 1;
	});
	I.pb(I[0]);
	vector<pll> ans;
	for(int i = 0; i + 1 < (int) I.size(); i ++){
		if(dsu[I[i]] == dsu[I[i + 1]]) continue;
		if(Right(po[I[i]], po[I[i + 1]])){
			dsu.Unite(I[i], I[i + 1]);
			swap(p[I[i]], p[I[i + 1]]);
			ans.pb({I[i], I[i + 1]});
		}
	}

	while(p[st] != st){
		ans.pb({st, p[st]});
		swap(p[st], p[p[st]]);
	}
	cout << ans.size() << '\n';
	for(auto x : ans) cout << x.F << ' ' << x.S << '\n';
	return 0;
}