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
const int MAXN=2000005;

int n,a[MAXN],fa[MAXN];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
unordered_set<ll> r;

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	int Q;readint(Q);
	for(int i=0;i<MAXN;++i)fa[i]=i;
	for(int i=1;i<=n;++i)
	{
		readint(a[i]);int x,u;
		for(x=2,u=a[i];x*x<=u;++x)
		{
			if(u%x)continue;
			while(!(u%x))u/=x;
			fa[getfa(x+n)]=getfa(i);
		}
		if(u>1)fa[getfa(u+n)]=getfa(i);
	}
	for(int i=1;i<=n;++i)
	{
		vector<int> v;int x,u;
		v.pb(getfa(i));
		for(x=2,u=a[i]+1;x*x<=u;++x)
		{
			if(u%x)continue;
			while(!(u%x))u/=x;
			v.pb(getfa(x+n));
		}
		if(u>1)v.pb(getfa(u+n));
		sort(v.begin(),v.end());
		int k=unique(v.begin(),v.end())-v.begin();
		for(int x=0;x<k;++x)
			for(int y=x+1;y<k;++y)
				r.insert(1ll*v[x]*MAXN+v[y]);
	}
//for(int i=1;i<=n;++i)cerr<<getfa(i)<<endl;
//cerr<<"A"<<endl;
	while(Q--)
	{
		int u,v;readint(u),readint(v);
		u=getfa(u),v=getfa(v);
		if(u>v)swap(u,v);
		if(u==v)printf("0\n");
		else if(r.count(1ll*u*MAXN+v))printf("1\n");
		else printf("2\n");
	}
	return 0;
}