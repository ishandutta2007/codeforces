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

const int INF = int(2e9);

class segment_tree{
	private:
		VI ST;
		VI A;	//base array
		int n;

		void build(int node,int l,int r)
		{
			if(l==r-1)
			{
				ST[node]=l;
				return;
			}

			int leftChild = node<<1;
			int rightChild = leftChild | 1;
			int mid = (l+r)>>1;
			
			build(leftChild,l,mid);
			build(rightChild,mid,r);

			//Operation of segment tree
			int lc = ST[leftChild];
			int rc = ST[rightChild];
			if(A[lc]<A[rc])
				ST[node] = lc;
			else
				ST[node] = rc;
		}

		int range_query(int L,int R,int node,int l,int r)
		{
			if(l>=R || r<=L)
			//Depending on your operation return a value which indicates that there's nothing here
				return -1;
		
			int leftChild = node<<1;
			int rightChild = leftChild|1;
			if(L<=l && r<=R)
				return ST[node];
			int mid = (l+r)>>1;
			int leftAns = range_query(L,R,leftChild,l,mid);
			int rightAns = range_query(L,R,rightChild,mid,r);
			if(leftAns == -1)
				return rightAns;
			if(rightAns == -1)
				return leftAns;
			//Operation of segment tree
			if(A[leftAns]<A[rightAns])
				return leftAns;
			else
				return rightAns;
		}
	public:
		segment_tree(){ST.clear();A.clear();n=0;}
		segment_tree(VI& baseArray)	//construct using a vector
		{
			A = baseArray;
			n = SZ(baseArray);
			ST = VI(4*n,0);
			build(1,0,n);
		}
		segment_tree(int *begin,int *end)	//construct using an array
		{
			A = VI(begin,end);
			n = SZ(A);
			ST = VI(4*n,0);
			build(1,0,n);
		}

		//returns [L,R)
		int query(int L,int R)
		{
			return range_query(L,R,1,0,n);
		}
};
const int N = int(2e5)+10;
int A[N];
int ans[N];
segment_tree S;
void solve(int l,int r)
{
	if(l>r)return;
	int len = r-l+1;
	int mn = S.query(l,r+1); 
	int mnlen = max(r-mn,mn-l);
	for(int i=len;i>mnlen;i--)
		ans[i] = max(ans[i],A[mn]);
	solve(l,mn-1);
	solve(mn+1,r);
}
int main()
{
	int n;si(n);
	for(int i=0;i<n;i++)
	{
		si(A[i]);
		ans[i+1] = -INF;
	}
	S = segment_tree(A,A+n);
	solve(0,n-1);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}