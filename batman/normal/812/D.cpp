#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)

ll n,m,k,q,a[N],b[N],lst[N],strt[N],fnsh[N],sz[N],now;
vector <ll> e[N];
bool dad[N];

void dfs(ll x)
{
	sz[x]=1,strt[x]=now++;
	for(auto u:e[x])
		dfs(u),sz[x]+=sz[u];
	fnsh[x]=now;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k>>q;
	for(int i=0;i<k;i++)
	{
		ll x,y;
		cin>>x>>y;
		if(lst[y])e[lst[y]].push_back(x),dad[x]=1;
		lst[y]=x;
	}
	for(int i=1;i<=n;i++)
		if(!dad[i])
			dfs(i);
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		if(!lst[y]){cout<<"0\n";continue;}
		if(strt[x]<strt[lst[y]] && strt[lst[y]]<fnsh[x])cout<<sz[x]<<"\n";
		else cout<<"0\n";
	}
	return 0;
}