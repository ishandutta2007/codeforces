#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,ans=0,pos;
int a[500002];
int f1[500002][2],f2[500002][2],f3[500002][2];
inline void updmn(int &x,int y)
{
	if(y<x)x=y;
}
inline void updmx(int &x,int y)
{
	if(y>x)x=y;
}
inline void solve()
{
	pos=1;
	for(int i=2;i<=n;++i)if(a[i]>a[pos])pos=i;
	f1[1][0]=f1[1][1]=-inf;
	for(int i=1;i<pos;++i)
	{
		f1[i+1][0]=f1[i+1][1]=inf;
		if(a[i]<a[i+1])updmn(f1[i+1][0],f1[i][0]),updmn(f1[i+1][1],f1[i][1]);
		if(f1[i][0]<a[i+1])updmn(f1[i+1][1],a[i]);
		if(f1[i][1]<a[i+1])updmn(f1[i+1][0],a[i]);
	}
	f2[pos][0]=-inf,f2[pos][1]=f1[pos][0];
	for(int i=pos;i<n;++i)
	{
		f2[i+1][0]=-inf,f2[i+1][1]=inf;
		if(a[i]<a[i+1])updmx(f2[i+1][0],f2[i][0]);
		if(f2[i][0]>a[i+1])updmn(f2[i+1][1],a[i]);
		if(a[i]>a[i+1])updmn(f2[i+1][1],f2[i][1]);
		if(f2[i][1]<a[i+1])updmx(f2[i+1][0],a[i]);
	}
	f3[n][0]=f3[n][1]=-inf;
	for(int i=n;i>pos;--i)
	{
		f3[i-1][0]=f3[i-1][1]=inf;
		if(a[i]<a[i-1])updmn(f3[i-1][0],f3[i][0]),updmn(f3[i-1][1],f3[i][1]);
		if(f3[i][0]<a[i-1])updmn(f3[i-1][1],a[i]);
		if(f3[i][1]<a[i-1])updmn(f3[i-1][0],a[i]);
	}
	for(int i=pos+1;i<=n;++i)if(f2[i][0]>f3[i][0])++ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	solve();
	for(int i=1;i<n+1-i;++i)swap(a[i],a[n+1-i]);
	solve(),printf("%d",ans);
	return 0;
}