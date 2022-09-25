#include<cstdio>
#include<cstring>
using namespace std;
#define N 65601
#define M 17
#define mod 998244353
int n,c,k,t,v[N],ct[M][M],tp[M][M*2],st[M][M*2],f2[M][M*2],fu[M][N],s1[M][N],s3[M][N],vl[M],fr[N],ifr[N],st1[N],sc[N],as[N];
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
void doit(int n,int su,int tp,int v,int s)
{
	if(s<n)return;
	int v1=tp&((1<<t)-1),f1=1;tp^=v1;
	if(tp)tp=(tp^v1)^((1<<v+t)-1),v1=tp&((1<<t)-1),v1+=(1<<t);
	int s1=1;
	for(int i=2;i<=n;i++)if(st1[i]!=st1[i-1])f1=1ll*f1*fr[s]%mod*ifr[s1]%mod*ifr[s-s1]%mod,s-=s1,s1=1;
	else s1++;
	for(int i=1;i<=n;i++)f1=1ll*f1*ifr[st1[i]]%mod;
	if(n)f1=1ll*f1*fr[s]%mod*ifr[s1]%mod*ifr[s-s1]%mod;
	st[su][v1]=(st[su][v1]+f1)%mod;
}
void dfs(int n,int ls,int su,int tp,int v,int s)
{
	doit(n-1,su,tp,v,s);
	for(int i=ls;su+i<=k;i++)st1[n]=i,dfs(n+1,i,su+i,tp^vl[i],v,s);
}
int main()
{
	scanf("%d%d%d",&n,&k,&c);
	fr[0]=ifr[0]=1;for(int i=1;i<=65555;i++)fr[i]=1ll*fr[i-1]*i%mod,ifr[i]=pw(fr[i],mod-2);
	while((1<<t)<k)t++;
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
	{
		int t1=v[i]&((1<<t)-1),t2=v[i]>>t,t3=0;
		t2=t2&-t2;
		while(t2)t2>>=1,t3++;
		ct[t3][t1]++;
	}
	for(int i=0;i<1<<c;i++)fu[0][i]=1;
	for(int i=1;i<1<<c;i++)sc[i]=sc[i-(i&-i)]+1;
	for(int i=0;i<=c-t+1;i++)
	{
		memset(tp,0,sizeof(tp));
		tp[0][0]=1;
		for(int j=0;j<(1<<t);j++)if(ct[i][j])
		{
			memset(st,0,sizeof(st));
			memset(f2,0,sizeof(f2));
			for(int l=1;l<=k;l++)vl[l]=((1<<i+t-1)|j)^(((1<<i+t-1)|j)-l);
			dfs(1,1,0,0,i,ct[i][j]);
			for(int v1=0;v1<=k;v1++)
			for(int v2=0;v2<=k;v2++)
			if(v1+v2<=k)
			for(int c1=0;c1<(1<<t+1);c1++)
			for(int c2=0;c2<(1<<t+1);c2++)
			f2[v1+v2][c1^c2]=(f2[v1+v2][c1^c2]+1ll*tp[v1][c1]*st[v2][c2])%mod;
			memcpy(tp,f2,sizeof(f2));
		}
		memset(s1,0,sizeof(s1));
		memset(s3,0,sizeof(s3));
		for(int j=0;j<=k;j++)
		for(int l=0;l<1<<(t+1);l++)
		{
			int tp1=l&((1<<t)-1),v2=l^tp1;
			if(v2)tp1^=(1<<i+t)-1;
			for(int s=0;s<1<<c;s++)
			{
				int s2=1ll*tp[j][l]*(sc[tp1&s]&1?mod-1:1)%mod;
				s1[j][s]=(s1[j][s]+s2)%mod;
			}
		}
		for(int j=0;j<=k;j++)
		for(int l=0;l<=k;l++)
		if(j+l<=k)
		for(int s=0;s<1<<c;s++)
		s3[j+l][s]=(s3[j+l][s]+1ll*s1[j][s]*fu[l][s])%mod;
		memcpy(fu,s3,sizeof(s3));
	}
	for(int i=0;i<1<<c;i++)as[i]=fu[k][i];
	for(int i=2;i<=1<<c;i<<=1)
	for(int j=0;j<1<<c;j+=i)
	for(int l=j;l<j+(i>>1);l++)
	{
		int v1=(as[l]+as[l+(i>>1)])%mod,v2=(as[l]-as[l+(i>>1)]+mod)%mod;
		v1=1ll*v1*(mod+1)/2%mod,v2=1ll*v2*(mod+1)/2%mod;
		as[l]=v1;as[l+(i>>1)]=v2;
	}
	int t1=0;for(int i=1;i<=n;i++)t1^=v[i];
	for(int i=0;i<1<<c;i++)printf("%d ",1ll*fr[k]*as[i^t1]%mod*pw(pw(n,mod-2),k)%mod);
}