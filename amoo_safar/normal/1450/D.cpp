// har ki ro didi goft mikhad beshe meslemon !
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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


vector<int> V[N];

int par[N], sz[N];
int Find(int u){
	if(par[u] == u) return u;
	return par[u] = Find(par[u]);
}
void Merge(int u, int v){
	u = Find(u);
	v = Find(v);
	if(u == v) return ;
	par[u] = v;
	sz[v] += sz[u];
}
int Get(int x){
	return sz[Find(x)];
}

int mk[N], a[N];
int Main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) V[i].clear();
	iota(par, par + n, 0);
	fill(sz, sz + n, 1);
	fill(mk, mk + n, 0);

	for(int i = 0; i < n; i++){
		cin >> a[i];
		V[a[i]].pb(i);
	}
	vector<int> ps(n+3, 0);
	for(int i = n; i >= 1; i--){
		if(V[i].empty()) continue;
		for(auto x : V[i]){
			if(x > 0 && mk[x - 1] == 1) Merge(x - 1, x);
			if(x + 1 < n && mk[x + 1] == 1) Merge(x, x + 1);		
			mk[x] = 1;
		}
		int mx = 0;
		for(auto x : V[i]){
			mx = max(mx, Get(x));
		}
		ps[1] ++;
		ps[min(mx, n - i + 1) + 1] --;
	}
	for(int i = 2; i <= n; i++) ps[i] += ps[i - 1];
	for(int i = 1; i <= n; i++)
		if(ps[i] == n - i + 1)
			cout << '1';
		else
			cout << '0';
	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}