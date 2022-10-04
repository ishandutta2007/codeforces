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
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=300005;

int n,m,p[MAXN],q[MAXN],cnt[MAXN],fa[MAXN];
vector<int> res;
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
void check(int k)
{
	for(int i=1;i<=k;++i)q[i]=n-k+i;
	for(int i=k+1;i<=n;++i)q[i]=i-k;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=n;++i)fa[getfa(p[i])]=getfa(q[i]);
	int cnt=n;
	for(int i=1;i<=n;++i)if(i==getfa(i))--cnt;
	if(cnt<=m)res.pb(k);
}
void solve()
{
	readint(n),readint(m);
	memset(cnt,0,sizeof(int)*n);
	for(int i=1;i<=n;++i)readint(p[i]),++cnt[(i-p[i]+n)%n];
	res.clear();
	for(int i=0;i<n;++i)if(cnt[i]>=n-2*m)check(i);
	printf("%d",res.size());
	for(auto i:res)printf(" %d",i);putchar('\n');
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}