#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 200005
#define maxpri 18005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int inf = 0x3f3f3f3f;
int pri[maxpri],k;
bool notp[maxn];
void getpri(int n){
	notp[1] = true;
	for(int i=2;i<=n;i++){
		if(!notp[i]) pri[++k] = i;
		for(int j=1;j<=k && pri[j] * i <= n;j++){
			notp[pri[j] * i] = true;
			if(i % pri[j] == 0) break;
		}
	}
}
int n,a[maxn];
vector <int> lis[maxpri];
vector <int> adj[maxn];
int fac,dp[maxn],ans;
bool vis[maxn];
void dfs(int u,int f){
	vis[u] = true;
	int maxi = 0,maxi2 = 0;
	for(int i=0;i<(int)adj[u].size();i++){
		int v = adj[u][i];
		if(v == f || a[v] % fac) continue;
		dfs(v,u);
		if(dp[v] + 1 > maxi){
			maxi2 = maxi;
			maxi = dp[v] + 1;
		}else{
			maxi2 = max(maxi2,dp[v] + 1);
		}
	}
	ans = max(ans,maxi + maxi2 + 1);
	dp[u] = maxi;
}
int main(){
	getpri(200000);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int tmp = a[i];
		for(int j=1;j <= k && pri[j] * pri[j] <= tmp;j++){
			if(tmp % pri[j] == 0) lis[j].push_back(i);
			while(tmp % pri[j] == 0) tmp /= pri[j];
		}
		if(tmp > 1) lis[lower_bound(pri + 1,pri + k + 1,tmp) - pri].push_back(i);
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		if(!lis[i].size()) continue;
		for(int j=0;j<(int)lis[i].size();j++) vis[lis[i][j]] = false;
		fac = pri[i];
		for(int j=0;j<(int)lis[i].size();j++){
			int u = lis[i][j];
			if(!vis[u]) dfs(u,-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}