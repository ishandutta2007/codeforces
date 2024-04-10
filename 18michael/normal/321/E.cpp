#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,k,res;
char ch;
int a[4002][4002],f[802][4002];
inline int calc(int x,int y)
{
	return a[y][y]-a[x-1][y]*2+a[x-1][x-1];
}
inline void solve(int x,int l,int r,int L,int R)
{
	if(l>r)return ;
	int mid=((l+r)>>1),p=L,val=f[x-1][L]+calc(L+1,mid);
	for(int i=L+1;i<=R && i<mid;++i)if((res=f[x-1][i]+calc(i+1,mid))<val)val=res,p=i;
	f[x][mid]=val,solve(x,l,mid-1,L,p),solve(x,mid+1,r,p,R);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			do ch=getchar();while(ch<'0' || ch>'9');
			a[i][j]=(ch^48)+a[i][j-1];
		}
		for(int j=1;j<=n;++j)a[i][j]+=a[i-1][j];
	}
	for(int i=1;i<=n;++i)f[0][i]=inf;
	for(int i=1;i<=k;++i)f[i][0]=inf,solve(i,1,n,0,n);
	return 0&printf("%d",f[k][n]/2);
}