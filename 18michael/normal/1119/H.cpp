#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,t=0,Mx;
LL X,Y,Z;
int a[3][131072],pw[4][100002];
int main()
{
	scanf("%d%d%lld%lld%lld",&n,&Mx,&X,&Y,&Z),Mx=(1<<Mx),pw[0][0]=pw[1][0]=pw[2][0]=pw[3][0]=1;
	for(int i=1,x,y,z;i<=n;++i)scanf("%d%d%d",&x,&y,&z),t^=z,++a[0][x^z],++a[1][y^z],++a[2][x^y],pw[0][i]=((LL)pw[0][i-1]*(Z+X+Y))%mod,pw[1][i]=((LL)pw[1][i-1]*(Z+X-Y))%mod,pw[2][i]=((LL)pw[2][i-1]*(Z-X+Y))%mod,pw[3][i]=((LL)pw[3][i-1]*(Z-X-Y))%mod;
	for(int i=1,x;i<Mx;i<<=1)for(int j=0;j<Mx;j+=(i<<1))for(int k=0;k<i;++k)for(int o=0;o<3;++o)x=a[o][j+k],a[o][j+k]+=a[o][j+k+i],a[o][j+k+i]=x-a[o][j+k+i];
	for(int i=0;i<Mx;++i)a[0][i]=((((((LL)pw[0][(n+a[0][i]+a[1][i]+a[2][i])/4]*pw[1][(n+a[0][i]-a[1][i]-a[2][i])/4])%mod)*pw[2][(n-a[0][i]+a[1][i]-a[2][i])/4])%mod)*pw[3][(n-a[0][i]-a[1][i]+a[2][i])/4])%mod;
	for(int i=1,x;i<Mx;i<<=1)for(int j=0;j<Mx;j+=(i<<1))for(int k=0;k<i;++k)x=a[0][j+k],a[0][j+k]=(499122177LL*(x+a[0][j+k+i]))%mod,a[0][j+k+i]=(499122177LL*(x-a[0][j+k+i]))%mod;
	for(int i=0;i<Mx;++i)printf("%d ",(a[0][i^t]+mod)%mod);
	return 0;
}