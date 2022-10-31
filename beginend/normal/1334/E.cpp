#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=105;
const int MOD=998244353;

LL D,p[N];
int jc[N],ny[N],tot,c[N];
map<LL,int> ans;

void pre(int n)
{
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
}

void dfs(int x,int s,LL v,int k)
{
	if (x>tot) {ans[v]=(LL)k*jc[s]%MOD;return;}
	for (int i=0;i<=c[x];i++,v*=p[x])
		dfs(x+1,s+i,v,(LL)k*ny[i]%MOD);
}

LL gcd(LL x,LL y)
{
	return !y?x:gcd(y,x%y);
}

int main()
{
	scanf("%lld",&D);
	int cnt=0;
	for (LL i=2;i*i<=D;i++)
		if (D%i==0)
		{
			p[++tot]=i;
			while (D%i==0) D/=i,c[tot]++;
			cnt+=c[tot];
		}
	if (D>1) p[++tot]=D,c[tot]=1,cnt++;
	pre(cnt);
	dfs(1,0,1,1);
	int q;scanf("%d",&q);
	while (q--)
	{
		LL x,y;scanf("%lld%lld",&x,&y);
		LL d=gcd(x,y);
		x/=d;y/=d;
		printf("%d\n",(LL)ans[x]*ans[y]%MOD);
	}
	return 0;
}