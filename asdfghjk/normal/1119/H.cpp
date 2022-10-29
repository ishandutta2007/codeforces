#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=300005,md=998244353;
int n,K,x,y,z,A,i,a[N],b[N],c[N],d[N],f1[N],f2[N],f3[N],g[N],x1,x2,x3,x4,inv[10];
int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
void fwtxor(int a[N],int t)
{
	for(int l=2;l<=(1<<K);l<<=1)
	{
		int m=l>>1;
		for(int i=0;i<(1<<K);i+=l)
			for(int j=0;j<m;++j)
			{
				int x=a[i+j],y=a[i+j+m];
				a[i+j]=(x+y)%md,a[i+j+m]=(x-y+md)%md;
				if(t==-1)
					a[i+j]=1ll*a[i+j]*inv[2]%md,a[i+j+m]=1ll*a[i+j+m]*inv[2]%md;
			}
	}
}
int main()
{
	inv[1]=1;
	for(i=2;i<=5;++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	scanf("%d%d",&n,&K);
	scanf("%d%d%d",&x,&y,&z);
	x%=md,y%=md,z%=md;
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d",a+i,b+i,c+i);
		b[i]^=a[i],c[i]^=a[i];
		A^=a[i];
	}
	for(i=1;i<=n;++i)
		f1[b[i]]++,f2[c[i]]++,f3[b[i]^c[i]]++;
	fwtxor(f1,1),fwtxor(f2,1),fwtxor(f3,1);
	for(i=0;i<(1<<K);++i)
	{
		x1=(1ll*n+f1[i]+f2[i]+f3[i])%md*inv[4]%md;
		x2=(1ll*n+f1[i]-f2[i]-f3[i]+2*md)%md*inv[4]%md;
		x3=(1ll*n-f1[i]+f2[i]-f3[i]+2*md)%md*inv[4]%md;
		x4=(1ll*n-f1[i]-f2[i]+f3[i]+2*md)%md*inv[4]%md;
		g[i]=1ll*pw((1ll*x+y+z)%md,x1)*pw((1ll*x+y-z+md)%md,x2)%md*pw((1ll*x-y+z+md)%md,x3)%md*pw((1ll*x-y-z+2*md)%md,x4)%md;
	}
	fwtxor(g,-1);
	for(i=0;i<(1<<K);++i)
		printf("%d ",g[i^A]);
	return 0;
}