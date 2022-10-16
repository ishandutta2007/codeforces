#include<bits/stdc++.h>
typedef long long ll;
struct func
{
	int k;ll b;
	func(){}func(int _k,ll _b){k=_k,b=_b;}
	ll operator()(int x){return k*1ll*x+b;}
};
const int axis=1e5;
void emin(ll&x,ll y){x<y?0:x=y;}
bool vis[111111];
struct segt
{
	int s[8111111][2],cr=2e5;
	func f[8111111];
	void ins(func g,int p)
	{
		if(!vis[p]){f[p]=g,vis[p]=1;return;}
		for(register int pl=-axis,pr=axis;;)
		{
			int pm=(pl+pr)>>1,dr=0;
			if(f[p](pm)>g(pm)){func a=g;g=f[p],f[p]=a;}
			//printf("I %d | (%dx+%lld)\n",p,g.k,g.b);
			if(pl==pr)return;
			if(f[p](pl)<g(pl))
			{
				if(f[p](pr)<g(pr))return;
				dr=1;
			}
			if(!s[p][dr]){s[p][dr]=++cr,f[cr]=g;return;}
			dr?pl=pm+1:pr=pm,p=s[p][dr];
		}
	}
	ll ask(int x,int p)
	{
		ll mn=1e18;
		for(register int pl=-axis,pr=axis;;)
		{
			//printf("Q %d | (%dx+%lld)\n",p,f[p].k,f[p].b);
			emin(mn,f[p](x));
			int pm=(pl+pr)>>1,dr=x>pm;
			if(!s[p][dr])return mn;
			dr?pl=pm+1:pr=pm,p=s[p][dr];
		}
	}
}S;
std::vector<int>v[111111],s[111111];
ll dp[111111];
int n,a[111111],b[111111];
int dfs(int p,int f=0)
{
	int r=p,u=0;
	for(int t:v[p])if(t^f)
	{
		u=1;
		int rt=dfs(t,p);
		if(s[r].size()<s[rt].size())r^=rt^=r^=rt;
		for(int t:s[rt])S.ins(func(b[t],dp[t]),r),s[r].push_back(t);
	}dp[p]=S.ask(a[p],r);if(!u)dp[p]=0;
	s[r].push_back(p),S.ins(func(b[p],dp[p]),r);
	return r;
}
int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)scanf("%d",b+i);
	for(i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b),v[a].push_back(b),v[b].push_back(a);
	}dfs(1);	
	for(i=1;i<=n;i++)printf("%lld ",dp[i]);puts("");
}
/*
Please don't let me down.
*/