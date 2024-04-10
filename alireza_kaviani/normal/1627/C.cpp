#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , ans[MAXN];
vector<pii> adj[MAXN];

void DFS(int v , int p , int col){
	for(pii i : adj[v]){
		int u = i.X , ind = i.Y;
		if(u == p)	continue;
		ans[ind] = col;
		DFS(u , v , 5 - col);
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		for(int i = 0 ; i < n + 5 ; i++){
			ans[i] = 0;
			adj[i].clear();
		}
		for(int i = 1 ; i < n ; i++){
			int v , u;
			cin >> v >> u;
			adj[v].push_back({u , i});
			adj[u].push_back({v , i});
		}
		int flag = 0 , leaf = -1;
		for(int i = 1 ; i <= n ; i++){
			if(SZ(adj[i]) > 2){
				flag = 1;
			}
			if(SZ(adj[i]) == 1){
				leaf = i;
			}
		}
		if(flag){
			cout << -1 << endl;
			continue;
		}
		DFS(leaf , -1 , 2);
		for(int i = 1 ; i < n ; i++){
			cout << ans[i] << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/