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
inline int inv(int x){return qmi(x,MOD-2);}
const int MAXN=300005;

int n,a[MAXN],las[MAXN],b[MAXN],f[MAXN];
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)b[i]=las[i]=0,f[i]=1<<30;
	for(int i=1;i<=n;++i)
	{
		readint(a[i]);
		chkmax(b[a[i]],i-las[a[i]]);
		las[a[i]]=i;
	}
	for(int i=1;i<=n;++i)chkmax(b[i],n-las[i]+1);
	for(int i=1;i<=n;++i)chkmin(f[b[i]],i);
	for(int i=2;i<=n;++i)chkmin(f[i],f[i-1]);
	for(int i=1;i<=n;++i)printf("%d ",f[i]==(1<<30)?-1:f[i]);putchar('\n');
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}