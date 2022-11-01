#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)

ll n,dis;
bool a[N],b[N],p[2],mark[N];
vector <ll> e[N],ans;

void dfs(ll x)
{
	bool xx=0;
	mark[x]=1;
	dis++;
	a[x]=(a[x]+p[(dis&1)])%2;
	if(a[x]!=b[x])
		p[(dis&1)]=!p[(dis&1)],ans.push_back(x),xx=1;
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			dfs(e[x][i]);
	if(xx)		
		p[(dis&1)]=!p[(dis&1)];
	dis--;			
	
}

int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);	
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];	
	dfs(1);	
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<"\n";
    return 0;
}