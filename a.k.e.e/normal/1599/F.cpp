#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
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
const int MAXN=400005,K=15;

int n,a[MAXN];
int pre[K+1][MAXN],kr[K+1][MAXN];
int pd[K+1],pc[K+1],binom[K+1][K+1];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
	#endif
	int Q;readint(n),readint(Q);
	for(int i=1;i<=n;++i)readint(a[i]),a[i+n]=a[i];
	for(int i=1;i<=2*n;++i)
	{
		int x=1,y=1;
		for(int k=0;k<=K;++k)
			pre[k][i]=dmy(pre[k][i-1]+x),
			kr[k][i]=dmy(kr[k][i-1]+y),
			x=1ll*x*a[i]%MOD,y=1ll*y*(i-1)%MOD;
	}
	for(int i=0;i<=K;++i)
	{
		binom[i][0]=1;
		for(int j=1;j<=i;++j)binom[i][j]=dmy(binom[i-1][j-1]+binom[i-1][j]);
	}
	while(Q--)
	{
		int l,r,d;
		readint(l),readint(r),readint(d);
		if(r<l)r+=n;
		int m=r-l+1;
		int c=((pre[1][r]-pre[1][l-1]-1ll*kr[1][m]*d)%MOD+MOD)*qmi(m,MOD-2)%MOD;
		pc[0]=pd[0]=1;
		for(int k=1;k<=K;++k)pc[k]=1ll*pc[k-1]*c%MOD,pd[k]=1ll*pd[k-1]*d%MOD;
		bool fl=1;
		for(int k=2;k<=K;++k)
		{
			int sum=0;
			for(int j=0;j<=k;++j)
				inc(sum,1ll*pd[j]*pc[k-j]%MOD*binom[k][j]%MOD*kr[j][m]%MOD);
			if(sum!=dmy(pre[k][r]-pre[k][l-1]+MOD)){fl=0;break;}
		}
		printf(fl?"Yes\n":"No\n");
	}
	return 0;
}