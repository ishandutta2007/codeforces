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

int n,a[MAXN],m,b[MAXN];
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	int p=0;
	for(int i=1;i<=n;++i)if(a[i]!=a[n-i+1]){p=i;break;}
	if(!p){printf("YES\n");return;}
	m=0;
	for(int i=1;i<=n;++i)if(a[i]!=a[p])b[++m]=a[i];
	bool fl=1;
	for(int i=1;i<=m;++i)if(b[i]!=b[m-i+1]){fl=0;break;}
	if(fl){printf("YES\n");return;}
	m=0;
	for(int i=1;i<=n;++i)if(a[i]!=a[n-p+1])b[++m]=a[i];
	fl=1;
	for(int i=1;i<=m;++i)if(b[i]!=b[m-i+1]){fl=0;break;}
	if(fl){printf("YES\n");return;}
	printf("NO\n");
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