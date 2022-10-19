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
#define SZ(x)       ll(x.14size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , A[MAXN] , col[MAXN] , dpDown[MAXN] , dpUp[MAXN] , sum[MAXN] , mx[MAXN] , sz[MAXN];
vector<int> adj[MAXN];

void DFSDown(int v , int p = -1){
	sz[v] = 1;
	sum[v] = mx[v] = 0;
	dpDown[v] = dpUp[v] = 0;
	for(int u : adj[v]){
		if(u == p)	continue;
		DFSDown(u , v);
		if(dpDown[u] == sz[u]){
			sum[v] += dpDown[u];
			dpDown[v] += dpDown[u];
		}
		else{
			mx[v] = max(mx[v] , dpDown[u]);
		}
		sz[v] += sz[u];
	}
	dpDown[v] = (dpDown[v] + mx[v] + col[v]) * col[v];
}

void DFSUp(int v , int p = -1){
	int S = 0 , MX = 0;
	if(dpUp[v] == n - sz[v]){
		S = dpUp[v];
	}
	else{
		MX = dpUp[v];
	}
	for(int u : adj[v]){
		if(u == p)	continue;
		if(dpDown[u] == sz[u]){
			S += dpDown[u];
		}
	}
	for(int u : adj[v]){
		if(u == p)	continue;
		int cur = S;
		if(dpDown[u] == sz[u]){
			cur -= dpDown[u];
		}
		dpUp[u] = max(dpUp[u] , (cur + MX + col[v]) * col[v]);
		if(dpDown[u] < sz[u]){
			MX = max(MX , dpDown[u]);
		}
	}
	reverse(all(adj[v])); MX = 0;
	for(int u : adj[v]){
		if(u == p)	continue;
		int cur = S;
		if(dpDown[u] == sz[u]){
			cur -= dpDown[u];
		}
		dpUp[u] = max(dpUp[u] , (cur + MX + col[v]) * col[v]);
		if(dpDown[u] < sz[u]){
			MX = max(MX , dpDown[u]);
		}
		DFSUp(u , v);
	}
}

int check(int x){
//	cout << "===========" << endl;
//	cout << x << endl;
	for(int i = 1 ; i <= n ; i++){
		col[i] = (A[i] >= x);
	}
	DFSDown(1);
	DFSUp(1);
	for(int i = 1 ; i <= n ; i++){
//		cout << i << sep << mx[i] << sep << sum[i] << endl;
		if(col[i] == 0)	continue;
		if(dpUp[i] == n - sz[i]){
			sum[i] += dpUp[i];
		}
		else{
			mx[i] = max(mx[i] , dpUp[i]);
		}
		if(mx[i] + sum[i] + 1 >= k){
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)	cin >> A[i];
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	set<int> st;
	int l = 1 , r = MAXN;
	while(r - l > 1){
		int mid = l + r >> 1;
		if(check(mid))	l = mid;
		else	r = mid;
	}
	cout << l << endl;

	return 0;
}
/*

*/