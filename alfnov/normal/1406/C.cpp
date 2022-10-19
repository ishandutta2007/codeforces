#include<bits/stdc++.h>
using namespace std;
int w[100005],fa[100005],qq[100005],tot=0,bg[100005],en[100005];
vector<int>g[100005];
void dfs(int x,int la)
{
	bg[x]=++tot;
	w[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		fa[cu]=x;
		dfs(cu,x);
		w[x]+=w[cu];
	}
	en[x]=tot;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			w[i]=fa[i]=qq[i]=bg[i]=en[i]=0;
		}
		tot=0;
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);
		int gs=0,w1=0,w2=0,aa=n+1;
		for(int i=1;i<=n;i++)
		{
			qq[i]=n-w[i];
			for(int j=0;j<g[i].size();j++)
			{
				int cu=g[i][j];
				if(cu!=fa[i])qq[i]=max(qq[i],w[cu]);
			}
			aa=min(aa,qq[i]);
		}
		for(int i=1;i<=n;i++)if(qq[i]==aa)
		{
			gs++;
			if(!w1)w1=i;
			else if(!w2)w2=i;
		}
		if(gs==1)
		{
			cout<<2<<" "<<fa[2]<<endl;
			cout<<2<<" "<<fa[2]<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			w[i]=fa[i]=qq[i]=bg[i]=en[i]=0;
		}
		tot=0;
		dfs(w1,0);
		for(int i=1;i<=n;i++)if(w[i]==1)
		{
			if(bg[i]<bg[w2]||bg[i]>en[w2])continue;
			cout<<i<<" "<<fa[i]<<endl;
			cout<<w1<<" "<<i<<endl;
			break;
		}
	}
	return 0;
}