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

int n , dp[MAXN][LOG];
vector<int> adj[MAXN];

void DFS(int v){
	for(int u : adj[v]){
		DFS(u);
	}
	dp[v][0] = v;
	for(int i = 1 ; i < LOG ; i++){
		pii res = {MOD , MOD};
		for(int u : adj[v]){
			res.Y = min(res.Y , dp[u][i - 1]);
			if(res.X > res.Y){
				swap(res.X , res.Y);
			}
		}
		dp[v][i] = res.Y;
		for(int u : adj[v]){
			dp[v][i] = min(dp[v][i] , dp[u][i]);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 2 ; i <= n + 1 ; i++){
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	DFS(1);
	int cur = 2;
	for(int i = 0 ; i < LOG ; i++){
		int mn = n + 2;
		for(int u : adj[1]){
			mn = min(mn , dp[u][i]);
		}
		for( ; cur < mn ; cur++){
			cout << i << sep;
		}
	}

    return 0;
}
/*

*/