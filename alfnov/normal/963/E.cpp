#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int powdv(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ans;
}
int niyuan(int x)
{
	return powdv(x,mod-2);
}
int r,s[105][105][105],a[5],t[105],b[105][105],zz[105];
void upd(int x,int y,int xx,int yy,int t)
{
	if(xx*xx+yy*yy>r*r||x*x+y*y>r*r)return;
	for(int i=0;i<=2*r+1;i++)
		s[x+r][y+r][i]=(s[x+r][y+r][i]+1ll*t*s[xx+r][yy+r][i])%mod;
}
void dpu(int v,int xx,int yy,int t)
{
	if(xx*xx+yy*yy>r*r)return;
	for(int i=0;i<=2*r+1;i++)
		b[v+r][i]=(b[v+r][i]+1ll*t*s[xx+r][yy+r][i])%mod;
}
int main()
{
	cin>>r;
	for(int i=0;i<4;i++)scanf("%d",&a[i]);
	if(r==0)
	{
		printf("%d\n",1);
		return 0;
	}
	int tt=niyuan(a[0]+a[1]+a[2]+a[3]);
	for(int i=0;i<4;i++)a[i]=1ll*a[i]*tt%mod;
	for(int i=-r;i<=r;i++)
	{
		for(int j=-r;j<=r;j++)
		{
			if(i*i+j*j>r*r)continue;
			t[i+r]=j+r;
			for(int k=-r;k<=r;k++)s[i+r][j+r][k+r]=0;
			s[i+r][j+r][i+r]=1;
			break;
		}
	}
	for(int j=-r;j<=r;j++)for(int i=-r;i<=r;i++)
	{
		if(i*i+j*j>r*r||t[i+r]==j+r)continue;
		upd(i,j,i,j-1,niyuan(a[3]));
		upd(i,j,i-1,j-1,-1ll*a[0]*niyuan(a[3])%mod);
		upd(i,j,i,j-2,-1ll*a[1]*niyuan(a[3])%mod);
		upd(i,j,i+1,j-1,-1ll*a[2]*niyuan(a[3])%mod);
		s[i+r][j+r][2*r+1]=(s[i+r][j+r][2*r+1]-niyuan(a[3]))%mod;
	}
	for(int i=-r;i<=r;i++)
	{
		int j=-(t[i+r]-r);
		dpu(i,i,j,1);
		dpu(i,i-1,j,-a[0]);
		dpu(i,i,j-1,-a[1]);
		dpu(i,i+1,j,-a[2]);
		dpu(i,i,j+1,-a[3]);
		b[i+r][2*r+1]--,b[i+r][2*r+1]=-b[i+r][2*r+1];
	}
	for(int i=0;i<=2*r;i++)
	{
		for(int j=i;j<=2*r;j++)
		{
			if(b[i][i])break;
			if(!b[j][i])continue;
			for(int k=0;k<=2*r+1;k++)swap(b[i][k],b[j][k]);
		}
		for(int j=i+1;j<=2*r;j++)
		{
			if(!b[j][i])continue;
			int ss=-1ll*b[j][i]*niyuan(b[i][i])%mod;
			for(int k=0;k<=2*r+1;k++)
				b[j][k]=(b[j][k]+1ll*b[i][k]*ss)%mod;
		}
	}
	for(int i=2*r;i>=0;i--)
	{
		zz[i]=1ll*b[i][2*r+1]*niyuan(b[i][i])%mod;
		for(int j=0;j<i;j++)
			b[j][2*r+1]=(b[j][2*r+1]-1ll*b[j][i]*zz[i])%mod;
	}
	int ans=s[r][r][2*r+1];
	for(int i=0;i<=2*r;i++)ans=(ans+1ll*zz[i]*s[r][r][i])%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}