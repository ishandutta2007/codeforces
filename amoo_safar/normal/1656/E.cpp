
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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<int> G[N];
int col[N];
void DFS(int u, int p, int c){
	col[u] = c * ((int) G[u].size());
	for(auto adj : G[u])
		if(adj != p)
			DFS(adj, u, -c);
}

int Main(){
	ll n; cin >> n;
	for(int i = 1; i <= n; i++) G[i].clear();
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, -1, 1);
	for(int i = 1; i <= n; i++) cout << col[i] << ' ';
		cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}