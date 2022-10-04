#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=100005;
struct Frac
{
	ll x,y;
	static ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
	Frac(){}
	Frac(ll a,ll b)
	{
		ll d=gcd(a,b);
		x=a/d;y=b/d;
	}
	bool operator <(const Frac &b)const{return x*b.y<y*b.x;}
};
typedef pair<Frac,int> pdi;

int n,m,k,op[MAXN],id[MAXN];
ll a[MAXN];
priority_queue<pdi> pq;
vector<pii> add[MAXN],mul;
pii chg[MAXN];
int res[MAXN];
inline bool cmp(int x,int y){return op[x]<op[y];}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int x,y,sum=0;
	readint(n),readint(m),readint(k);
	for(int i=1;i<=n;++i)readint(a[i]);
	for(int i=1;i<=m;++i)
	{
		readint(op[i]),readint(x),readint(y);
		id[i]=x;
		if(op[i]==1)chkmax(chg[x],mp((int)(y-a[x]),i));
		else if(op[i]==2)add[x].pb(mp(y,i));
		else mul.pb(mp(y,i));
	}
	for(int i=1;i<=n;++i)
	{
		if(chg[i].y)add[i].pb(chg[i]);
		if(!add[i].empty())
		{
			sort(add[i].begin(),add[i].end());
			sum+=add[i].size();
			pii p=add[i].back();add[i].pop_back();
			pq.push(mp(Frac(p.x,a[i]),p.y));
		}
	}
	for(auto p:mul)pq.push(mp(Frac(p.x-1,1),p.y));
	sum+=mul.size();
	chkmin(k,sum);
	for(int i=1;i<=k;++i)
	{
		pdi u=pq.top();pq.pop();
		res[i]=u.y;
		int x=id[u.y];
		if(op[u.y]<=2)
		{
			a[x]=a[x]/u.x.y*(u.x.x+u.x.y);
			if(add[x].empty())continue;
			pii p=add[x].back();add[x].pop_back();
			pq.push(mp(Frac(p.x,a[x]),p.y));
		}
	}
	sort(res+1,res+k+1,cmp);
	printf("%d\n",k);
	for(int i=1;i<=k;++i)printf("%d ",res[i]);
	return 0;
}