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
/*const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
inline int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=2005;

int n;
void solve()
{
	vector<int> res;
	int p;
	readint(n);
	for(int i=2;i<=n;++i)
	{
		printf("? 1 %d\n",i-1);
		printf("%d\n",i);
		for(int j=1;j<i;++j)printf("%d ",j);putchar('\n');
		fflush(stdout);
		int x;
		readint(x);
		if(x){p=i;break;}
	}
	for(int i=p+1;i<=n;++i)
	{
		printf("? 1 1\n%d\n%d\n",p,i);
		fflush(stdout);
		int x;
		readint(x);
		if(!x)res.pb(i);
	}
	int L=1,R=p-2,mid,ans=1;
	while(L<=R)
	{
		mid=(L+R)>>1;
		printf("? 1 %d\n%d\n",mid,p);
		for(int i=1;i<=mid;++i)printf("%d ",i);putchar('\n');
		fflush(stdout);
		int x;
		readint(x);
		if(x)R=mid-1;
		else ans=L=mid+1;
	}
	for(int i=1;i<p;++i)if(i!=ans)res.pb(i);
	printf("! %d ",res.size());
	for(auto i:res)printf("%d ",i);
	putchar('\n');
	fflush(stdout);
}

int main()
{
	#ifdef LOCAL
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}