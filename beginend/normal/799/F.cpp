#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define pb(x) push_back(x)
using namespace std;

typedef long long LL;
typedef unsigned long long ull;

const int N=200005;

int n,m,vis[N];
ull val[N],sum[N],tag;
vector<int> vec[N];
map<ull,LL> ma1,ma2;

ull Random()
{
	ull ret=((ull)rand()*rand()*rand()*236484161+(ull)rand()*546464131);
	return ret;	
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int l,r;val[i]=Random();scanf("%d%d",&l,&r);
		vec[l].pb(i);
		vis[l]++;vis[r+1]--;
		sum[l]^=val[i];sum[r+1]^=val[i];
	}
	for (int i=1;i<=m;i++) vis[i]+=vis[i-1],sum[i]^=sum[i-1];
	for (int i=1;i<=m;i++) sum[i]^=sum[i-1];
	LL ans=0;
	for (int i=1;i<=m;i++)
	{
		tag^=sum[i]^sum[i-1];
		for (int j=0;j<vec[i].size();j++) tag^=val[vec[i][j]];
		ma1[tag]++;ma2[tag]+=i-1;
		ans+=(LL)i*ma1[tag]-ma2[tag];
	}
	for (int i=1;i<=m;i++)
	{
		if (vis[i]) continue;
		int r=i;
		while (r<m&&!vis[r+1]) r++;
		int len=r-i+1;
		for (int j=1;j<=len;j++) ans-=(LL)j*(len-j+1);
		i=r;
	}
	printf("%I64d",ans);
	return 0;
}