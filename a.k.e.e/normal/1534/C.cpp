#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
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
int inv(int x){return qmi(x,MOD-2);}
const int MAXN=400005;

int n,a[2][MAXN],fa[MAXN],cnt;
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
void onion(int u,int v){u=getfa(u),v=getfa(v);if(u!=v)fa[u]=v,++cnt;}
void solve()
{
	cnt=0;
	readint(n);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int u=0;u<2;++u)for(int i=1;i<=n;++i)readint(a[u][i]);
	for(int i=1;i<=n;++i)
	{
		if(a[0][i]==a[1][i]){printf("0\n");return;}
		onion(a[0][i],a[1][i]);
	}
	printf("%d\n",qmi(2,n-cnt));
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