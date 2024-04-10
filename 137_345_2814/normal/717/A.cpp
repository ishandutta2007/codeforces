#include<cstdio>
using namespace std;
#define N 1505
#define mod 1000000007
#define ll long long
int T,m,k,c[N][N],f[N];
ll l,r;
void pre()
{
	for(int i=0;i<=k;i++)c[i][0]=c[i][i]=1,f[i]=0;f[0]=1;
	for(int i=2;i<=k;i++)for(int j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	for(int i=0;i<k;i++)
	for(int j=i;j>=0;j--)f[j+1]=(f[j+1]+f[j])%mod,f[j]=1ll*f[j]*(mod-i)%mod;
}
int pw(int a,int b){int as=1;while(b){if(b&1)as=1ll*as*a%mod;a=1ll*a*a%mod;b>>=1;}return as;}
struct task1{
	struct fuc{
		int a,b;
		friend fuc operator +(fuc a,fuc b){return (fuc){(a.a+b.a)%mod,(a.b+b.b)%mod};}
		friend fuc operator *(fuc a,fuc b){return (fuc){(1ll*a.a*b.a+1ll*b.b*a.b*5)%mod,(1ll*a.a*b.b+1ll*a.b*b.a)%mod};}
	};
	fuc pw(fuc a,ll b){fuc as=(fuc){1,0};while(b){if(b&1)as=as*a;a=a*a;b>>=1;}return as;}
	int pw(int a,int b){int as=1;while(b){if(b&1)as=1ll*as*a%mod;a=1ll*a*a%mod;b>>=1;}return as;}
	fuc las;
	fuc solve2(fuc a,ll b)
	{
		if(b==1){las=a;return a;}
		fuc v1=solve2(a,b>>1);
		v1=v1+v1*las;las=las*las;
		if(b&1)las=las*a,v1=v1+las;
		return v1;
	}
	int solve(ll r)
	{
		fuc v1=(fuc){500000004,500000004},v2=(fuc){500000004,500000003},as=(fuc){0,0};
		as=pw(v1,4)+pw(v2,4)*(fuc){mod-1,0};
		for(int i=0;i<=k;i++)
		for(int j=0;j<=k;j++)
		if(i+j<=k)
		{
			fuc st=pw(v1,i)*pw(v2,j);
			int vl=1ll*c[i+j][j]*f[i+j]%mod*(j&1?mod-1:1)%mod;
			fuc st2=solve2(st,r);
			st2=st2*(fuc){vl,0};
			if((i+j)&1)st2=(fuc){st2.b,1ll*st2.a*pw(5,mod-2)%mod};
			st2=st2*(fuc){pw(pw(5,mod-2),(i+j)/2),0};
			as=as+st2;
		}
		for(int i=1;i<=k;i++)as.a=1ll*as.a*pw(i,mod-2)%mod;
		return as.a;
	}
}t1;
int main()
{
	scanf("%d%lld%lld",&k,&l,&r),pre(),printf("%d\n",(t1.solve(r+2)-t1.solve(l+1)+mod)%mod);
}