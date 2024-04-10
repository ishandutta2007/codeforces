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
/*const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=300005,B=700,S=700;

int n,m,a[MAXN];
bool vis[S+5];
struct BIOS
{
	ll val[MAXN],tag[S+5];
	void init(int m)
	{
		memset(val,0,sizeof(ll)*(m+5));
		memset(tag,0,sizeof(tag));
	}
	void add(int x,int y)
	{
		for(int i=x;i/B==x/B && i<=m;++i)val[i]+=y;
		for(int i=x/B+1;i<=m/B;++i)tag[i]+=y;
	}
	ll qval(int x){return val[x]+tag[x/B];}
	ll qsum(int l,int r)
	{
		return qval(r)-qval(l-1);
	}
};
BIOS v0,v1;
void solve()
{
	readint(n);m=0;
	for(int i=1;i<=n;++i)readint(a[i]),chkmax(m,a[i]);
	v0.init(m);v1.init(m);
	memset(vis,0,sizeof(bool)*(B+5));
	ll res=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]<=B)
		{
			for(int j=1;j<i;++j)
				res+=a[i]%a[j]+a[j]%a[i];
			vis[a[i]]=1;
		}
		else
		{
			for(int j=1;j<=B;++j)if(vis[j])res+=a[i]%j+j;
			for(int l=B+1,r;l<=a[i];l=r+1)
			{
				r=a[i]/(a[i]/l);
				res+=a[i]*v0.qsum(l,r)-(a[i]/l)*v1.qsum(l,r);
			}
			res+=a[i]*v0.qsum(a[i]+1,m);
			for(int x=a[i];x<=m;x+=a[i])
			{
				int l=x,r=min(x+a[i]-1,m);
				res+=v1.qsum(l,r)-(x/a[i])*v0.qsum(l,r)*a[i];
			}
			res+=v1.qsum(1,a[i]-1);
			v1.add(a[i],a[i]);
			v0.add(a[i],1);
		}
		cout<<res<<' ';
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	solve();
/*	int T;
	readint(T);
	while(T--)solve();*/
	return 0;
}