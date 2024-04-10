#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=800005;
const ll INF=1ll<<60;
typedef pair<ll,int> pli;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void exgcd(int a,int b,int &x,int &y)
{
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-(a/b)*y;
}

int n,m,stot,invn,invm;
vector<int> a[MAXN],b[MAXN],ta,tb;
map<int,int> ma,mb;
ll dis[MAXN];
bool hap[MAXN];
priority_queue<pli,vector<pli>,greater<pli> > pq;
struct Edge
{
	int v;
	ll c;
	Edge *next;
}pool[MAXN*3],*h[MAXN];
int etot=0;
inline void addEdge(int u,int v,ll c)
{
	Edge *p=&pool[++etot];
	p->v=v;p->c=c;p->next=h[u];h[u]=p;
}

void read(int d,vector<int> *a)
{
	int n,x;
	readint(n);
	while(n--)
	{
		readint(x);
		a[x%d].pb(x/d);
	}
}
int gma(int x){return ma.count(x)?ma[x]:ma[x]=++stot;}
int gmb(int x){return mb.count(x)?mb[x]:mb[x]=++stot;}
void dijkstra(int src)
{
	for(int i=1;i<=stot;++i)dis[i]=INF;
	dis[src]=0;
	pq.push(mp(0,src));
	while(!pq.empty())
	{
		pli pr=pq.top();pq.pop();
		int u=pr.y;
		if(pr.x>dis[u])continue;
		for(Edge *p=h[u];p;p=p->next)
			if(dis[p->v]>dis[u]+p->c)
			{
				dis[p->v]=dis[u]+p->c;
				pq.push(mp(dis[p->v],p->v));
			}
	}
}
ll solve(vector<int> a,vector<int> b)
{
	ma.clear();ta.clear();
	mb.clear();tb.clear();
	for(int i=1;i<=stot;++i)h[i]=NULL,hap[i]=0;
	stot=etot=0;
	int src=++stot;
	for(int i=0;i<a.size();++i)
	{
		int x=1ll*a[i]*invm%n;
		addEdge(src,gma(x),a[i]);
		addEdge(gma(x),gmb(1ll*a[i]*invn%m),0);
		hap[gma(x)]=1;
		ta.pb(x?x-1:n-1);
		tb.pb(1ll*a[i]*invn%m);
		tb.pb((1ll*a[i]*invn+m-1)%m);
		a[i]=x;
	}
	for(int i=0;i<b.size();++i)
	{
		int x=1ll*b[i]*invn%m;
		addEdge(src,gmb(x),b[i]);
		addEdge(gmb(x),gma(1ll*b[i]*invm%n),0);
		hap[gmb(x)]=1;
		tb.pb(x?x-1:m-1);
		ta.pb(1ll*b[i]*invm%n);
		ta.pb((1ll*b[i]*invm+n-1)%n);
		b[i]=x;
	}
	for(auto x:ta)a.pb(x);
	for(auto x:tb)b.pb(x);
	sort(a.begin(),a.end());
	auto edu=unique(a.begin(),a.end());
	a.erase(edu,a.end());
	sort(b.begin(),b.end());
	edu=unique(b.begin(),b.end());
	b.erase(edu,b.end());
	for(int i=1;i<a.size();++i)addEdge(gma(a[i-1]),gma(a[i]),1ll*(a[i]-a[i-1])*m);
	addEdge(gma(a.back()),gma(a[0]),1ll*(a[0]-a.back()+n)*m);
	for(int i=1;i<b.size();++i)addEdge(gmb(b[i-1]),gmb(b[i]),1ll*(b[i]-b[i-1])*n);
	addEdge(gmb(b.back()),gmb(b[0]),1ll*(b[0]-b.back()+m)*n);
	dijkstra(src);
/*for(auto x:a)cerr<<x<<":"<<gma(x)<<endl;cerr<<endl;
for(auto x:b)cerr<<x<<":"<<gmb(x)<<endl;cerr<<endl;
for(int i=1;i<=stot;++i)
{
	cerr<<i<<":";
	for(Edge *p=h[i];p;p=p->next)
		cerr<<"("<<p->v<<","<<p->c<<")";
	cerr<<endl;
}*/
	ll ans=-1;
	for(int i=2;i<=stot;++i)
		if(!hap[i])chkmax(ans,dis[i]);
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	int d=gcd(n,m);
	if(d>200000)return 0*printf("-1\n");
	read(d,a);
	read(d,b);
	for(int i=0;i<d;++i)
		if(!a[i].size() && !b[i].size())
			return 0*printf("-1\n");
	n/=d,m/=d;
	int temp;
	exgcd(n,m,invn,temp);
	if(invn<0)invn+=m;
	exgcd(n,m,temp,invm);
	if(invm<0)invm+=n;
	ll ans=0;
	for(int i=0;i<d;++i)
		chkmax(ans,solve(a[i],b[i])*d+i);
	printf("%lld\n",ans);
	return 0;
}