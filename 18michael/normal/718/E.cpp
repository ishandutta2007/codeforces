#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int la[8],mn[256],lg[256];
int d[100002][8],g[8][8],cnt[8][256];
char s[100002];
typedef pair<int,LL> P;
P ans=P(0,0);
inline int lowbit(int x)
{
	return x&(-x);
}
inline P merge(P a,P b)
{
	if(!b.second)return a;
	if(a.first<b.first)swap(a,b);
	if(a.first==b.first)a.second+=b.second;
	return a;
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i)s[i]-='a';
	for(int i=0;i<8;++i)
	{
		la[i]=-inf,lg[1<<i]=i;
		for(int j=1;j<=n;++j)d[j][i]=inf;
		for(int j=0;j<8;++j)g[j][i]=inf;
	}
	for(int i=1;i<=n;++i)
	{
		la[s[i]]=i;
		for(int j=0;j<8;++j)d[i][j]=min(d[i][j],i-la[j]),g[s[i]][j]=min(g[s[i]][j],i-la[j]);
	}
	for(int i=0;i<8;++i)la[i]=inf;
	for(int i=n;i;--i)
	{
		la[s[i]]=i;
		for(int j=0;j<8;++j)d[i][j]=min(d[i][j],la[j]-i),g[s[i]][j]=min(g[s[i]][j],la[j]-i);
	}
	for(int i=0;i<8;++i)for(int j=0;j<8;++j)for(int k=0;k<8;++k)g[j][k]=min(g[j][k],g[j][i]+g[i][k]+1);
	for(int i=1;i<=n;++i)for(int j=0;j<8;++j)for(int k=0;k<8;++k)d[i][j]=min(d[i][j],d[i][k]+g[k][j]+1);
	for(int i=1,x;i<=n;++i)
	{
		for(int j=max(i-15,1);j<i;++j)
		{
			x=i-j;
			for(int k=0;k<8;++k)x=min(x,d[i][k]+d[j][k]+1);
			ans=merge(ans,P(x,1));
		}
		if(i>16)
		{
			x=0;
			for(int j=0;j<8;++j)x|=((d[i-16][j]-g[s[i-16]][j])<<j);
			++cnt[s[i-16]][x];
		}
		for(int j=0;j<8;++j)
		{
			mn[255]=inf;
			for(int k=0;k<8;++k)mn[255]=min(mn[255],d[i][k]+g[j][k]+2);
			for(int k=255,x;~k;--k)
			{
				if(k<255)x=lowbit(255^k),mn[k]=min(mn[k|x],d[i][lg[x]]+g[j][lg[x]]+1);
				ans=merge(ans,P(mn[k],cnt[j][k]));
			}
		}
	}
	return 0&printf("%d %lld",ans.first,ans.second);
}