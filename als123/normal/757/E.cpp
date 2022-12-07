#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL N=1000005;
int pri[N+5];
int tot=0;
bool vis[N+5];
int mn[N+5];
void get_p ()
{
	memset(vis,false,sizeof(vis));
	for (LL u=2;u<N;u++)
	{
		//printf("%I64d\n",u);
		if (vis[u]==false)	{pri[++tot]=u;mn[u]=u;}
		for (LL i=1;i<=tot;i++)
		{
			if (u*pri[i]>N) break;
			vis[u*pri[i]]=true;
			mn[u*pri[i]]=pri[i];
			if (u%pri[i]==0) break;
		}
	}
//	for (LL u=2;u<=10;u++) printf("%I64d ",mn[u]);
}
int f[N][22],s[N][22];
int main()
{
	get_p();
//	printf("YES\n");
	for (LL u=1;u<22;u++) f[0][u]=2,s[0][u]=2*u+1;
	f[0][0]=s[0][0]=1;
	for (LL u=1;u<N;u++)
	{
		for (LL i=0;i<22;i++) f[u][i]=s[u-1][i];
		s[u][0]=f[u][0];
		for (LL i=1;i<22;i++) s[u][i]=(s[u][i-1]+f[u][i])%MOD;
	}
	LL m;
	scanf("%I64d",&m);
	while (m--)
	{
		LL n,r;
		scanf("%I64d%I64d",&r,&n);
		LL ans=1;
		while (n>1)
		{
			LL t=mn[n],o=0;
			while (n%t==0)	{n/=t;o++;}
			//printf("%I64d %I64d\n",n,t);
			ans=(ans*f[r][o])%MOD;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}