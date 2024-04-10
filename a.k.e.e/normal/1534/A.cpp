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
/*const int MOD=;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
int inv(int x){return qmi(x,MOD-2);}*/
const int MAXN=55;

int n,m;
char a[MAXN][MAXN];
void solve()
{
	int u[2]={0,0};
	readint(n),readint(m);
	for(int i=0;i<n;++i)
	{
		scanf("%s",a[i]);
		for(int j=0;j<m;++j)
			if(a[i][j]=='R')u[(i^j)&1]|=1;
			else if(a[i][j]=='W')u[(i^j)&1]|=2;
	}
	if(u[0]==3 || u[1]==3 || (u[0]&u[1])){printf("NO\n");return;}
	printf("YES\n");
	int w=(u[0]==2 || u[1]==1);
	const char *c="RW";
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			putchar(c[(i^j^w)&1]);
		putchar('\n');
	}
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