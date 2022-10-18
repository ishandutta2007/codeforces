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
class segment_tree{
	private:
		vector<LL> ST;
		vector<LL> A;	//base array
		vector<LL> lazy;	
		int n;
		void build(int node,int l,int r)
		{
			if(l==r-1)
			{
				ST[node]=A[l];
				return;
			}
			int leftChild = node<<1;
			int rightChild = leftChild | 1;
			int mid = (l+r)>>1;
			
			build(leftChild,l,mid);
			build(rightChild,mid,r);

			//Operation of segment tree
			ST[node] = (ST[leftChild] + ST[rightChild]);
		}
		int range_query(int L,int R,int node,int l,int r)
		{
			if(l>=R || r<=L)
			//Depending on your operation return a value which indicates that there's nothing here
				return 0;
			int lc = node<<1;
			int rc = lc|1;
			if(lazy[node]!=0ll)
			{
				//Operation of range_update
				ST[node]=((r-l)*lazy[node]); 	
				
				if(l!=r-1)
				{
					lazy[lc]=lazy[node];
					lazy[rc]=lazy[node];
				}
				lazy[node]=0ll;
			}
			if(L<=l && r<=R)
				return ST[node];
			int mid = (l+r)>>1;
			LL leftAns = range_query(L,R,lc,l,mid);
			LL rightAns = range_query(L,R,rc,mid,r);
			//Operation of segment tree
			return (leftAns+rightAns);
		}
		void range_reset(int L,int R,LL val,int node,int l,int r)
		{
			int lc = node<<1;
			int rc = lc | 1;	
			if(lazy[node]!=0ll)
			{
				//Operation of range_update
				ST[node]=((r-l)*lazy[node]); 	
				if(l!=r-1)
				{
					lazy[lc]=lazy[node];
					lazy[rc]=lazy[node];
				}
				lazy[node]=0ll;
			}
			if(l>=R || r<=L)	//Segment out of range
				return ;
			if(L<=l && r<=R)	//Segment completely within range
			{
				//Operation of range_update
				ST[node]=((r-l)*val);
				if(l!=r-1)
				{
					lazy[lc]=val;
					lazy[rc]=val;
				}
				return;
			}
			int mid = (l+r)>>1;
			range_reset(L,R,val,lc,l,mid);
			range_reset(L,R,val,rc,mid,r);
			//Operation of segment tree
			ST[node] = (ST[lc]+ST[rc]);

		}
	public:
		segment_tree(){ST.clear();A.clear();n=0;lazy.clear();}
		segment_tree(int *begin,int *end)	//construct using an array
		{
			A = vector<LL>(begin,end);
			n = SZ(A);
			ST = vector<LL>(4*n,0);
			lazy = vector<LL>(4*n,0);
			build(1,0,n);
		}
		//returns [L,R)
		int query(int x)
		{
			return range_query(x,x+1,1,0,n);
		}
		void update(int L,int R,int val)
		{
			range_reset(L,R,val,1,0,n);
		}
};
const int N = int(1e6)+10;
int dsu[N];
int A[N];
int Find(int x)
{
	if(dsu[x]==x)return x;
	return dsu[x]=Find(dsu[x]);
}
void Union(int a,int b)
{
	a = Find(a);b=Find(b);
	if(a==b)return;
	dsu[a]=b;
}
int len;
int main()
{
	int n,q;si(n);si(q);
	for(int i=1;i<=n;i++)
		dsu[i]=i;
	segment_tree R(dsu,dsu+n+1);
	while(q--)
	{
		int t,x,y;
		si(t);si(x);si(y);
		if(t==1)
			Union(x,y);
		else if(t==2)
		{
			if(x>y)swap(x,y);
			len=0;
			for(int i=x;i<=y;i++)
			{
				int xx = R.query(i);
				A[len++]=Find(xx);
				i = xx;
			}
			for(int i=1;i<len;i++)
				Union(A[0],A[i]);
			R.update(x,y+1,y);
		}
		else
			puts(Find(x)==Find(y)?"YES":"NO");
	}	
	return 0;
}