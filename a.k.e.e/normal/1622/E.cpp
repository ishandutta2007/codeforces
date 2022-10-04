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
const int MAXN=11,MAXM=10005;

int n,m,a[MAXN];
char s[MAXN][MAXM];
int c[MAXM],p[MAXM],fin[MAXM];
void solve()
{
	readint(n),readint(m);
	for(int i=0;i<n;++i)readint(a[i]);
	for(int i=0;i<n;++i)scanf("%s",s[i]+1);
	for(int j=1;j<=m;++j)p[j]=j;
	ll res=0;
	for(int u=0;u<(1<<n);++u)
	{
		memset(c,0,sizeof(c));
		ll sum=0;
		for(int i=0;i<n;++i)
		{
			int w=(u&(1<<i))?1:-1;
			sum-=w*a[i];
			for(int j=1;j<=m;++j)
				if(s[i][j]=='1')c[j]+=w;
		}
		sort(p+1,p+m+1,[&](int x,int y){return c[x]<c[y];});
		for(int i=1;i<=m;++i)
			sum+=c[p[i]]*i;
		if(sum>=res)
		{
			res=sum;
			for(int j=1;j<=m;++j)fin[p[j]]=j;
		}
	}
	for(int j=1;j<=m;++j)printf("%d ",fin[j]);
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