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
const int MAXN=500005;

int n,a[MAXN];
ll res;
void solve(int w)
{
	ll sum=0;
	for(int i=1,j=1;i<=n;++i)
		if(a[i]==w)sum+=abs(i-j),j+=2;
	chkmin(res,sum);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)
	{
		int cnt=0;
		readint(n);
		for(int i=1;i<=n;++i)readint(a[i]),a[i]&=1,cnt+=a[i];
		res=1ll<<60;
		if(cnt==n/2)solve(0);
		if(cnt==(n+1)/2)solve(1);
		if(res==(1ll<<60))printf("-1\n");
		else printf("%lld\n",res);
	}
	return 0;
}