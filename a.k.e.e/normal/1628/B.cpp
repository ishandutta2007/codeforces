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
const int MAXN=100005;

int n;
char a[MAXN][5];
int f[MAXN],g[MAXN];
bool vis[26*26*26];
bool work()
{
	readint(n);
	for(int i=1;i<=n;++i)scanf("%s",a[i]);
	for(int x=2;x<=3;++x)for(int y=2;y<=3;++y)
	{
		for(int i=1;i<=n;++i)
		{
			int len=strlen(a[i]);
			if(len==1)return 1;
			if(a[i][0]==a[i][len-1])return 1;
			if(len==x)f[i]=(a[i][0]-'a')+(a[i][1]-'a')*26;
			else f[i]=-1;
			if(len==y)g[i]=(a[i][len-1]-'a')+(a[i][len-2]-'a')*26;
			else g[i]=-1;
			if(x==3&&y==3&&len==3)
				f[i]+=(a[i][2]-'a')*26*26,g[i]+=(a[i][0]-'a')*26*26;
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i)
		{
			if(g[i]>=0&&vis[g[i]])return 1;
			if(f[i]>=0)vis[f[i]]=1;
		}
	}
	return 0;
}
void solve()
{
	printf(work()?"YES\n":"NO\n");
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