#include<bits/stdc++.h>
using namespace std;
int n,pd[100005],val[100005],go[100005],ans[100005],cnt;
vector <int> edg[100005];
void dfs(int id,int dep,int odd,int even)
{
	pd[id]=1;
	if(dep%2&&odd%2||!(dep%2)&&even%2)val[id]=!val[id];
	if(val[id]!=go[id])ans[++cnt]=id,dep%2?odd++:even++;
	for(int i=0;i<edg[id].size();i++){
		int to=edg[id][i];
		if(!pd[to])dfs(to,dep+1,odd,even);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		edg[u].push_back(v);
		edg[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<=n;i++)
		cin>>go[i];
	dfs(1,1,0,0);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<ans[i]<<endl;
	return 0;
}