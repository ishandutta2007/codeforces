#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int n,m;
#include<bitset>
typedef std::bitset<505>bps;
bps F[505][505],G[505][505];
char str[555][555];
#include<vector>
int ans[1111111],x[1111111],y[1111111],xx[1111111],yy[1111111];
std::vector<int>v[777777];
void calcf(int l,int r,int mid)
{
	register int i,ii;
	for(i=1;i<=m;i++)F[mid][i]=G[mid][i]=0;
	for(i=1;i<=m;i++)if(str[mid][i]=='.')G[mid][i][i]=1,G[mid][i]|=G[mid][i-1];
	for(i=m;i;i--)if(str[mid][i]=='.')F[mid][i][i]=1,F[mid][i]|=F[mid][i+1];
	for(i=mid+1;i<=r;i++)
		for(ii=1;ii<=m;ii++)
			if(str[i][ii]=='.')
			{
				G[i][ii]=0;
				if(str[i-1][ii]=='.')G[i][ii]|=G[i-1][ii];
				if(str[i][ii-1]=='.')G[i][ii]|=G[i][ii-1];
			}
	for(i=mid-1;i>=l;i--)
		for(ii=m;ii;ii--)
			if(str[i][ii]=='.')
			{
				F[i][ii]=0;
				if(str[i+1][ii]=='.')F[i][ii]|=F[i+1][ii];
				if(str[i][ii+1]=='.')F[i][ii]|=F[i][ii+1];
			}
}
void solve(int l=1,int r=n,int p=1)
{
	if(!v[p].size())return;
	int mid=(l+r)>>1;
	calcf(l,r,mid);
	for(auto i:v[p])
	{
		if(xx[i]<mid)v[p<<1].push_back(i);
		else if(x[i]>mid)v[p<<1|1].push_back(i);
		else ans[i]=(F[x[i]][y[i]]&G[xx[i]][yy[i]]).any();
	}solve(l,mid-1,p<<1),solve(mid+1,r,p<<1|1);
}
int main()
{
	scanf("%d%d",&n,&m);
	register int i;
	for(i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	int q;
	scanf("%d",&q);
	for(i=1;i<=q;i++)scanf("%d%d%d%d",x+i,y+i,xx+i,yy+i),v[1].push_back(i);
	solve();
	for(i=1;i<=q;i++)puts(ans[i]?"Yes":"No");
}
/*
Just go for it.
*/