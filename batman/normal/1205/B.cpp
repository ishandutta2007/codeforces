#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define N ((int)101*1000)
#define K ((int)61)

int n;
ll a[N];
int id[K][2];
vector <int> e[N];
int dis[N],par[N];
int ans=N;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<K;j++)
			if((a[i]&(1LL<<j)))
			{
				if(!id[j][0])id[j][0]=i;
				else if(!id[j][1])id[j][1]=i;
				else return cout<<3,0;
			}
	}
	for(int i=0;i<K;i++)
		if(id[i][1])
		{
			e[id[i][0]].push_back(id[i][1]);
			e[id[i][1]].push_back(id[i][0]);
		}
	for(int i=1;i<=n;i++)
	{
		if(!e[i].size())continue;
		queue <int> q,ex;
		q.push(i);dis[i]=1;ex.push(i);
		while(q.size())
		{
			int x=q.front();q.pop();
			for(auto u:e[x])
			{
				if(!dis[u])
					q.push(u),dis[u]=dis[x]+1,par[u]=x,ex.push(u);
				else if(par[x]!=u && par[u]!=x)
				{
					ans=min(ans,dis[x]+dis[u]-1);
				}
			}
		}
		while(ex.size())
			dis[ex.front()]=0,par[ex.front()]=0,ex.pop();
	}
	cout<<((ans==N)?-1:ans);
	return 0;
}