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
const int MAXN=100005,MAXK=19;
const ll INF=1ll<<60;
int n;
ll a[MAXN];
int _log2[MAXN];
ll rmq[MAXN][MAXK],r2[MAXN][MAXK];
ll qmax(int l,int r)
{
	int t=_log2[r-l+1];
	return max(rmq[l][t],rmq[r-(1<<t)+1][t]);
}
ll qmin(int l,int r)
{
	int t=_log2[r-l+1];
	return min(r2[l][t],r2[r-(1<<t)+1][t]);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q;
	readint(n),readint(Q);
	for(int i=1;i<=n;++i)readint(a[i]);
	for(int i=1,x;i<=n;++i)readint(x),a[i]=x-a[i]+a[i-1];
//for(int i=1;i<=n;++i)cerr<<a[i]<<endl;
	_log2[0]=-1;
	for(int i=1;i<=n;++i)
	{
		r2[i][0]=rmq[i][0]=a[i];
		_log2[i]=_log2[i>>1]+1;
	}
	for(int j=1;j<MAXK;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]),
			r2[i][j]=min(r2[i][j-1],r2[i+(1<<j-1)][j-1]);
	while(Q--)
	{
		int l,r;readint(l),readint(r);
		if(a[l-1]==a[r])
		{
			ll t=qmin(l,r-1)-a[l-1];
			if(t<0)printf("-1\n");
			else printf("%lld\n",qmax(l,r-1)-a[l-1]);
		}
		else printf("-1\n");
	}
	return 0;
}