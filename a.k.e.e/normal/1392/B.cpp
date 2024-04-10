#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
inline int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=200005;

int n,k,a[MAXN];
void solve()
{
	int mx=-1<<30;
	readint(n),readint(k);
	for(int i=1;i<=n;++i)readint(a[i]),chkmax(mx,a[i]);
	for(int i=1;i<=n;++i)a[i]=mx-a[i];
	if(!(k&1))
	{
		mx=-1<<30;
		for(int i=1;i<=n;++i)chkmax(mx,a[i]);
		for(int i=1;i<=n;++i)a[i]=mx-a[i];
	}
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
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