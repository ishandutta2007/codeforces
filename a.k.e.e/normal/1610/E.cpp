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

int n,a[MAXN],las[MAXN];
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	las[1]=1;for(int i=2;i<=n;++i)las[i]=(a[i]==a[i-1]?las[i-1]:i);
	int res=1;
	for(int i=1;i<n;++i)
	{
		int cnt=0,x=n;
		for(x=n;a[x]>a[i];)
		{
			++cnt;
			x=upper_bound(a+i,a+x,(a[i]+a[x])/2)-a-1;
		}
		cnt+=x-i+1;
		chkmax(res,cnt);
	}
	printf("%d\n",n-res);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;readint(T);
	while(T--)solve();
	return 0;
}