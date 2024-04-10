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
/*const int MOD=
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=105;

int n,m;
int a[MAXN];
int p[MAXN],q[MAXN];
int ask(int x,int y)
{
	printf("?");
	for(int i=1;i<=n;++i)printf(" %d",i==x?y+1:1);
	putchar('\n');
	fflush(stdout);
	int z;
	readint(z);
/*for(int i=1;i<=n;++i)
	for(int j=i+1;j<=n;++j)
		if(a[i]+(i==x?y+1:1)==a[j]+(j==x?y+1:1))
			return i;*/
	return z;
}

int main()
{
	#ifdef LOCAL
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);m=n;
//for(int i=1;i<=n;++i)readint(a[i]);
	memset(p,-1,sizeof(p));
	for(int i=n;i;--i)
	{
		if(p[i]>=0)continue;
		memset(q,-1,sizeof(q));
		q[i]=0;
		int x=1;
		for(;x<n;++x)
		{
			int y=ask(i,x);
			if(!y || y>=i)break;
			q[y]=x;
		}
		for(int j=1;j<=n;++j)
			if(q[j]>=0)p[j]=m-x+q[j];
		m-=x;
	}
	printf("!");
	for(int i=1;i<=n;++i)printf(" %d",p[i]+1);
	putchar('\n');
	fflush(stdout);
	return 0;
}