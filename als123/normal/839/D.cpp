#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL N=200005;
const LL M=1000005;
LL n;
LL s[N];
LL cnt[M];//
bool in[M];
LL f[M];
LL get (LL x,LL y)
{
	if (y==1) return x;
	if (y==0) return 1;
	LL lalal=get(x,y/2);
	lalal=lalal*lalal%MOD;
	if (y&1) lalal=lalal*x%MOD;
	return lalal;
}
LL dfs (LL x)
{
	if (in[x]==true) return f[x];
	in[x]=true;
	if (cnt[x]==0) {f[x]=0;return 0;}
	LL lalal=0;
	for (LL i=2;i*x<=1000000;i++)
	{
		lalal=lalal+dfs(i*x);
		if (lalal>=MOD) lalal-=MOD;
	}
	f[x]=((cnt[x]*get(2,cnt[x]-1)%MOD-lalal)%MOD+MOD)%MOD;
	return f[x];
}
int main()
{
	memset(in,false,sizeof(in));
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++)	scanf("%lld",&s[u]);
	for (LL u=1;u<=n;u++)
	{
		for (LL i=2;i*i<=s[u];i++)
			if (s[u]%i==0)
			{
				cnt[i]++;
				if (i*i!=s[u]) cnt[s[u]/i]++;
			}
		cnt[s[u]]++;
	}
	for (LL u=2;u<=1000000;u++) dfs(u);
	LL ans=0;
	for (LL u=2;u<=1000000;u++) ans=(ans+u*f[u]%MOD)%MOD;
	printf("%lld\n",ans);
	return 0;
}