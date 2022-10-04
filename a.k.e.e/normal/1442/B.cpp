#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
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

int n,m,a[MAXN],b[MAXN];
set<int> vis;
void solve()
{
	vis.clear();
	int x;
	readint(n),readint(m);
	for(int i=1;i<=n;++i)readint(x),a[x]=i;
	vis.insert(0);vis.insert(n+1);
	for(int i=1;i<=m;++i)readint(b[i]),b[i]=a[b[i]],vis.insert(b[i]);
	int ans=1;
	for(int i=1;i<=m;++i)
		ans=1ll*ans*(2-vis.count(b[i]-1)-vis.count(b[i]+1))%MOD,
		vis.erase(b[i]);
	printf("%d\n",ans);
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