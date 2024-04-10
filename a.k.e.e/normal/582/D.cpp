#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=3505,MOD=1000000007,BASE=1000000000,WIDTH=9;

int p,m,n,f[MAXN][MAXN][2],g[MAXN][MAXN][2];
ll a[MAXN];
char str[MAXN];
struct Big
{
	int len,a[MAXN];
	int operator %(int x)const
	{
		int y=0;
		for(int i=len;i;--i)
			y=(1ll*y*BASE+a[i])%x;
		return y;
	}
	Big operator /(int x)const
	{
		Big b;
		b.len=len;
		ll add=0;
		for(int i=len;i;--i)
		{
			b.a[i]=(add*BASE+a[i])/x;
			add=(add*BASE+a[i])%x;
		}
		if(!b.a[len])--b.len;
		return b;
	}
	void input()
	{
		scanf("%s",str);
		int n=strlen(str);
		for(int i=0;i*2<n;++i)swap(str[i],str[n-i-1]);
		len=(n-1)/WIDTH+1;
		for(int i=1;i<=len;++i)
			for(int j=0,k=1;j<WIDTH && (i-1)*WIDTH+j<n;++j,k*=10)
				a[i]+=k*(str[(i-1)*WIDTH+j]-'0');
	}
}bg;

inline ll calc(ll l,ll r){return ((r-l+1)%MOD)*((l+r)%MOD)%MOD*(MOD+1)/2%MOD;}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
#endif
	readint(p);readint(m);
	bg.input();
	for(n=1;bg.len;++n)a[n]=bg%p,bg=bg/p;--n;
	if(m>n)return 0*printf("0\n");
//for(int i=1;i<=n;++i)cerr<<a[i]<<" ";cerr<<endl;
	f[1][0][0]=calc(1,p),f[1][1][1]=calc(1,p-1);
	g[1][0][0]=calc(1,a[1]+1),g[1][1][1]=calc(p-a[1]-1,p-1);
	for(int i=2;i<=n;++i)
		for(int j=0;j<=i;++j)
		{
			f[i][j][0]=(calc(1,p)*f[i-1][j][0]+calc(1,p-1)*f[i-1][j][1])%MOD;
			if(j)f[i][j][1]=(calc(1,p-1)*f[i-1][j-1][0]+calc(1,p)*f[i-1][j-1][1])%MOD;
			g[i][j][0]=((a[i]+1)*g[i-1][j][0]+a[i]*g[i-1][j][1]+
				calc(1,a[i])*f[i-1][j][0]+calc(1,a[i]-1)*f[i-1][j][1])%MOD;
			if(j)g[i][j][1]=((p-a[i]-1)*g[i-1][j-1][0]%MOD+(p-a[i])*g[i-1][j-1][1]%MOD+
				calc(p-a[i],p-1)*f[i-1][j-1][0]%MOD+calc(p-a[i]+1,p)*f[i-1][j-1][1]%MOD)%MOD;
		}
/*for(int i=1;i<=n;++i)
for(int j=0;j<=i;++j)
cerr<<i<<","<<j<<":"<<f[i][j][0]<<" "<<f[i][j][1]<<" "<<g[i][j][0]<<" "<<g[i][j][1]<<endl;*/
	ll ans=0;
	for(int j=m;j<=n;++j)
		ans=(ans+g[n][j][0])%MOD;
	printf("%lld\n",ans);
	return 0;
}