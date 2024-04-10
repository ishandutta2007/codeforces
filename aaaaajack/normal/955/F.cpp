#include<bits/stdc++.h>
#define N 300100
using namespace std;
const int LG=20;
int dp[N][LG],mx[N][LG],dep[N];
int buf[N];
vector<int> g[N];
long long solve(int u, int p){
	long long ans=0;
	dep[u]=1;
	for(auto v:g[u]){
		if(v==p) continue;
		ans+=solve(v,u);
		dep[u]=max(dep[u],dep[v]+1);
		for(int j=0;j<LG;j++){
			mx[u][j]=max(mx[u][j],mx[v][j]);
		}
	}
	for(int j=0;j<LG;j++){
		if(j){
			int m=0;
			for(auto v:g[u]){
				if(v!=p){
					buf[m++]=dp[v][j-1];
				}
			}
			sort(buf,buf+m,greater<int>());
			while(m && buf[m-1]<m) m--;
			dp[u][j]=m;
		}
		mx[u][j]=max(mx[u][j],dp[u][j]);
		ans+=mx[u][j];
	}
	if(dep[u]>LG) ans+=dep[u]-LG;
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) dp[i][0]=n;
	printf("%lld\n",solve(1,0));
	return 0;
}