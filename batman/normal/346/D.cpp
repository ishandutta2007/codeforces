#include<bits/stdc++.h>
using namespace std;
#define INF ((int)1e8)
#define N (1001*1000)
#define ll int

ll n,m,num[N],a1,a2;
vector <ll> e[N];
set <ll> s;
queue <ll> q;
bool mark[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		ll v,u;
		scanf("%d%d",&v,&u);
		e[u].push_back(v);
		num[v]++;
	}
	scanf("%d%d",&a1,&a2);
	s.insert(a2);
	for(int ans=0;ans<n;ans++)
	{
		while(s.size())
			q.push(*s.begin()),s.erase(s.begin());
		while(q.size())
		{
			ll x=q.front();q.pop();
			mark[x]=1;
			if(x==a1){printf("%d",ans);return 0;}
			for(int i=0;i<e[x].size();i++)
			{
				ll v=e[x][i];
				if(mark[v])continue;
				s.insert(v);
				if(--num[v]==0)s.erase(v),q.push(v);
			}
		}
	}
	printf("-1");
	return 0;
}