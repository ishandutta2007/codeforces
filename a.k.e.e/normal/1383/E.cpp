#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
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
const int MAXN=1000005;

int n,m;
char str[MAXN];
int a[MAXN],b[MAXN],f[MAXN],g[MAXN],pf[MAXN],pg[MAXN];
int sta[MAXN],top;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	scanf("%s",str+1);
	n=strlen(str+1);
	str[0]='0';m=1;
	for(int i=1;i<=n;++i)
	{
		if(str[i]=='0' && str[i-1]=='1')++m;
		if(str[i]=='0')++a[m];
		else ++b[m];
	}
	if(str[n]=='1')a[++m]=0;
	if(m==1 && !b[1])return 0*printf("%d\n",a[1]); 
	pg[1]=g[1]=a[1]+1,pf[1]=f[1]=1ll*b[1]*(a[1]+1)%MOD;
	sta[top=0]=1;
	for(int i=2;i<m;++i)
	{
		g[i]=1ll*f[i-1]*a[i]%MOD;
		while(top && a[sta[top]]<a[i])
			inc(g[i],1ll*(a[i]-a[sta[top]]+MOD)*(pf[sta[top]-1]-pf[sta[top-1]-1]+MOD)%MOD),
			--top;
		sta[++top]=i;
		pg[i]=dmy(pg[i-1]+g[i]);
		f[i]=1ll*b[i]*pg[i]%MOD;
		pf[i]=dmy(pf[i-1]+f[i]);
	}
	printf("%lld\n",1ll*pf[m-1]*(a[m]+1)%MOD);
	return 0;
}