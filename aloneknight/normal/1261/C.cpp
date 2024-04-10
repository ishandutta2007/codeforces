#include<bits/stdc++.h>
using namespace std;
const int N=3000005;
int n,m,s1[N],s2[N];char mp[N];
inline int gt(int x,int y){return !x||!y?0:(x-1)*m+y;}
inline int val(int*s,int sx,int sy,int tx,int ty){return s[gt(tx,ty)]-s[gt(sx-1,ty)]-s[gt(tx,sy-1)]+s[gt(sx-1,sy-1)];}
inline bool chk(int x)
{
	memset(s2,0,sizeof(s2));int S=(x*2+1)*(x*2+1);
	for(int i=x+1;i<=n-x;i++)for(int j=x+1;j<=m-x;j++)if(val(s1,i-x,j-x,i+x,j+x)==S)s2[gt(i,j)]=1;
	for(int i=1;i<=n*m;i++)
	{
		if(i>m)s2[i]+=s2[i-m];
		if(i%m!=1)s2[i]+=s2[i-1];
		if(i%m!=1&&i>m)s2[i]-=s2[i-m-1];
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(mp[gt(i,j)]=='X'&&!val(s2,max(i-x,1),max(j-x,1),min(n,i+x),min(m,j+x)))return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);n+=2;m+=2;
	for(int i=2;i<n;i++)scanf("%s",mp+(i-1)*m+2);
	for(int i=1;i<=n*m;i++)s1[i]=(mp[i]=='X');
	for(int i=1;i<=n*m;i++)
	{
		if(i>m)s1[i]+=s1[i-m];
		if(i%m!=1)s1[i]+=s1[i-1];
		if(i%m!=1&&i>m)s1[i]-=s1[i-m-1];
	}
	int l=0,r=1050,mid,ans;
	while(l<=r)if(chk(mid=l+r>>1))ans=mid,l=mid+1;else r=mid-1;
	printf("%d\n",ans);chk(ans);
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<m;j++)printf(val(s2,i,j,i,j)?"X":".");
		puts("");
	}
	return 0;
}