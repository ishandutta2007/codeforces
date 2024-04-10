#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,pd[51][51],v[51],ans;
int dfs(int id){
	int ans=1; v[id]=1;
	for(int i=1;i<=n;i++)if(!v[i]&&pd[id][i])ans+=dfs(i);
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		pd[u][v]=pd[v][u]=1;
	}
	for(int i=1;i<=n;i++)
		if(!v[i])ans+=dfs(i)-1;
	cout<<(1ll<<ans)<<endl;
    return 0;
}