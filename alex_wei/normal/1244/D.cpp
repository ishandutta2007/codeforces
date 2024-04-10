#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005][4];
vector<int> g[100005],v;
int root;
void dfs(int x,int fa)
{
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y!=fa)dfs(y,x);
	}
	v.push_back(x);
}
int as[100005];
signed main()
{
	cin>>n;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			cin>>a[j][i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(g[i].size()>2)
			cout<<-1,exit(0);
	for(int i=1;i<=n;i++)
		if(g[i].size()==1)
			root=i;
	dfs(root,0);
	int ans=1ll<<48,id1=0,di2=0;
	for(int i=1;i<4;i++)
		for(int j=1;j<4;j++)
			if(i!=j){
				int sum=0;
				for(int k=0;k<v.size();k++){
					int x=v[k];
					int t;
					if(k%3==0)t=i;
					else if(k%3==1)t=j;
					else t=6-i-j;
					sum+=a[x][t];
				}
				if(sum<ans)ans=sum,id1=i,di2=j;
			}
	cout<<ans<<endl;
	for(int k=0;k<v.size();k++){
		int t;
		if(k%3==0)t=id1;
		else if(k%3==1)t=di2;
		else t=6-id1-di2;
		as[v[k]]=t;
	}
	for(int i=1;i<=n;i++)
		cout<<as[i]<<" ";
	return 0;
}