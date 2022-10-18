//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(4e5)+10;
VI g[N];
int Start[N],End[N],A[N],len;
LL ST[4*N],E[N],lazy[4*N];
void setBit(LL &mask,int i)
{
	mask = mask | (1ll<<(i-1));
}
void dfs(int u,int p)
{
	Start[u]=++len;setBit(E[len],A[u]);
	for(int i=0;i<SZ(g[u]);i++)
		if(g[u][i]!=p)
			dfs(g[u][i],u);
	End[u]=len;
}
#define lc (x<<1)
#define rc (x<<1)|1
void up(int x)
{
	ST[x]=ST[lc]|ST[rc];
}
void push(int l,int r,int x)
{
	if(!lazy[x])return;
	ST[x]=lazy[x];
	if(l==r-1)return void(lazy[x]=0);
	lazy[lc]=lazy[rc]=lazy[x];
	lazy[x]=0;
}
void build(int l=0,int r=len,int x=1)
{
	if(l==r-1)return void(ST[x]=E[l]);
	int m=(l+r)/2;
	build(l,m,lc);
	build(m,r,rc);
	up(x);
}
void update(int L,int R,int c,int l=0,int r=len,int x=1)
{
	push(l,r,x);
	if(r<=L || R<=l)return;
	if(l>=L && r<=R)
	{
		lazy[x]=0;
		setBit(lazy[x],c);
		push(l,r,x);
		return;
	}
	int m = (l+r)/2;
	update(L,R,c,l,m,lc);
	update(L,R,c,m,r,rc);
	up(x);
}
LL query(int L,int R,int l=0,int r=len,int x=1)
{
	push(l,r,x);
	if(r<=L || R<=l)return 0;
	if(l>=L && r<=R)return ST[x];
	int m = (l+r)/2;
	return query(L,R,l,m,lc) | query(L,R,m,r,rc);
}
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=1;i<=n;i++)
		si(A[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		si(u);si(v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,1);len++;
	build();
	while(m--)
	{
		int t;si(t);
		if(t==1)
		{
			int v,c;
			si(v);si(c);
			update(Start[v],End[v]+1,c);
		}
		else
		{
			int v;si(v);
			dout(__builtin_popcountll(query(Start[v],End[v]+1)));
		}
	}
	return 0;
}