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

int n,a[MAXN],f[MAXN];
int vis[MAXN],timer;
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	++timer;
	f[n+1]=0;
	for(int i=n;i;--i)
	{
		vis[a[i]]=timer;
		f[i]=f[i+1];
		while(vis[f[i]]==timer)++f[i];
	}
	vector<int> b;
	for(int i=1;i<=n;)
	{
		++timer;
		int cur=0,p=i;
		for(int j=i;j<=n;++j)
		{
			vis[a[j]]=timer;
			while(vis[cur]==timer)++cur;
			if(cur==f[i]){p=j;break;}
		}
		b.pb(f[i]);
		i=p+1;
	}
	printf("%d\n",b.size());
	for(auto i:b)printf("%d ",i);
	putchar('\n');
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