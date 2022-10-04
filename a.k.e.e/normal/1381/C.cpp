#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
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

int n,x,y,a[MAXN],la;
vector<int> b[MAXN];
struct CMP
{
	bool operator ()(pii p,pii q)const
	{
		if(p.x!=q.x)return p.x<q.x;
		if(p.y!=la && q.y==la)return 1;
		if(p.y==la && q.y!=la)return 0;
		if(p.y!=q.y)return p.y<q.y;
		return 0;
	}
};
priority_queue<pii,vector<pii>,less<pii> > pq;
priority_queue<pii,vector<pii>,CMP> tpq;
int res[MAXN];
void solve()
{
	readint(n),readint(x),readint(y);
	for(int i=1;i<=n;++i)readint(a[i]);
	for(int i=1;i<=2*n+2;++i)b[i].clear();
	while(!pq.empty())pq.pop();
	while(!tpq.empty())tpq.pop();
	for(int i=1;i<=n;++i)b[a[i]].pb(i);
	int nc=0;
	for(int i=1;i<=n+1;++i)
		if(b[i].empty())nc=i;
		else pq.push(mp(b[i].size(),i));
	if(x==y)
	{
		printf("YES\n");
		for(int i=1;i<=n;++i)printf("%d ",i<=x?a[i]:nc);
		return;
	}
	for(int i=1;i<=x;++i)
	{
		pii p=pq.top();pq.pop();
		res[b[p.y].back()]=a[b[p.y].back()];
		b[p.y].pop_back();
		if(p.x>1)pq.push(mp(p.x-1,p.y));
	}
//for(int i=1;i<=n;++i)cerr<<res[i]<<" ";cerr<<endl;
	int c=0,u=0,l;
	pii p=pq.top(),q;pq.pop();
	c=p.y,u=b[p.y].back();
	b[p.y].pop_back();
	if(p.x>1)pq.push(mp(p.x-1,p.y));
	l=u;la=a[u];
	while(!pq.empty())tpq.push(pq.top()),pq.pop();
	for(int i=1;i<n-x;++i)
	{
		q=mp(0,0);p=tpq.top();tpq.pop();
		if(p.y==a[l] && !tpq.empty())q=p,p=tpq.top(),tpq.pop();
//cerr<<l<<" "<<b[p.y].back()<<endl;
		res[l]=a[b[p.y].back()];
		l=b[p.y].back();
		b[p.y].pop_back();
		if(p.x>1)tpq.push(mp(p.x-1,p.y));
		if(q!=mp(0,0))tpq.push(q);
	}
	res[l]=a[u];
//cerr<<l<<" "<<u<<endl;
//for(int i=1;i<=n;++i)cerr<<res[i]<<" ";cerr<<endl;
	int rem=n-y,ned=0;
	for(int i=1;i<=n;++i)if(res[i]==a[i])++ned;
	ned-=x;
	if(ned>rem){printf("NO\n");return;}
	for(int i=1;i<=n && ned;++i)
		if(res[i]==a[i])
			--rem,--ned,res[i]=nc;
	for(int i=1;i<=n && rem;++i)
		if(res[i]!=nc && res[i]!=a[i])
			--rem,res[i]=nc;
	printf("YES\n");
	for(int i=1;i<=n;++i)printf("%d ",res[i]>n+1?nc:res[i]);
	putchar('\n');
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}