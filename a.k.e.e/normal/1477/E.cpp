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
const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
inline int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=1000015,N=1000010;

int n,m;
int a[MAXN],b[MAXN];
struct Fenwick
{
	int c[MAXN];
	ll s[MAXN];
	multiset<int> t;
	void add(int x,int d)
	{
		if(d>0)t.insert(x);
		else t.erase(t.find(x));
		int e=d*x;
		++x;
		for(;x<=N;x+=(x&-x))c[x]+=d,s[x]+=e;
	}
	int qcnt(int x)
	{
		++x;
		int r=0;
		for(;x;x-=(x&-x))r+=c[x];
		return r;
	}
	ll qsum(int x)
	{
		++x;
		ll r=0;
		for(;x;x-=(x&-x))r+=s[x];
		return r;
	}
	int max(){return *(--t.end());}
	int min(){return *t.begin();}
};
Fenwick f,g;
ll solve(int x)
{
	if(g.t.empty())
	{
		chkmax(x,-f.min());
		return 1ll*x*f.qcnt(N)+f.qsum(N);
	}
	int t=g.max();
	chkmax(x,-t);
	int c=g.qcnt(N)-g.qcnt(max(-x,0)-1);
	ll s=g.qsum(N)-g.qsum(max(-x,0)-1);
	ll res=-(1ll*x*c+s);
	if(f.t.empty())return res;
	chkmax(x,-min(f.min(),g.min()));
	res+=1ll*x*f.qcnt(N)+f.qsum(N);
	return res;
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q;
	readint(n),readint(m),readint(Q);
	for(int i=1;i<=n;++i)readint(a[i]),f.add(a[i],1);
	for(int i=1;i<=m;++i)readint(b[i]),g.add(b[i],1);
	while(Q--)
	{
		int op,x;
		readint(op),readint(x);
		if(op==1)
		{
			f.add(a[x],-1);
			readint(a[x]);
			f.add(a[x],1);
		}
		else if(op==2)
		{
			g.add(b[x],-1);
			readint(b[x]);
			g.add(b[x],1);
		}
		else
		{
			ll res=solve(x-g.max());
			int t=f.min();
			f.add(t,-1);
			chkmax(res,solve(x-t)+x);
			f.add(t,1);
			if(f.t.size()>=2)
			{
				auto it=f.t.upper_bound(x+g.max());
				if(it==f.t.begin())++it;
				if(it==f.t.end())--it;
				t=*it;
				f.add(t,-1);
				chkmax(res,solve(x-t)+x);
				f.add(t,1);

				it=f.t.upper_bound(x+g.max());
				if(it==f.t.begin())++it;
				if(it!=f.t.begin())--it;
				t=*it;
				f.add(t,-1);
				chkmax(res,solve(x-t)+x);
				f.add(t,1);
			}
			t=g.min();
			g.add(t,-1);
			chkmax(res,solve(x-t)-x);
			g.add(t,1);
			printf("%lld\n",res);
		}
	}
	return 0;
}