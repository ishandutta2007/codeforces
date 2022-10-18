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
const int N = int(1e5)+10;
const int LOGN = 20;
const int INF = int(2e9);
VI tree[N];
int DP[N][LOGN];
int root;
int visited[N];
int n,m;
int level[N];
//For segment tree
VII ST[4*N];
int baseArray[N];
int posInBaseArray[N];
int lenBA;
//For HLD
int numChain[N];
int chainHead[N];
int chainParent[N];
int sizeSubtree[N];
int chainNo;

/*Implementation using FAT-NODE method of persistence :D */

void dfs(int u)
{
	visited[u]=1;
	sizeSubtree[u]=1;
	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(!visited[w])
		{
			level[w]=level[u]+1;
			dfs(w);
			sizeSubtree[u]+=sizeSubtree[w];
		}
	}
}


void HLD(int u)
{
	visited[u]=1;
	
	numChain[u]=chainNo;
	posInBaseArray[u]=lenBA;
	baseArray[lenBA++]=u;

	int sc = -1;
	int mx = -INF;
	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(!visited[w] && sizeSubtree[w]>mx)
		{
			sc = w;
			mx = sizeSubtree[w];
		}
	}
	
	//Expand the current chain on special child
	if(sc!=-1)
		HLD(sc);
	//Begin New chains at normal child
	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(!visited[w])
		{
			chainNo++;
			chainHead[chainNo]=w;
			chainParent[chainNo]=u;
			HLD(w);
		}
	}
}


void build_ST(int node=1,int l=0,int r=lenBA)
{
	if(l==r-1)
	{
		ST[node].PB(MP(0,0));
		return;
	}

	int leftChild = node<<1;
	int rightChild = leftChild | 1;
	int mid = (l+r)>>1;

	build_ST(leftChild,l,mid);
	build_ST(rightChild,mid,r);
	int la = ST[leftChild][0].S;
	int ra = ST[rightChild][0].S;
	ST[node].PB(MP(0,la+ra));

}

void update_ST(int pos,int val,int year,int node=1,int l=0,int r = lenBA)
{
	if(l==pos && l==r-1)
	{
		ST[node].PB(MP(year,val));
		return;
	}

	int leftChild = node<<1;
	int rightChild = leftChild | 1;
	int mid = (l+r)>>1;

	if(pos<mid)
		update_ST(pos,val,year,leftChild,l,mid);
	else
		update_ST(pos,val,year,rightChild,mid,r);

	int lc = SZ(ST[leftChild])-1;
	int rc = SZ(ST[rightChild])-1;
	ST[node].PB(MP(year,ST[leftChild][lc].S + ST[rightChild][rc].S));
}

int query_ST_ok(int L,int R,int year,int node=1,int l=0,int r=lenBA)	//number of castles ok in [L,R) from (year,present]
{
	if(L<=l && r<=R)
	{
		VII &A = ST[node];
		int l = 0,h = SZ(A)-1;
		int ans;
		while(l<h-1)
		{
			int m = (l+h)>>1;
			if(A[m].F <= year)
				l = m;
			else if(A[m].F > year)
				h = m-1;
		}
		if(A[h].F<=year)
			ans = h;
		else
			ans = l;
		int destroyed = A[SZ(A)-1].S - A[ans].S;
		int total = (r-l);
		return total-destroyed;
	}
	if(l>=R || r<=L)
		return 0;

	int leftChild = node<<1;
	int rightChild = leftChild | 1;
	int mid = (l+r)>>1;

	int leftAns = query_ST_ok(L,R,year,leftChild,l,mid);
	int rightAns = query_ST_ok(L,R,year,rightChild,mid,r);

	return leftAns + rightAns;
}

