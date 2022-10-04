#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=4005,MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
inline int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}

int n,m,l,a[MAXN],res[MAXN],len=0,temp[MAXN],c[MAXN][MAXN];
void mul(int A,int B,int C)
{
	inc(A,MOD),inc(B,MOD),inc(C,MOD);
	memset(temp,0,sizeof(temp));
	for(int i=0;i<=len;++i)
		inc(temp[i],1ll*a[i]*C%MOD),
		inc(temp[i+1],1ll*a[i]*B%MOD),
		inc(temp[i+2],1ll*a[i]*A%MOD);
	len+=2;
	memcpy(a,temp,sizeof(a));
}
void div(int B)
{
	inc(B,MOD);
	memset(temp,0,sizeof(temp));
	for(int i=len;i;--i)
		inc(temp[i-1],a[i]),
		inc(a[i-1],MOD-1ll*a[i]*B%MOD);
	--len;
	memcpy(a,temp,sizeof(a));
}
void add(int B)
{
	for(int i=0;i<=2*n;++i)
		inc(res[i],1ll*a[i]*B%MOD);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m),readint(l);
	a[0]=1;
	for(int i=1;i<=n;++i)mul(-2,2,0);
	for(int i=0;i<=n;++i)
	{
		c[i][0]=1;
		for(int j=1;j<=i;++j)c[i][j]=dmy(c[i-1][j-1]+c[i-1][j]);
	}
	for(int i=n;i>=m;--i)
	{
//for(int i=0;i<=2*n;++i)cerr<<(a[i]>MOD/2?a[i]-MOD:a[i])<<" ";cerr<<endl;
		add(c[n][i]);
		div(-1),div(0);
		mul(-1,1,-qmi(2,MOD-2));
	}
//for(int i=0;i<=2*n;++i)cerr<<(res[i]>MOD/2?res[i]-MOD:res[i])<<" ";cerr<<endl;
	int ans=0;
	for(int i=0;i<=2*n;++i)
		inc(ans,1ll*res[i]*qmi(i+1,MOD-2)%MOD);
	printf("%I64d\n",1ll*ans*l%MOD);
	return 0;
}