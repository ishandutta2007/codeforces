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

int n , m , ans , edge , vertex , mark[MAXN];
vector<int> adj[MAXN];

void DFS(int v){
	mark[v] = 1;
	vertex++;
	edge += SZ(adj[v]);
	for(int u : adj[v]){
		if(mark[u])	continue;
		DFS(u);
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for(int i = 1 ; i <= n ; i++){
		if(mark[i])	continue;
		edge = vertex = 0;
		DFS(i);
		edge /= 2;
		if(edge + 1 == vertex){
			ans++;
		}
	}
	cout << ans << endl;

    return 0;
}
/*

*/