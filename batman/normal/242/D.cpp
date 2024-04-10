#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define MOD ((ll)1e9+7)

ll n,m,a[N],d[N];
vector <ll> e[N],ans;

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	queue <ll> q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
			q.push(i);	
	}
	while(q.size())
	{
		ll x=q.front();
		q.pop();
		if(a[x]!=d[x])continue;
		ans.push_back(x);
		d[x]++;
		for(int i=0;i<e[x].size();i++)
		{
			d[e[x][i]]++;
			if(d[e[x][i]]==a[e[x][i]])
				q.push(e[x][i]);
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]==d[i])
			return cout<<-1,0;
			
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	
    return 0;
}