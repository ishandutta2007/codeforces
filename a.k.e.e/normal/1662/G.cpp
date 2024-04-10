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
const int MAXN=1000005;

int n;
vector<int> G[MAXN];
int pa[MAXN],sz[MAXN];
ll fs[MAXN],gs[MAXN];
void dfs1(int u)
{
	sz[u]=1,fs[u]=0;
	for(auto v:G[u])
		dfs1(v),sz[u]+=sz[v],fs[u]+=fs[v]+sz[v];
}
void dfs2(int u)
{
	for(auto v:G[u])
		gs[v]=gs[u]+n-sz[u]+fs[u]-fs[v]-sz[v],dfs2(v);
}

int o,a[MAXN];
int work()
{
	sort(a+1,a+o+1);
	if(a[o]>=(n-1)/2)return a[o];
	bitset<MAXN> b;b[0]=1;
	for(int i=1,cur=0;i<=o;++i)
	{
		++cur;
		if(i==o || a[i]!=a[i+1])
		{
			for(int x=1;cur;cur-=x,x=min(x<<1,cur))
				b=b|b<<(x*a[i]);
		}
	}
	for(int i=(n-1)/2;i>=0;--i)
		if(b[i])return i;
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=2;i<=n;++i)readint(pa[i]),G[pa[i]].pb(i); 
	dfs1(1),dfs2(1);
	ll res=0;
	for(int i=1;i<=n;++i)
	{
		ll sum=0;
		o=0;
		for(auto v:G[i])sum+=fs[v]+sz[v],a[++o]=sz[v];
		if(i>1)sum+=gs[i]+n-sz[i],a[++o]=n-sz[i];
		int t=work();
		sum+=1ll*t*(n-1-t);
		chkmax(res,sum);
	}
	printf("%lld\n",res+n);
	return 0;
}