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
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
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
const int MAXN=105,MAXM=200005,M=100001;

int n,c[MAXN],b[MAXN];
int f[MAXN][MAXN*MAXN];
int res[MAXM];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	int mulc=1;
	for(int i=1;i<=n;++i)readint(c[i]),mulc=1ll*mulc*(c[i]+1)%MOD;
	for(int i=2;i<=n;++i)readint(b[i]),b[i]+=b[i-1];
	for(int x=-M;x<=M;++x)
	{
		int sum=0,pre=0;
		bool fl1=0,fl2=0;
		for(int i=1;i<=n;++i)
		{
			sum+=b[i]+x,
			pre+=c[i];
			if(pre-sum<0)fl1=1;
			if(sum>0)fl2=1;
		}
		if(fl1)continue;
		if(!fl2){res[x+M]=mulc;continue;}
		memset(f,0,sizeof(f));
		sum=0,pre=0;
		f[0][0]=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=max(sum,0);j<=pre;++j)
				inc(f[i][j],f[i-1][j]),
				inc(f[i][j+c[i]+1],MOD-f[i-1][j]);
			sum+=b[i]+x;
			pre+=c[i];
			for(int j=1;j<=pre;++j)inc(f[i][j],f[i][j-1]);
		}
		for(int j=max(sum,0);j<=pre;++j)
			inc(res[x+M],f[n][j]);
	}
	int Q;
	readint(Q);
	while(Q--)
	{
		int x;readint(x);
		printf("%d\n",res[x+M]);
	}
	return 0;
}