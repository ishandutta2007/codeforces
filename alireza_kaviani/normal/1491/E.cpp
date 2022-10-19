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
const ll LOG = 30;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , sz[MAXN] , fib[LOG] , par[MAXN] , valid[MAXN] , isFib[MAXN];
vector<int> vec , adj[MAXN];

void DFS(int v , int p = -1){
	sz[v] = 1;
	par[v] = p;
	for(int u : adj[v]){
		if(valid[u] == 0 || u == p)	continue;
		DFS(u , v);
		sz[v] += sz[u];
	}
	vec.push_back(v);
}

int solve(int v){
	vec = {} , DFS(v);
//	cout << v << endl;
//	for(int i : vec)	cout << i << sep;
//	cout << endl;
	if(isFib[sz[v]] == 0)	return 0;
	if(sz[v] == 1)	return 1;
	int x = 0;
	for(int i : vec){
		if(i == v)	continue;
		if(isFib[sz[i]] && sz[i] > sz[x])	x = i;
	}
	if(x == 0)	return 0;
	v = x; int u = par[x];
//	cout << v << sep << u << endl;
	vec = {} , DFS(u , v);
	for(int i : vec)	valid[i] = 0;
	vector<int> vvec = vec;
	int ans = solve(v);
	for(int i : vvec)	valid[i] = 1;
	vec = {} , DFS(v , u);
	for(int i : vec)	valid[i] = 0;
	ans &= solve(u);
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	fib[0] = fib[1] = 1;
	for(int i = 2 ; i < LOG ; i++)	fib[i] = fib[i - 1] + fib[i - 2];
	for(int i = 0 ; i < LOG ; i++)	isFib[fib[i]] = i;
	cin >> n;
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	fill(valid , valid + n + 5 , 1);
	if(solve(1))	cout << "YES" << endl;
	else	cout << "NO" << endl;

    return 0;
}
/*

*/