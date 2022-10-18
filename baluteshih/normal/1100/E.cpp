#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct mode
{
	int a,b,w;
}edge[100005];
vector<int> G[100005],ans;
int in[100005],topo[100005],n,m;
queue<int> q;

int check(int mid)
{
	for(int i=1;i<=n;++i)
		G[i].clear(),in[i]=0;
	for(int i=1;i<=m;++i)
		if(edge[i].w>mid)
			G[edge[i].a].pb(edge[i].b),++in[edge[i].b];
	int t=0;
	for(int i=1;i<=n;++i)
		if(!in[i]) q.push(i),topo[i]=++t;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i:G[x])
			if(!--in[i]) topo[i]=++t,q.push(i);
	}
	return t;
}

int main()
{jizz
	int l,r;
	cin >> n >> m,l=0,r=0;
	for(int i=1;i<=m;++i)
		cin >> edge[i].a >> edge[i].b >> edge[i].w,r=max(r,edge[i].w);
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)==n) r=mid;
		else l=mid+1;
	}
	check(l);
	for(int i=1;i<=m;++i)
		if(topo[edge[i].a]>topo[edge[i].b])
			ans.pb(i);
	cout << l << " " << ans.size() << "\n";
	for(int i:ans)
		cout << i << " ";
	ET;
}