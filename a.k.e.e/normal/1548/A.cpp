#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
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
const int MAXN=200005;

int n,res;
int cnt[MAXN];
void ins(int u,int v)
{
	res-=!cnt[u];
	cnt[u]+=(v>u);
	res+=!cnt[u];
}
void era(int u,int v)
{
	res-=!cnt[u];
	cnt[u]-=(v>u);
	res+=!cnt[u];
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E;readint(n),readint(E);
	res=n;
	while(E--)
	{
		int u,v;
		readint(u),readint(v);
		ins(u,v),ins(v,u);
	}
	int Q;readint(Q);
	while(Q--)
	{
		int op,u,v;readint(op);
		if(op==1)readint(u),readint(v),ins(u,v),ins(v,u);
		else if(op==2)readint(u),readint(v),era(u,v),era(v,u);
		else printf("%d\n",res);
	}
	return 0;
}