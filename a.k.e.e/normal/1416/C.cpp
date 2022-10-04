#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
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
inline int inv(int x){return qmi(x,MOD-2);}
const int MAXN=300005;

int n,a[MAXN],m,cnt[2][MAXN],st[MAXN];
ll sum[MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	int res=0;ll ans=0;
	for(int k=29;k>=0;--k)
	{
		memset(sum,0,sizeof(sum));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i)st[i]=(a[i]>>k)>>1;
		sort(st+1,st+n+1);
		for(int i=1;i<=n;++i)
		{
			int u=a[i]>>k;
			int j=lower_bound(st+1,st+n+1,u>>1)-st;
			if(!(u&1))sum[j]+=cnt[1][j];
			++cnt[u&1][j];
		}
		ll c0=0,c1=0;
		for(int i=1;i<=n;++i)
		{
			int x=cnt[0][i],y=cnt[1][i];
			ll s=sum[i];
			c0+=s,c1+=1ll*x*y-s;
		}
		if(c1<c0)res^=(1<<k),ans+=c1;
		else ans+=c0;
	}
	printf("%I64d %d\n",ans,res);
	return 0;
}