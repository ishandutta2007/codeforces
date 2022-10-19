#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
vector<int>g[200005];
int a[105],vist[200005];
int main()
{
	srand(time(0)+20090908+time(0));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
	int T=1000000;
	while(T--)
	{
		for(int i=1;i<=5;i++)
		{
			a[i]=rand()%n+1;
			while(vist[a[i]])a[i]=rand()%n+1;
			vist[a[i]]=1;
		}
		int aa=0; 
		for(int i=1;i<=5;i++)for(int j=i+1;j<=5;j++)
		{
			int wz=lower_bound(g[a[i]].begin(),g[a[i]].end(),a[j])-g[a[i]].begin();
			if(wz<g[a[i]].size()&&g[a[i]][wz]==a[j])aa++;
		}
		if(abs(aa-5)==5)
		{
			for(int i=1;i<5;i++)cout<<a[i]<<" ";
			cout<<a[5]<<endl;
			return 0;
		}
		for(int i=1;i<=5;i++)vist[a[i]]=0;
	}
	cout<<-1<<endl;
	return 0;
}