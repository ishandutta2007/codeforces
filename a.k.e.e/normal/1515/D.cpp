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
const int MAXN=200005;

int n,l,r,a[MAXN];
void solve()
{
	readint(n),readint(l),readint(r);
	for(int i=1;i<=n;++i)a[i]=0;
	for(int i=1;i<=n;++i)
	{
		int x;
		readint(x);
		if(i<=l)++a[x];
		else --a[x];
	}
	int ans=0,e[2]={0,0},o[2]={0,0};
	for(int i=1;i<=n;++i)
	{
		if(!a[i])continue;
		int x=abs(a[i]),y=(a[i]>0);
		e[y]+=x/2,o[y]+=x%2;
	}
	if(o[0]<o[1])swap(o[0],o[1]),swap(e[0],e[1]);
	ans+=o[1];o[0]-=o[1];o[1]=0;
	int t=min(e[1],o[0]/2);
	ans+=t*2;e[1]-=t;o[0]-=2*t;
	ans+=e[0]+e[1]+o[0];
	printf("%d\n",ans);
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