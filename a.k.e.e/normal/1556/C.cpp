#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
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
const int MAXN=1005;

int n;
ll a[MAXN];
ll sum[MAXN][MAXN],minp[MAXN][MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	if(n&1)--n;
	ll res=0;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
		{
			sum[i][j]=sum[i][j-1]+a[j]*((j&1)?1:-1);
			minp[i][j]=min(minp[i][j-1],sum[i][j]);
		}
	for(int i=1;i<=n;i+=2)
		for(int j=i+1;j<=n;j+=2)
		{
			ll s=sum[i+1][j-1],m=-minp[i+1][j-1];
			ll l=m,r=a[i];
			chkmax(l,-s+1);chkmin(r,a[j]-s);
			res+=max(r-l+1,0ll);
//			cerr<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
		}
	cout<<res<<endl;
	return 0;
}