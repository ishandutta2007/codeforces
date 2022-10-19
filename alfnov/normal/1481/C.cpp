#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],w1[100005],w2[100005],dd[100005];
vector<int>g[100005];//clear
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),g[a[i]].clear();
		for(int i=1;i<=n;i++)scanf("%d",&b[i]),g[b[i]].clear();
		for(int i=1;i<=m;i++)scanf("%d",&c[i]),g[c[i]].clear();
		for(int i=1;i<=n;i++)if(a[i]!=b[i])g[b[i]].push_back(i);
		int tot=0;
		for(int i=m;i>=1;i--)
		{
			if(g[c[i]].size())
			{
				w1[++tot]=i,w2[tot]=g[c[i]].back();
				g[c[i]].pop_back();
			}
		}
		int flag=1;
		for(int i=1;i<=n;i++)if(a[i]!=b[i]&&g[b[i]].size())
		{
			puts("NO");
			flag=0;
			break;
		}
		if(!flag)continue;
		if(tot&&w1[1]==m)
		{
			puts("YES");
			for(int i=1;i<=m;i++)dd[i]=w2[1];
			for(int i=1;i<=tot;i++)dd[w1[i]]=w2[i];
			for(int i=1;i<=m;i++)printf("%d ",dd[i]);
			puts("");
		}else
		{
			flag=0;
			for(int i=1;i<=n;i++)if(b[i]==c[m])
			{
				flag=1;
				puts("YES");
				for(int j=1;j<=m;j++)dd[j]=i;
				for(int j=1;j<=tot;j++)dd[w1[j]]=w2[j];
				for(int i=1;i<=m;i++)printf("%d ",dd[i]);
				puts("");
				break;
			}
			if(!flag)puts("NO");
		}
	}
	return 0;
}