#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=300005;

int n,m;
int a[MAXN];
ll b[MAXN];
void solve()
{
	readint(n),readint(m);
	for(int i=1;i<=n;++i)readint(a[i]);
	for(int i=1;i<=m;++i)readint(b[i]);
	sort(a+1,a+n+1);
	int c=m,cnt=0;
	for(int i=n;i;--i)
	{
		chkmin(c,a[i]);
		--c;
		++cnt;
		if(!c)break;
	}
	while(cnt>n || (cnt && b[cnt]>=b[a[n-cnt+1]]))--cnt;
	ll sum=0;
	for(int i=1;i<=n-cnt;++i)sum+=b[a[i]];
	for(int i=1;i<=cnt;++i)sum+=b[i];
	printf("%lld\n",sum);
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