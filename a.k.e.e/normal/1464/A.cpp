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
const int MOD=1000000007;
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

int n,m;
int fa[MAXN],num[MAXN],sz[MAXN];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
void solve()
{
	readint(n),readint(m);
	for(int i=1;i<=n;++i)fa[i]=i,num[i]=0,sz[i]=1;
	int cnt=0;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		readint(x),readint(y);
		if(x!=y)
		{
			x=getfa(x),y=getfa(y);
			if(x==y)++num[x];
			else fa[x]=y,num[y]+=num[x]+1,sz[y]+=sz[x];
			++cnt;
		}
	}
	for(int i=1;i<=n;++i)
		if(getfa(i)==i && sz[i]>=2 && num[i]==sz[i])
			++cnt;
	printf("%d\n",cnt);
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