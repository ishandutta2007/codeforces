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
const int MAXN=1000005;

int n;
int a[MAXN];
void solve()
{
	int T;readint(T),readint(n);
	memset(a,0,sizeof(int)*(n+3));
	for(int x;T;--T)readint(x),a[x]=1;
	for(int i=1;i<=n;++i)a[i]+=a[i-1];
	for(int i=1;i<=n;++i)
	{
		if(a[i]==a[i-1])continue;
		for(int j=i;j<=n;j+=i)
			if(a[min(j+i-1,n)]>a[j-1] && a[j/i]==a[j/i-1])
				{printf("No\n");return;}
	}
	printf("Yes\n");
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