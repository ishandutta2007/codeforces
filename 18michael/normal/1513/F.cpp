#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
int n,T,ans=0;LL sum=0;int t[2]={},c[2];
int a[200002][2],b[200002][2],id[2][200002];
inline bool cmp0(int x,int y)
{
	return a[x][0]<a[y][0]? 1:0;
}
inline bool cmp1(int x,int y)
{
	return a[x][1]<a[y][1]? 1:0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i][0]);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&b[i][0]),sum+=abs(a[i][0]-b[i][0]);
		if(a[i][0]<b[i][0])++t[0],a[t[0]][0]=a[i][0],b[t[0]][0]=b[i][0],id[0][t[0]]=t[0];
		else ++t[1],a[t[1]][1]=b[i][0],b[t[1]][1]=a[i][0],id[1][t[1]]=t[1];
	}
	sort(id[0]+1,id[0]+t[0]+1,cmp0),sort(id[1]+1,id[1]+t[1]+1,cmp1),c[0]=c[1]=1,T=0;
	while(c[0]<=t[0] && c[1]<=t[1])
	{
		while(c[0]<=t[0] && a[id[0][c[0]]][0]<=a[id[1][c[1]]][1])T=max(T,b[id[0][c[0]]][0]),++c[0];
		ans=max(ans,min(T,b[id[1][c[1]]][1])-a[id[1][c[1]]][1]),++c[1];
	}
	while(c[1]<=t[1])ans=max(ans,min(T,b[id[1][c[1]]][1])-a[id[1][c[1]]][1]),++c[1];
	c[0]=c[1]=1,T=0;
	while(c[0]<=t[0] && c[1]<=t[1])
	{
		while(c[1]<=t[1] && a[id[1][c[1]]][1]<=a[id[0][c[0]]][0])T=max(T,b[id[1][c[1]]][1]),++c[1];
		ans=max(ans,min(T,b[id[0][c[0]]][0])-a[id[0][c[0]]][0]),++c[0];
	}
	while(c[0]<=t[0])ans=max(ans,min(T,b[id[0][c[0]]][0])-a[id[0][c[0]]][0]),++c[0];
	return 0&printf("%lld\n",sum-2LL*ans);
}