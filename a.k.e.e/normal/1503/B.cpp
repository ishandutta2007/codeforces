#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
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
const int MAXN=105;

int n;
int a[MAXN][MAXN];
vector<pii> b[2];

int main()
{
	#ifdef LOCAL
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			b[(i+j)&1].pb(mp(i,j));
	for(int i=1;i<=n*n;++i)
	{
		int x,t;
		readint(x);
		if(x<=2)t=2-x;
		else if(b[0].empty())t=1;
		else t=0;
		if(b[t].empty())
		{
			pii p=b[t^1].back();
			printf("%d %d %d\n",3,p.x,p.y);fflush(stdout);
			b[t^1].pop_back();
		}
		else
		{
			pii p=b[t].back();
			printf("%d %d %d\n",t+1,p.x,p.y);fflush(stdout);
			b[t].pop_back();
		}
	}
	return 0;
}