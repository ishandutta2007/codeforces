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
const int MAXN=1005;

int n,m,a[MAXN][MAXN],s[MAXN],b[MAXN],ss[MAXN];
int check(int d)
{
	int r=0;
	for(int i=1;i<=n;++i)if(s[i]-i*d!=s[1]-d)r=(r?-1:i);
	if(r>0)return r;
	r=0;
	for(int i=1;i<=n;++i)if(s[i]-i*d!=s[2]-2*d)r=(r?-1:i);
	return r>0?r:0;
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(m),readint(n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			readint(a[i][j]),s[i]+=a[i][j],inc(ss[i],1ll*a[i][j]*a[i][j]%MOD);
	int d=(s[n]-s[1])/(n-1);
	int p=check(d);
	int x[3]={1,(p==2?3:2),n};
	int y[3];
	for(int i=0;i<3;++i)y[i]=ss[x[i]];
	int sp=s[1]+(p-1)*d,ssp=0;
	for(int i=0;i<3;++i)
	{
		int u=y[i];
		for(int j=0;j<3;++j)
			if(i!=j)u=1ll*u*(p-x[j]+MOD)%MOD*qmi(x[i]-x[j]+MOD,MOD-2)%MOD;
		inc(ssp,u);
	}
	inc(sp,MOD-s[p]),inc(ssp,MOD-ss[p]);
	int tp=1ll*ssp*qmi(sp,MOD-2)%MOD;
	printf("%d %d\n",p-1,1ll*(tp+sp)*qmi(2,MOD-2)%MOD);
	return 0;
}