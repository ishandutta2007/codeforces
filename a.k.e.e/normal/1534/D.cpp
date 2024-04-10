#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
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
int inv(int x){return qmi(x,MOD-2);}
const int MAXN=2005;

int n,d[MAXN][MAXN],G[MAXN][MAXN];
void query(int r)
{
	if(d[r][0])return;
	printf("? %d\n",r);fflush(stdout);d[r][0]=-1;
	for(int i=1;i<=n;++i)readint(d[r][i]);
}

int main()
{
	#ifdef LOCAL
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	query(1);
	int cnt1[2]={0,0};
	for(int i=1;i<=n;++i)cnt1[d[1][i]&1]++;
	int w=(cnt1[1]<cnt1[0]);
	for(int i=1;i<=n;++i)
		if((d[1][i]&1)==w)
		{
			query(i);
			for(int j=1;j<=n;++j)
				if(d[i][j]==1)G[i][j]=G[j][i]=1;
		}
	printf("!\n");
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(G[i][j])printf("%d %d\n",i,j);
	return 0;
}