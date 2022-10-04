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
const int INF=0x3f3f3f3f;
const int MAXN=200005;

int n,a[MAXN];
bool work()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	if(n==1)return 1;
	if(a[1]==0)
	{
		if(a[2]==1)return 0;
		return 1;
	}
	if(a[1]>=2)return 1;
	for(int i=1;i<n;++i)
		if(a[i+1]-a[i]==1)return 0;
	return 1;
}
void solve()
{
	printf(work()?"YES\n":"NO\n");
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