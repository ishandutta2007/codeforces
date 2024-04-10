#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MAXN=3005,INF=0x3f3f3f3f;

int n,a[MAXN],f[MAXN][MAXN],from[MAXN][MAXN];
vector<int> pos[MAXN];
void solve()
{
	readint(n);
	for(int i=0;i<=n;++i)pos[i].clear();
	for(int i=1;i<=n;++i)readint(a[i]),pos[a[i]].pb(i);
	a[n+1]=0;
	for(int i=n;i;--i)
	{
		f[i][i]=(a[i]!=a[i+1]&&a[i]!=a[i-1]);
		from[i][i]=i;
		for(int j=i+1;j<=n;++j)
		{
			f[i][j]=INF;
			for(int k=from[i][j-1];k<=from[i+1][j];++k)
				if(chkmin(f[i][j],f[i][k-1]+f[k+1][j]+1))
					from[i][j]=k;
			for(auto k:pos[a[i-1]])
				if(k>=i&&k<=j)chkmin(f[i][j],f[i][k-1]+f[k+1][j]);
			for(auto k:pos[a[j+1]])
				if(k>=i&&k<=j)chkmin(f[i][j],f[i][k-1]+f[k+1][j]);
		}
	}
	int res=INF;
	for(int i=1;i<=n;++i)
		chkmin(res,f[1][i-1]+f[i+1][n]);
	printf("%d\n",res);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}