#include<bits/stdc++.h>
typedef long long ll;
const int MAXN=200005;
ll ans;
int n;
std::vector<std::pair<int,int>>e[MAXN];
int dp[2][MAXN];
void dfs1(int u,int fa){
	for(auto i:e[u]){
		int v=i.first,c=i.second;
		if(v==fa){
			continue;
		}
		dfs1(v,u);
		if(c==0){
			dp[0][u]+=dp[0][v]+dp[1][v]+1;
		}else{
			dp[1][u]+=dp[1][v]+1;
		}
	}
}
void dfs2(int u,int fa){
	for(auto i:e[u]){
		int v=i.first,c=i.second;
		if(v==fa){
			continue;
		}
		if(c==0){
			dp[0][v]=dp[0][u]+dp[1][u]-dp[1][v];
		}else{
			dp[1][v]=dp[1][u];
		}
		dfs2(v,u);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		e[u].push_back({v,c});
		e[v].push_back({u,c});
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i){
		ans+=dp[0][i]+dp[1][i];
	}
	printf("%I64d\n",ans);
	return 0;
}