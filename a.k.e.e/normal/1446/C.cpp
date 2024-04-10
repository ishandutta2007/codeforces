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
const int MAXN=200005;

int n,a[MAXN];
int ch[MAXN*35][2],stot=1,sz[MAXN*35];
int solve(int u)
{
	if(!u)return 0;
	if(!ch[u][0] && !ch[u][1])return 1;
	return max(solve(ch[u][0])+(sz[ch[u][1]]?1:0),
		solve(ch[u][1])+(sz[ch[u][0]]?1:0));
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
	{
		int x;
		readint(x);
		int p=1;
		for(int j=29;j>=0;--j)
		{
			if(!ch[p][(x>>j)&1])ch[p][(x>>j)&1]=++stot;
			p=ch[p][(x>>j)&1];
			++sz[p];
		}
	}
	printf("%d\n",n-solve(1));
	return 0;
}