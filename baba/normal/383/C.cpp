//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef unsigned long long int ULL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define DRT() int t; si(t); while(t--)

#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(2e5) + 10;
int ST[4*N];
int baseArray[N];

int pos[N];
int chainNo[N];
int chainHead[N];
int chainParent[N];
int chainTail[N];
int nchain;
int lenBA;

VI tree[N];
int val[N];
int subsize[N];
int level[N];
int root = 0;

void HLD(int u,int p)
{
	pos[u] = lenBA++;
	chainNo[u] = nchain;

	int sc = -1,mx = 0;
	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(w == p)continue;
		if(subsize[w] > mx)
		{
			mx = subsize[w];
			sc = w;
		}
	}
	if(sc == -1)
		chainTail[nchain] = u;
	else
		HLD(sc,u);
	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(w == p || w == sc)continue;
		nchain++;
		chainParent[nchain] = u;
		chainHead[nchain] = w;
		HLD(w,u);
	}
}

void dfs(int u,int p)
{
	subsize[u]=1;
	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(w!=p)
		{
			level[w] = level[u] + 1;
			dfs(w,u);
			subsize[u] += subsize[w];
		}
	}
}

void point_update(int pos,int val,int node = 1,int l = 0,int r = lenBA)
{
	if(pos < l || pos >= r)
		return;
	if(l == r-1 && l == pos)
	{
		//Operation of point update
		ST[node] += val;
		return;
	}
	int lc = 2*node;
	int rc = 2*node + 1;
	int mid = (l+r)>>1;
	point_update(pos,val,lc,l,mid);
	point_update(pos,val,rc,mid,r);
	//Operation of segment tree
	ST[node] = ST[lc] + ST[rc];
}
int range_query(int L,int R,int node = 1,int l = 0,int r = lenBA)
{
	if(L>=r || R<=l)
		return 0; //Nothing here :)
	if(L<=l && r<=R)
		return ST[node];
	int lc = 2*node;
	int rc = 2*node + 1;
	int mid = (l+r)>>1;
	int left = range_query(L,R,lc,l,mid);
	int right = range_query(L,R,rc,mid,r);
	
	//Operation of segment tree
	return left + right;
}

void processTree()
{
	//DFS
	level[root] = 0;
	dfs(root,root);

	//HLD
	nchain = 0;
	lenBA = 0;
	chainParent[nchain] = root;
	chainHead[nchain] = root;
	HLD(root,root);
	//Segment Tree
	SET(ST,0);	//No need to build explicitly :)
}
void update(int node,int add)
{
	int tail = chainTail[chainNo[node]];
	if((level[tail] - level[node]) & 1) add = -add;	
	//if distance between chainEnd and currnode is odd it will contribute -ve to the chain assuming that distance on reaching the last node is even
	
	point_update(pos[node],add);
}


int query(int node)
{
	int ret = val[node];
	int len = 0;
	while(chainHead[chainNo[node]]!=root)
	{
		int l = pos[chainHead[chainNo[node]]];
		int r = pos[node];
		int add = range_query(l,r+1);
		int tail = chainTail[chainNo[node]];
//		trace4(node+1,chainNo[node],tail,add);
		if((((level[tail] - level[node]) & 1) && len%2==0) || ((level[tail] - level[node])%2 == 0 && len&1))
			add = -add;
		ret += add;
		len += level[node] - level[chainParent[chainNo[node]]];
		node = chainParent[chainNo[node]];
	}
	int add = range_query(pos[root],pos[node]+1);
	int tail = chainTail[chainNo[node]];
	if((((level[tail] - level[node]) & 1) && len%2==0) || ((level[tail] - level[node])%2 == 0 && len&1))
		add = -add;
//	trace4(node+1,chainNo[node],tail,add);
	ret+=add;
	return ret;
}
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=0;i<n;i++)
		si(val[i]);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		si(u);si(v);
		tree[u-1].PB(v-1);
		tree[v-1].PB(u-1);
	}
	processTree();
	while(m--)
	{
		int type;
		si(type);
		if(type==1)
		{
			int x,val;
			si(x);si(val);
			update(x-1,val);
		}
		else
		{
			int x;
			si(x);
			dout(query(x-1));
		}
	}

	return 0;
}