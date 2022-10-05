#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector< int > g[N];
int n, ans, deg[N], dp[N][2];
void f(int v, int p){
	dp[v][0] = g[v].size() - 1;
	dp[v][1] = 1;
	vector< pii > a, b;
	for(auto to : g[v]){
		if(to == p)
			continue;
		f(to, v);
		dp[v][0] = max(dp[v][0], dp[to][0] + deg[v] - 2);
		dp[v][0] = max(dp[v][0], dp[to][1] + deg[v] - 2);
		dp[v][1] = max(dp[v][1], dp[to][0] + 1);    
		ans = max(ans, dp[to][0] + deg[v] - 1);
		ans = max(ans, dp[to][1] + deg[v] - 1);
		ans = max(ans, dp[to][0] + 1);
		a.pb({dp[to][0], to});
		b.pb({dp[to][1], to});
	}                        
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int i = 0; i < a.size(); i++){
		for(int j = a.size() - 1; j >= 0; j--){
			if(a[i].s == a[j].s)
				continue;                                
			ans = max(ans, a[i].f + a[j].f + deg[v] - 2);
			ans = max(ans, a[i].f + a[j].f + 1);	
			break;
		}
	}
	for(int i = 0; i < a.size(); i++){
		for(int j = b.size() - 1; j >= 0; j--){
			if(a[i].s == b[j].s)
				continue;                                
			ans = max(ans, a[i].f + b[j].f + deg[v] - 2);
			break;
		}
	}
	for(int i = 0; i < b.size(); i++){
		for(int j = b.size() - 1; j >= 0; j--){
			if(b[i].s == b[j].s)
				continue;                                
			ans = max(ans, b[i].f + b[j].f + deg[v] - 2);
			break;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
		deg[v]++, deg[u]++;
	}
	f(1, -1);
	printf("%d", ans);
}