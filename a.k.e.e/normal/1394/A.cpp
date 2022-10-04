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
const int MAXN=200005;

int n,d,m,a[MAXN];
ll pre[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(d),readint(m);
	for(int i=1;i<=n;++i)readint(a[i]);
	sort(a+1,a+n+1);
	int p=upper_bound(a+1,a+n+1,m)-a;
	for(int i=1;i<p;++i)pre[i]=pre[i-1]+a[p-i];
	ll ans=pre[p-1],sum=0;
	for(int i=1;i<=n-p+1;++i)
	{
		sum+=a[n-i+1];
		if(1+1ll*(i-1)*(d+1)<=n-p+1)chkmax(ans,sum+pre[p-1]);
		else if(1+1ll*(i-1)*(d+1)<=n)chkmax(ans,sum+pre[n-1-1ll*(i-1)*(d+1)]);
	}
	cout<<ans<<endl;
	return 0;
}