#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)

ll n,m,k,d[N];
vector <ll> e[N];
bool mark[N];
deque <ll> q;

void print(ll x,ll y)
{
	vector <ll> ans;
	while(q.size() && q.front()!=x)
		q.pop_front();	
	while(q.front()!=y)
	{
		ans.push_back(q.front());
		q.pop_front();
	}
	cout<<ans.size()+1<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	cout<<y;
	exit(0);
}

void dfs(ll x)
{
	q.push_back(x);
	mark[x]=1;
	for(int i=0;i<e[x].size();i++)
	{
		if(mark[e[x][i]] && d[x]-d[e[x][i]]>=k)
			print(e[x][i],x);
		if(!mark[e[x][i]])
			d[e[x][i]]=d[x]+1,dfs(e[x][i]);
	}
	mark[x]=0;
	q.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dfs(1);
	return 0;
}