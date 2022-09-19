// vaziat meshki-ghermeze !
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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> G[N];

ll dep[N];

void DFS(int u, int p, int d = 0){
	dep[u] = d;
	for(auto adj : G[u])
		if(dep[adj] == -1)
			DFS(adj, u, d + 1);
}

ll mk[N];
int Main(){
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) G[i].clear();

	ll u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	fill(dep, dep + n + 1, -1);
	DFS(1, -1);
	vector<ll> I(n);
	iota(all(I), 1);
	sort(all(I), [&](int i, int j){
		return dep[i] < dep[j];
	});
	if(dep[I[0]] == -1)
		return cout << "NO\n", 0;
	fill(mk, mk +  n+ 1, 0);
	vector<ll> A;
	for(auto i : I){
		mk[i] = 1;
		for(auto adj : G[i]) if(mk[adj]) mk[i] = 0;
		if(mk[i]) A.pb(i);
	}
	cout << "YES\n" << A.size() << '\n';
	for(auto x : A) cout << x << ' ';
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