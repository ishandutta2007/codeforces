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
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=1019260817;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=300005;

int n,a[MAXN];
multiset<int> s;
int res[MAXN];
void solve()
{
	s.clear();
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]),s.insert(a[i]),res[i]=0;
	int l=1,r=n;
	for(int i=1;i<=n;++i)
	{
		if(*s.begin()!=i)break;
		res[i]=1;
		s.erase(s.find(i));
		if(a[l]!=i && a[r]!=i)break;
		if(a[l]==i && a[r]==i)break;
		if(a[l]==i)++l;
		else --r;
	}
	sort(a+1,a+n+1);
	bool flag=1;
	for(int i=1;i<=n;++i)if(a[i]!=i){flag=0;break;}
	putchar(flag?'1':'0');
	for(int i=n-1;i>=1;--i)putchar(res[i]+'0');
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