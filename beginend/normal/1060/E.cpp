#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

typedef long long LL;

const int N=200005;

int n,dep[N],size[N],s0,s1;
std::vector<int> vec[N];
LL sum,ans;

void dfs1(int x,int fa)
{
	size[x]=1;dep[x]=dep[fa]+1;
	if (dep[x]&1) s1++;
	else s0++;
	for (int i=0;i<vec[x].size();i++)
		if (vec[x][i]!=fa) dfs1(vec[x][i],x),size[x]+=size[vec[x][i]];
}

void dfs2(int x,int fa,LL now)
{
	if (dep[x]&1) sum+=(LL)s0;
	else sum+=(LL)s1;
	ans+=now;
	for (int i=0;i<vec[x].size();i++)
		if (vec[x][i]!=fa) dfs2(vec[x][i],x,now+(n-size[vec[x][i]])-size[vec[x][i]]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		vec[x].pb(y);vec[y].pb(x);
	}
	dfs1(1,0);
	LL tot=0;
	for (int i=1;i<=n;i++) tot+=(LL)(dep[i]-1);
	dfs2(1,0,tot);
	printf("%lld\n",((ans-sum)/2+sum)/2);
	return 0;
}