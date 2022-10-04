#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=4005,INF=1<<30;

int n,m,a[MAXN],b[MAXN],c[MAXN];
vector<int> f[MAXN][MAXN];
int lbt[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=n;i;--i)readint(a[i]);
	for(int i=n;i;--i)readint(b[i]);
	for(int i=1;i<=n+m;++i)readint(c[i]),c[i]+=c[i-1];
	for(int i=1;i<=n;++i)
		if(i&1)lbt[i]=0;
		else lbt[i]=lbt[i>>1]+1;
	f[0][1].pb(0);
	for(int i=0;i<n;++i)
	{
		int sz=0;
		for(int j=1;j<=m;++j)
			if(a[i+1]-j>=0 && a[i+1]-j<=12)
				chkmax(sz,(int)(f[i][j].size()-1)/(1<<(a[i+1]-j))+2);
		while(sz--)f[i+1][a[i+1]].pb(-INF);
		for(int j=1;j<=m;++j)
		{
			if(j<a[i+1])
			{
				f[i+1][j]=f[i][j];
				for(int k=0;k<(int)f[i][j].size();++k)
				{
					int kk=(a[i+1]-j>=12?0:k/(1<<(a[i+1]-j)));
					chkmax(f[i+1][a[i+1]][kk+1],f[i][j][k]-b[i+1]+c[a[i+1]+lbt[kk+1]]-c[a[i+1]-1]);
				}
			}
			else if(j==a[i+1])
				for(int k=0;k<(int)f[i][j].size();++k)
				{
					chkmax(f[i+1][j][k],f[i][j][k]);
					chkmax(f[i+1][j][k+1],f[i][j][k]-b[i+1]+c[j+lbt[k+1]]-c[j-1]);
				}
			else f[i+1][j]=f[i][j];
		}
/*cerr<<i<<":"<<endl;
for(int j=1;j<=m;++j)
{
	for(int k=0;k<(int)f[i][j].size();++k)
		cerr<<f[i][j][k]<<" ";
	cerr<<endl;
}
cerr<<endl;*/
	}
	int ans=-INF;
	for(int j=1;j<=m;++j)
		for(auto v:f[n][j])chkmax(ans,v);
	printf("%d\n",ans);
	return 0;
}