II query_ST_ans_left(int L,int R,int K,int year,int node=1,int l=0,int r=lenBA)
{
	if(l>=R || r<=L)
		return MP(0,-1);
	II la,ra;
	if(L<=l && r<=R)
	{
		VII &A = ST[node];
		int low = 0,high = SZ(A)-1;
		int ans;
		while(low<high-1)
		{
			int mid = (low+high)>>1;
			if(A[mid].F <= year)
				low = mid;
			else if(A[mid].F > year)
				high = mid-1;
		}
		if(A[high].F<=year)
			ans = high;
		else
			ans = low;
		int destroyed = A[SZ(A)-1].S - A[ans].S;
		int total = r-l;
		int n = total-destroyed;
		if(n<K) return MP(n,-1);
		if(l==r-1)
			return MP(n,l);
		int lc = node<<1;
		int rc = lc|1;
		int mid = (l+r)>>1;
		la = query_ST_ans_left(L,R,K,year,lc,l,mid);
		if(la.S!=-1)
			return la;
		return query_ST_ans_left(L,R,K-la.F,year,rc,mid,r);
	}
	int lc = node<<1;
	int rc = lc|1;
	int mid = (l+r)>>1;

	la = query_ST_ans_left(L,R,K,year,lc,l,mid);
	if(la.S!=-1)
		return la;
	ra = query_ST_ans_left(L,R,K-la.F,year,rc,mid,r);
	if(ra.S!=-1)
		return ra;
	return MP(la.F + ra.F,-1);
}
II query_ST_ans_right(int L,int R,int K,int year,int node=1,int l=0,int r=lenBA)
{
	//trace4(L,R,l,r);
	if(l>=R || r<=L)
		return MP(0,-1);
	II la,ra;
	if(L<=l && r<=R)
	{
		VII &A = ST[node];
		int low = 0,high = SZ(A)-1;
		int ans;
		while(low<high-1)
		{
			int mid = (low+high)>>1;
			if(A[mid].F <= year)
				low = mid;
			else if(A[mid].F > year)
				high = mid-1;
		}
		if(A[high].F<=year)
			ans = high;
		else
			ans = low;
		int destroyed = A[SZ(A)-1].S - A[ans].S;
		int total = r-l;
		int n = total-destroyed;
		if(n<K) return MP(n,-1);
		if(l==r-1)
			return MP(n,l);
		int lc = node<<1;
		int rc = lc|1;
		int mid = (l+r)>>1;
		ra = query_ST_ans_right(L,R,K,year,rc,mid,r);
		if(ra.S!=-1)
			return ra;
		return query_ST_ans_right(L,R,K-ra.F,year,lc,l,mid);
	}
	int lc = node<<1;
	int rc = lc|1;
	int mid = (l+r)>>1;

	ra = query_ST_ans_right(L,R,K,year,rc,mid,r);
	if(ra.S!=-1)
		return ra;
	la = query_ST_ans_right(L,R,K-ra.F,year,lc,l,mid);
	if(la.S!=-1)
		return la;
	return MP(la.F + ra.F,-1);
}
int a,b,k,y;
int query_up_ans(int u,int p,int year,int& k)
{
	II ret;
	if(u == DP[u][0])
		return -1;
	u = DP[u][0];
	while(numChain[u]!=numChain[p])
	{
		ret = query_ST_ans_right(posInBaseArray[chainHead[numChain[u]]],posInBaseArray[u]+1,k,year);
		if(ret.S !=-1)
			return ret.S; //answer found.
		u = chainParent[numChain[u]];
		k-=ret.F;
	}
	ret = query_ST_ans_right(posInBaseArray[p] + (p==b?1:0) ,posInBaseArray[u]+1,k,year);
	if(ret.S!=-1) //answer found.
	 	return ret.S;
	k-=ret.F;
	return -1;
}
int query_down_ans(int p,int v,int year,int &k)
{
	II ret; 
	if(v == DP[v][0])
		return -1;
	v = DP[v][0];
	stack<II> Q;
	while(numChain[v]!=numChain[p])
	{
		Q.push(MP(posInBaseArray[chainHead[numChain[v]]],posInBaseArray[v]+1));
		v = chainParent[numChain[v]];
	}
	Q.push(MP(posInBaseArray[p] + 1 , posInBaseArray[v]+1)); 
	while(!Q.empty())
	{
		int l = Q.top().F, r = Q.top().S;
		Q.pop();
		ret = query_ST_ans_left(l,r,k,year);
		if(ret.S!=-1)
			return ret.S;
		k-=ret.F;
	}
	return -1;
}

int lca(int a,int b)
{
	if(level[a]>level[b])
		swap(a,b);

	int d = level[b]-level[a];
	for(int i=0;(1<<i)<=d;i++)
		if(d&(1<<i))
			b = DP[b][i];
	
	if(a==b)
		return a;

	int msb=0;
	for(int i=0;DP[a][i]!=DP[b][i];i++)
		msb = i;
	
	for(int i=msb;i>=0;i--)
		if(DP[a][i]!=DP[b][i])
		{
			a = DP[a][i];
			b = DP[b][i];
		}

	return DP[a][0];
}

void processTree()
{
	//dfs
	SET(visited,0);
	level[root]=0;
	dfs(root);
	
	//HLD
	SET(visited,0);
	chainNo=0;
	lenBA=0;
	chainHead[chainNo]=root;
	chainParent[chainNo]=root;
	HLD(root);

	//Segment tree
	build_ST();
	
	//LCA
	for(int i=1;i<LOGN;i++)
		for(int j=0;j<n;j++)
			DP[j][i] = DP[DP[j][i-1]][i-1];
}


int main()
{
	si(n);
	for(int i=0;i<n;i++)
	{
		int v;
		si(v);
		if(v==0)
		{
			root=i;
			DP[root][0]=root;
		}
		else
		{
			tree[v-1].PB(i);
			tree[i].PB(v-1);
			DP[i][0]=v-1;
		}
	}
	processTree();
	si(m);
	for(int year=1;year<=m;year++)
	{
		int t;si(t);
		if(t==1)
		{
			int c;
			si(c);c--;
			update_ST(posInBaseArray[c],1,year);
		}
		else
		{
			scanf("%d %d %d %d",&a,&b,&k,&y);
			a--;b--;
			int LCA = lca(a,b);
			//trace3(a+1,b+1,LCA+1);
			if(LCA == a)
			{
				int ans = query_down_ans(a,b,y,k);
				if(ans==-1)
					dout(ans);
				else
					dout(baseArray[ans]+1);
				continue;
			}
			if(LCA == b)
			{
				int ans = query_up_ans(a,b,y,k);
				if(ans==-1)
					dout(ans);
				else
					dout(baseArray[ans]+1);
				continue;
			}
			int up = query_up_ans(a,LCA,y,k); 	
			if(up!=-1)
			{
				dout(baseArray[up]+1);
				continue;
			}
			int down = query_down_ans(LCA,b,y,k);
			if(down!=-1)
			{
				dout(baseArray[down]+1);
				continue;
			}
			dout(-1);
		}
	}
	return 0;
}