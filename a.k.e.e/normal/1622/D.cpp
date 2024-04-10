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
const int MAXN=5005;

int n,k,m,a[MAXN];
char str[MAXN];
int dp[MAXN][MAXN],binom[MAXN][MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(k);
	if(!k)return !printf("1\n");
	scanf("%s",str+1);
	for(int i=1;i<=n;++i)if(str[i]=='1')a[++m]=i;
	for(int i=0;i<=n;++i)
	{
		binom[i][0]=1;
		for(int j=1;j<=i;++j)binom[i][j]=dmy(binom[i-1][j]+binom[i-1][j-1]);
	}
	if(k>m)return !printf("1\n");
	a[0]=0,a[m+1]=n+1;
	int res=1;
	for(int i=m;i;--i)
		for(int j=i;j<=m;++j)
		{
			int x=binom[a[j+1]-a[i-1]-1][j-i+1];
			inc(x,MOD-binom[a[j+1]-a[i]-1][j-i]);
			inc(x,MOD-binom[a[j]-a[i-1]-1][j-i]);
			if(j>i)inc(x,binom[a[j]-a[i]-1][j-i-1]);
			else inc(x,1);
			if(j-i+1<=k)inc(res,x);
		}
	printf("%d\n",res);
	return 0;
}