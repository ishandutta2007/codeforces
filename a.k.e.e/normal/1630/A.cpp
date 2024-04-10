#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
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
int n,k;
int a[MAXN];
void solve()
{
	readint(n),readint(k);
	if(k==n-1)
	{
		if(n==4)
		{
			printf("-1\n");
			return;
		}
		memset(a,-1,sizeof(a));
		for(int i=1;i<n;i<<=1)
		{
			int j=i<<1;
			if(j==n)j=1;
			a[i]=(n-1)^j;
			a[(n-1)^j]=i;
		}
		for(int i=0;i<n;++i)
			if(a[i]<0)a[i]=i^(n-1);
		for(int i=0;i<n;++i)
			if(i<a[i])printf("%d %d\n",i,a[i]);
	}
	else
	{
		for(int i=1;i<n/2;++i)
		{
			int j=n-1-i;
			if(i==k||j==k)continue;
			printf("%d %d\n",i,j);
		}
		if(k)printf("%d %d\n%d %d\n",0,n-1-k,k,n-1);
		else printf("%d %d\n",0,n-1);
	}
}

int main()
{
	#ifdef LOCAL
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}