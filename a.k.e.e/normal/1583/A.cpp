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
/*const int MOD=
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=205;

int n,a[MAXN];
void solve()
{
	readint(n);int s=0;
	for(int i=1;i<=n;++i)readint(a[i]),s+=a[i];
	bool fl=0;
	for(int j=2;j*j<=s;++j)if(!(s%j)){fl=1;break;}
	if(fl)
	{
		printf("%d\n",n);
		for(int i=1;i<=n;++i)printf("%d ",i);
		putchar('\n');
	}
	else
	{
		printf("%d\n",n-1);
		int t=0;
		for(int i=1;i<=n;++i)if(a[i]&1)t=i;
		for(int i=1;i<=n;++i)if(i!=t)printf("%d ",i);
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