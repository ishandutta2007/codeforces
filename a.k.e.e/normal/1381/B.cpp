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
const int MAXN=4005;

int n,a[MAXN],m,b[MAXN];
bool f[MAXN][MAXN];
void solve()
{
	readint(n);
	for(int i=1;i<=2*n;++i)readint(a[i]);a[2*n+1]=2*n+1;
	int cur=1;
	m=0;
	for(int i=2;i<=2*n+1;++i)
		if(a[i]>a[cur])
		{
			b[++m]=i-cur;
			cur=i;
		}
	f[0][0]=1;
	for(int i=1;i<=m;++i)
		for(int j=0;j<=2*n;++j)
			if(j<b[i])f[i][j]=f[i-1][j];
			else f[i][j]=(f[i-1][j]||f[i-1][j-b[i]]);
	printf(f[m][n]?"YES\n":"NO\n");
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