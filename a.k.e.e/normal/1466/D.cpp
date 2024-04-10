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

int n,a[MAXN];
bool vis[MAXN];
void solve()
{
	readint(n);
	ll sum=0;
	for(int i=1;i<=n;++i)readint(a[i]),vis[i]=0,sum+=a[i];
	vector<int> b;
	for(int i=1;i<=2*n-2;++i)
	{
		int u;
		readint(u);
		if(!vis[u])vis[u]=1;
		else b.pb(a[u]);
	}
	sort(b.begin(),b.end());reverse(b.begin(),b.end());
	printf("%lld ",sum);
	for(int i=0;i<n-2;++i)sum+=b[i],printf("%lld ",sum);
	putchar('\n');
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