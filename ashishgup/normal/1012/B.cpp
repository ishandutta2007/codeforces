#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second

const int N=2e5+5;

int n, m, q, ans=0, emptyrow=0, emptycol=0;
pair<int, int> a[N];
int fx[N], fy[N];
int connected[2];
int root[N][2], sz[N][2];
set<int> x, y;
vector<int> g[N];

void init()
{
	for(int i=1;i<N;i++)
	{
		root[i][0]=root[i][1]=i;
		sz[i][0]=sz[i][1]=1;
	}
	connected[0]=n;
	connected[1]=m;
}

int rt(int k, int idx)
{
	while(k!=root[k][idx])
	{
		root[k][idx]=root[root[k][idx]][idx];
		k=root[k][idx];
	}
	return k;
}

void merge(int u, int v, int idx)
{
	int rt1=rt(u, idx);
	int rt2=rt(v, idx);

	if(rt1==rt2)
		return;

	connected[idx]--;

	if(sz[rt2][idx]>=sz[rt1][idx])
	{
		sz[rt2][idx]+=sz[rt1][idx];
		sz[rt1][idx]=0;
		root[rt1][idx]=root[rt2][idx];
	}
	else
	{
		sz[rt1][idx]+=sz[rt2][idx];
		sz[rt2][idx]=0;
		root[rt2][idx]=root[rt1][idx];
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>q;
	init();
	for(int i=1;i<=q;i++)
	{
		cin>>a[i].x>>a[i].y;
		fx[a[i].x]++;
		fy[a[i].y]++;
		x.insert(a[i].x);
		y.insert(a[i].y);
		g[a[i].x].push_back(a[i].y);
	}	
	for(int i=1;i<=n;i++)
		ans+=(fx[i]==0);
	ans-=1;	
	for(int i=1;i<=2e5;i++)
	{
		if(!g[i].size())
			continue;
		int prev=g[i][0];
		for(auto it:g[i])
		{
			merge(prev, it, 1);
			prev=it;
		}
	}
	ans+=connected[1];
	cout<<ans;
	return 0;
}