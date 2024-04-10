#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
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
const int MAXN=100005;

int m,n,a[MAXN],b[MAXN];
vector<pii> c;
inline bool cmp(pii p,pii q){return a[p.x]+b[p.y]>a[q.x]+b[q.y];}
int fa[MAXN<<1];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	ll sum=0;
	readint(m),readint(n);
	for(int i=1;i<=m;++i)readint(a[i]);
	for(int i=1;i<=n;++i)readint(b[i]);
	for(int i=1;i<=m;++i)
	{
		int k,j;
		readint(k);
		while(k--)readint(j),c.pb(mp(i,j)),sum+=a[i]+b[j];
	}
	sort(c.begin(),c.end(),cmp);
	for(int i=1;i<=n+m;++i)fa[i]=i;
	for(auto p:c)
	{
		int u=getfa(p.x),v=getfa(p.y+m);
		if(u==v)continue;
		sum-=a[p.x]+b[p.y];
		fa[u]=v;
	}
	printf("%lld\n",sum);
	return 0;
}