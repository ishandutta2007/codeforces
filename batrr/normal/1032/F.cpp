#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9, mod = 998244353 ;
const ll INF = 1e18;

vector< int > g[N];
int n, dp[N][4], nxt[4];
void add(int &x,int  y){
	x += y;
	if(x >= mod)	
		x -= mod;
}
int get1(int x, int y){
	if(x == 0 && y == 0)
		return 1;
	if(x == 0 && y == 1)
		return 2;
	if(x == 0 && y == 2)
		return 1;
	
	if(x == 1 && y == 0)
		return -1;
	if(x == 1 && y == 1)
		return 1;
	if(x == 1 && y == 2)
		return -1;
	
	if(x == 2 && y == 0)
		return 1;
	if(x == 2 && y == 1)
		return 2;
	if(x == 2 && y == 2)
		return 1;
}
	
int get2(int x, int y){
	if(y == 2)
		return -1;
	return x;
}


void dfs(int v, int p){
	dp[v][0] = 1;
	for(auto to : g[v]){
		if(to == p)
			continue;
		dfs(to, v);
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++){
				if(get1(i, j) != -1)
                	add(nxt[get1(i, j)], 1ll * dp[v][i] * dp[to][j] % mod);
				if(get2(i, j) != -1)
                	add(nxt[get2(i, j)], 1ll * dp[v][i] * dp[to][j] % mod);
			}
		for(int i = 0; i < 3; i++)
			dp[v][i] = nxt[i], nxt[i] = 0;
	}
	//cerr << v << " " << dp[v][0] << " " << dp[v][1] << " " << dp[v][2] << endl;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v , &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1, 1);
	cout << (dp[1][1] + dp[1][0]) % mod;
	return 0;
}