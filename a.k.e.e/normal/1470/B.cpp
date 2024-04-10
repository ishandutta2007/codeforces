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
const int MAXN=1000005;

int n,a[MAXN],to[MAXN];
void solve()
{
	int Q;ll w;
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]),a[i]=to[a[i]];
	sort(a+1,a+n+1);
	a[n+1]=0;
	int c=0,d=0,s=0;
	for(int i=1;i<=n;++i)
	{
		++c;
		if(a[i]!=a[i+1])
		{
			if(!(c&1) || a[i]==1)s+=c;
			chkmax(d,c);
			c=0;
		}
	}
	chkmax(s,d);
	readint(Q);
	while(Q--)
	{
		readint(w);
		printf("%d\n",w?s:d);
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	for(int i=1;i<=1000000;++i)
	{
		int x=i,y=1;
		for(int j=2;j*j*j<=x;++j)
		{
			while(x%(j*j)==0)x/=j*j,y*=j*j;
			if(x%j==0)x/=j;
		}
		int t=sqrt(x);
		if(t*t==x)y*=t*t,x/=t*t;
		to[i]=i/y;
	}
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}