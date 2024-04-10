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

int L,R,n,G[35][35];
void solve(int R)
{
	if(R==1)
	{
		++n;
		G[n][1]=1;
		return;
	}
	if(R&1)
	{
		int t=(R+1)/2;
		solve(t);
		++n;
		G[n][n-1]=t-1;
		for(int i=1;i<=n-2;++i)G[n][i]=G[n-1][i];
		G[n-1][1]=0;
	}
	else
	{
		int t=R/2;
		solve(t);
		++n;
		G[n][n-1]=t;
		for(int i=1;i<=n-2;++i)G[n][i]=G[n-1][i];
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(L),readint(R);
	n=1;
	solve(R-L+1);
	for(int j=1;j<n;++j)if(G[n][j])G[n][j]+=L-1;
	int m=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			if(G[i][j])++m;
	printf("YES\n%d %d\n",n,m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			if(G[i][j])printf("%d %d %d\n",n-i+1,n-j+1,G[i][j]);
	return 0;
}