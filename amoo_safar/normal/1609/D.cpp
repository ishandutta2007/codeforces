// Dennis - Toney
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
const int N = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

struct DisjointSet {
	int par[N], sz[N];
	DisjointSet (int _n){
		iota(par, par + _n, 0);
		fill(sz, sz + _n, 1);
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
		sz[v] += sz[u];
		return true;
	}
};
int x[N], y[N];
int Main(){
	int n, d;
	cin >> n >> d;
	DisjointSet ds(n);
	vector<int> V;
	int yy = 1;
	for(int i = 0; i < d; i++){
		cin >> x[i] >> y[i];
		x[i] --; y[i] --;
		if(!ds.Unite(x[i], y[i])){
			yy++;

		}
		V.clear();
		for(int j = 0; j < n; j++)
			if(ds[j] == j)
				V.pb(ds.sz[j]);
		sort(all(V)); reverse(all(V));
		int ans = 0;
		// debug(yy);
		for(int j = 0; j < min((int) V.size(), yy); j++) ans += V[j];
		cout << ans-1 << '\n';
	}

	// cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// for(int i = 2; i < N; i++)
	// 	if(pr[i] == 0)
	// 		for(int j = i + i; j < N; j += i)
				// pr[j] = 1;
	int tc = 1;
	// cin >> tc;
	while(tc --) Main();
	return 0;
}
/*
1
7 3
10 2 1 3 1 19 3

*/