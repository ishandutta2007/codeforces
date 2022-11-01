#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)

ll t,n,m,ans[N];
vector <ll> e[N],vec,now,all;
bool cycle,mark[N];

void dfs(ll x,ll y=0,ll par=0)
{
	mark[x]=1;
	all.push_back(x);
	now.push_back(x);
	if(x==y)vec=now;
	for(auto u:e[x])
		if(u!=par)
		{
			if(mark[u]){cycle=1;continue;}
			dfs(u,y,x);
		}
	now.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)e[i].clear(),mark[i]=0,ans[i]=0;
		for(int i=0;i<m;i++)
		{
			ll v,u;
			cin>>v>>u;
			e[v].push_back(u);
			e[u].push_back(v);
		}
		bool flg=0;
		for(int i=1;i<=n;i++)
			if(!mark[i])
			{
				all.clear();
				cycle=0;
				dfs(i);
				if(cycle)
				{
					for(auto u:all)ans[u]=1;
					flg=1;
					break;
				}
				for(auto u:all)
					if(e[u].size()>=4)
					{
						for(auto w:all)ans[w]=1;
						ans[u]=2;
						flg=1;
						break;
					}
				if(flg)break;
				ll ex1=-1,ex2=-1;
				for(auto u:all)
					if(e[u].size()==3)
						ex2=ex1,ex1=u;
				if(ex2!=-1)
				{
					vec.clear();
					for(auto u:all)mark[u]=0;
					dfs(ex1,ex2);
					for(auto u:all)ans[u]=1;
					for(auto u:vec)ans[u]=2;
					flg=1;
					break;
				}
				if(ex1==-1)continue;
				ll a=e[ex1][0],b=e[ex1][1],c=e[ex1][2];
				if(e[a].size()>e[b].size())swap(a,b);
				if(e[a].size()>e[c].size())swap(a,c);
				if(e[b].size()>e[c].size())swap(b,c);
				if(e[a].size()==2)
				{
					for(auto u:all)ans[u]=1;
					ans[ex1]=3;
					ans[a]=ans[b]=ans[c]=2;
					flg=1;
					break;
				}
				if(e[a].size()==1 && e[b].size()==1)continue;
				ll adj1=e[b][0],adj2=e[c][0];
				if(adj1==ex1)adj1=e[b][1];
				if(adj2==ex1)adj2=e[c][1];
				if(e[adj1].size()==1 && e[adj2].size()==1)continue;
				if(e[adj1].size()>e[adj2].size())swap(adj1,adj2),swap(b,c);
				if(e[adj1].size()==1)
				{
					ll adj3=e[adj2][0];
					if(adj3==c)adj3=e[adj2][1];
					if(e[adj3].size()==1)continue;
					ll adj4=e[adj3][0];
					if(adj4==adj2)adj4=e[adj3][1];
					if(e[adj4].size()==1)continue;
					for(auto u:all)ans[u]=1;
					ans[ex1]=6;
					ans[c]=5;
					ans[b]=ans[adj2]=4;
					ans[a]=ans[adj3]=3;
					ans[adj1]=ans[adj4]=2;
					flg=1;
					break;
				}
				for(auto u:all)ans[u]=1;
				ans[ex1]=4;
				ans[b]=ans[c]=3;
				ans[a]=ans[adj1]=ans[adj2]=2;
				flg=1;
				break;
			}
		if(!flg)cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<"\n";
		}
	}
	return 0;
}