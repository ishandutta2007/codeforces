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
const int MAXN=200005;
int n,k;
int a[MAXN],p[MAXN];
void solve()
{
	readint(n),readint(k);
	for(int i=1;i<=n;++i)readint(a[i]),p[i]=a[i];
	int w=(k+n+1)/2;
	sort(p+1,p+n+1);
	int ret=0,best=1<<30;
	for(int i=1;i<=n-w+1;++i)
		if(chkmin(best,p[i+w-1]-p[i]))ret=i;
	printf("%d %d\n",p[ret],p[ret+w-1]);
	for(int i=1,cnt=0,la=0,num=1;i<=n;++i)
	{
		if(a[i]>=p[ret]&&a[i]<=p[ret+w-1])++cnt;
		else --cnt;
		if( (num<k&&cnt==1) || i==n )printf("%d %d\n",la+1,i),cnt=0,la=i,++num;
	}
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