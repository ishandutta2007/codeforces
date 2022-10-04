#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=200005;

int n,rt;
pii e[MAXN],p[MAXN];
vector<int> G[MAXN];
vector<pii> sub[MAXN];
int val[MAXN],cnt[MAXN];
void dfs(int u,int pe)
{
	for(auto i:G[u])
	{
		if(i==pe)continue;
		int v=e[i].x^e[i].y^u;
		int x=(u==e[i].x?p[i].x:p[i].y),y=p[i].x^p[i].y^x;
		val[v]=1ll*val[u]*y%MOD*qmi(x,MOD-2)%MOD;
		for(auto r:sub[x])while(cnt[r.x]<r.y)++cnt[r.x];
		for(auto r:sub[x])cnt[r.x]-=r.y;
		for(auto r:sub[y])cnt[r.x]+=r.y;
		dfs(v,i);
		for(auto r:sub[x])cnt[r.x]+=r.y;
		for(auto r:sub[y])cnt[r.x]-=r.y;
	}
}
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1;i<n;++i)
	{
		readint(e[i].x),readint(e[i].y),readint(p[i].x),readint(p[i].y);
		G[e[i].x].pb(i),G[e[i].y].pb(i);
		int d=__gcd(p[i].x,p[i].y);
		p[i].x/=d,p[i].y/=d;
	}
	val[1]=1;
	memset(cnt,0,sizeof(int)*(n+1));
	dfs(1,0);
	int sum=0;
	for(int i=1;i<=n;++i)inc(sum,val[i]);
	for(int i=1;i<=n;++i)sum=1ll*sum*qmi(i,cnt[i])%MOD;
	printf("%d\n",sum);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
	#endif 
	const int m=200000;
	for(int i=1;i<=m;++i)
	{
		int cur=i;
		for(int j=2;j*j<=cur;++j)
			if(cur%j==0)
			{
				int c=0;
				while(cur%j==0)cur/=j,++c;
				sub[i].pb(mp(j,c));
			}
		if(cur>1)sub[i].pb(mp(cur,1));
	}
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}