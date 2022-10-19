#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
struct apple
{
	int x,y;
	bool operator<(const apple &other)const
	{
		if(x==other.x)return y<other.y;
		return x<other.x;
	}
}e[2005];
int f[2][2005],d[200005],ny[200005];
int niyuan(int x)
{
	int y=mod-2,ans=1;
	while(y)
	{
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ans;
}
int C(int n,int m)
{
	return 1ll*d[n]*ny[m]%mod*ny[n-m]%mod;
}
int main()
{
	int h,w,n;
	cin>>h>>w>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",&e[i].x,&e[i].y);
	d[0]=1;
	for(int i=1;i<=h+w;i++)d[i]=1ll*d[i-1]*i%mod;
	ny[h+w]=niyuan(d[h+w]);
	for(int i=h+w-1;i>=0;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	sort(e+1,e+n+1);
	e[0].x=1,e[0].y=1;
	e[n+1].x=h,e[n+1].y=w;
	f[0][0]=1;
	for(int i=1;i<=n+1;i++)for(int j=0;j<i;j++)
	{
		if(e[j].y>e[i].y)continue;
		int l=C(e[i].x-e[j].x+e[i].y-e[j].y,e[i].x-e[j].x);
		f[0][i]=(f[0][i]+1ll*f[1][j]*l)%mod;
		f[1][i]=(f[1][i]+1ll*f[0][j]*l)%mod;
	}
	int ans=(f[1][n+1]-f[0][n+1]+mod)%mod;
	cout<<ans<<endl;
	return 0;
}