#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , timer , root[MAXN] , ans[MAXN] , fn[MAXN] , st[MAXN] , sz[MAXN];
vector<int> adj[MAXN];

void DFS(int v , int p = -1){
	st[v] = timer++; sz[v] = 1;
	for(int u : adj[v]){
		if(u == p)	continue;
		root[u] = (p == -1 ? u : root[v]);
		DFS(u , v);
		sz[v] += sz[u];
	}
	fn[v] = timer++;
}

int isPar(int v , int u){
	return (st[v] < st[u] || fn[u] < fn[v]);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n; timer = 0;
		fill(ans , ans + n + 5 , 0);
		fill(adj , adj + n + 5 , vector<int>());
		for(int i = 1 ; i < n ; i++){
			int v , u;
			cin >> v >> u;
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		DFS(0);
		int v = 0 , u = 0; // v : min fn , u : max st
		for(int i = 0 ; i < n ; i++){
			if(i == 0){
				ans[1] = n * (n - 1) / 2;
				for(int j : adj[0]){
					ans[1] -= sz[j] * (sz[j] - 1) / 2;
				}
				continue;
			}
			if(v == u && root[v] == root[i] && isPar(i , v) && isPar(v , i))	break;
			if(v != u){
				if(isPar(i , v) && isPar(v , i) && isPar(i , u) && isPar(u , i))
					break;
			}
			if(fn[i] < fn[v])	v = i;
			if(st[i] > st[u])	u = i;
			if(v != u){
				ans[i + 1] = sz[v] * sz[u];
				continue;
			}
			ans[i + 1] = sz[v] * (n - sz[root[v]]);
		}
		ans[0] = n * (n - 1) / 2;
		for(int i = 0 ; i <= n ; i++){
			cout << ans[i] - ans[i + 1] << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/