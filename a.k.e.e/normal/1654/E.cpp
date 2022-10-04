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
const int MAXN=100005,B=505,S=205,M=MAXN*(S+5);

int n,a[MAXN],p[MAXN];
int cnt[MAXN*(S+5)*2],vis[MAXN*(S+5)*2],timer;
int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
	#endif
	int res=0;
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	for(int i=1;i<=n;++i)
	{
		++timer;
		for(int j=max(i-B,1);j<=min(i+B,n);++j)
			if(j!=i && (a[j]-a[i])%(j-i)==0)
			{
				int d=(a[j]-a[i])/(j-i)+M;
				if(vis[d]!=timer)vis[d]=timer,cnt[d]=0;
				++cnt[d];
				chkmax(res,cnt[d]+1);
			}
	}
	for(int i=-S;i<=S;++i)
	{
		++timer;
		for(int j=1;j<=n;++j)
		{
			int d=a[j]+i*j+M;
			if(vis[d]!=timer)vis[d]=timer,cnt[d]=0;
			++cnt[d];
			chkmax(res,cnt[d]);
		}
	}
	printf("%d\n",n-res);
	return 0;
}