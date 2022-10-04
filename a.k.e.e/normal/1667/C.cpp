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
const int MAXN=500015,INF=0x3f3f3f3f;

int n;
vector<pii> a;
void solve()
{
	readint(n);
	if(n==1)
	{
		printf("1\n1 1\n");
		return;
	}
	while(n%3!=2)a.pb(mp(n,n)),--n;
	int m=2*n/3;
	for(int i=1;i<=(m+1)/2;++i)a.pb(mp(i,(m+1)/2+1-i));
	for(int i=1;i<=m/2;++i)a.pb(mp((m+1)/2+i,m+1-i));
	printf("%d\n",a.size());
	for(auto p:a)printf("%d %d\n",p.x,p.y);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;T=1;
//	readint(T);
	while(T--)solve();
	return 0;
}