#include<bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long LL;
typedef std::pair<int,LL> pi;

const int N=100005;
const int MOD=1000000007;

int n,dep[N],ans,cnt,last[N];
LL a[N];
std::vector<pi> vec[N];
struct edge{int to,next;}e[N*2];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

LL gcd(LL x,LL y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	vec[x].pb(mp(x,a[x]));
	LL d=a[x];int now=x;
	for (int i=0;i<vec[fa].size();i++)
	{
		int y=vec[fa][i].first;
		LL w=gcd(vec[fa][i].second,d);
		if (w!=d) (ans+=(LL)d*(dep[now]-dep[y])%MOD)%=MOD,d=w,now=y,vec[x].pb(mp(y,d));
	}
	(ans+=(LL)d*dep[now]%MOD)%=MOD;
	vec[x].pb(mp(now,d));
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}