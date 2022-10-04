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
//const int MAXN=;

int n;
ll ask(int l,int r)
{
	printf("? %d %d\n",l,r);fflush(stdout);
	ll x;readint(x);
	return x;
}
void solve()
{
	readint(n);
	int l=1,r=n,mid,s=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(ask(1,mid))r=mid-1;
		else l=mid+1,s=mid;
	}
	int t=ask(s,n)-ask(s+1,n);
	t+=s+1;
	int z=ask(t,n)-ask(t+1,n);
	z+=t;
	printf("! %d %d %d\n",s,t,z);fflush(stdout);
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