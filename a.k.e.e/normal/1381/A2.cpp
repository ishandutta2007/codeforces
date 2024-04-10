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
/*const int MOD=;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=200005;

int n,m,op[MAXN];
char a[MAXN],b[MAXN];
void solve()
{
	m=0;
	scanf("%d%s%s",&n,a+1,b+1);
	for(int i=1,j=n,k=n,c=1;k;--k,c^=1)
	{
		if(i<=n-j+1)
		{
			if(((a[i]-'0')^c)!=b[k]-'0')op[++m]=1;
			++i;
		}
		else
		{
			if(((a[j]-'0')^c)!=b[k]-'0')op[++m]=1;
			--j;
		}
		op[++m]=k;
	}
	printf("%d ",m);
	for(int i=1;i<=m;++i)printf("%d ",op[i]);
	putchar('\n');
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}