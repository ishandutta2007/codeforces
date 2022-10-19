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

const ll MAXN = 5010;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , ans , mark[MAXN] , dist[MAXN];
vector<int> adj[MAXN] , radj[MAXN] , ord , vec;

void DFS(int v){
	mark[v] = 1;
	for(int u : adj[v]){
		if(!mark[u]){
			DFS(u);
		}
	}
	ord.push_back(v);
}

void DFS2(int v){
	mark[v] = 1;
	for(int u : radj[v]){
		if(!mark[u]){
			DFS2(u);
		}
	}
	vec.push_back(v);
}

void DFS3(int v){
	mark[v] = 1;
	for(int u : adj[v]){
		if(!mark[u]){
			DFS3(u);
		}
	}
}

int solve(int v){
	fill(dist , dist + MAXN , MOD);
	queue<int> Q;
	Q.push(v); dist[v] = 0;
	while(!Q.empty()){
		int v = Q.front(); Q.pop();
		for(int u : adj[v]){
			if(dist[u] == MOD){
				dist[u] = dist[v] + 1;
				Q.push(u);
			}
		}
	}
	int res = MOD;
	for(int u : radj[v]){
		res = min(res , dist[u] + 1);
	}
	return (res == MOD ? 0 : res);
}

void SCC(){
	for(int i = 1 ; i <= n ; i++){
		if(!mark[i]){
			DFS(i);
		}
	}
	fill(mark , mark + MAXN , 0);
	reverse(all(ord));
	for(int i : ord){
		if(mark[i])	continue;
		vec.clear();
		DFS2(i);
		int cur = MOD;
		for(int v : vec){
			cur = min(cur , solve(v));
		}
		ans += (cur == 0 ? 0 : cur * 998 + 1);
		for(int v : vec){
			mark[v] = 0;
		}
		DFS3(i);
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin >> v >> u;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	SCC();
	cout << ans + n << endl;

    return 0;
}
/*

*/