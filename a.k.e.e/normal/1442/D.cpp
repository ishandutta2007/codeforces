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
const int MAXN=3005;

int n,m;
vector<ll> a[MAXN];
ll sum[MAXN],ans;
ll f[MAXN][MAXN];
void solve(int d,int l,int r)
{
	if(l==r)
	{
		chkmax(ans,f[d][m]);
		ll s=0;
		for(int i=1;i<=a[l].size() && i<=m;++i)
			s+=a[l][i-1],chkmax(ans,s+f[d][m-i]);
		return;
	}
	int mid=(l+r)>>1;
	for(int j=0;j<=m;++j)f[d+1][j]=f[d][j];
	for(int i=mid+1;i<=r;++i)
		for(int j=m;j>=a[i].size();--j)
			chkmax(f[d+1][j],f[d+1][j-a[i].size()]+sum[i]);
	solve(d+1,l,mid);
	for(int j=0;j<=m;++j)f[d+1][j]=f[d][j];
	for(int i=l;i<=mid;++i)
		for(int j=m;j>=a[i].size();--j)
			chkmax(f[d+1][j],f[d+1][j-a[i].size()]+sum[i]);
	solve(d+1,mid+1,r);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=1;i<=n;++i)
	{
		int K,x;readint(K);
		while(K--)readint(x),a[i].pb(x);
		for(auto j:a[i])sum[i]+=j;
	}
	solve(0,1,n);
	printf("%lld\n",ans);
	return 0;
}