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

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

class segment_tree_gcd{
	private:
		VI ST;
		VI A;	//base array
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
			ST[node] = gcd(ST[leftChild],ST[rightChild]);
		}

		int range_query(int L,int R,int node,int l,int r)
		{
			if(l>=R || r<=L)
			//Depending on your operation return a value which indicates that there's nothing here
				return 0;
		
			int leftChild = node<<1;
			int rightChild = leftChild|1;
			if(L<=l && r<=R)
				return ST[node];

			int mid = (l+r)>>1;

			int la = range_query(L,R,leftChild,l,mid);
			int ra = range_query(L,R,rightChild,mid,r);
			if(!la || !ra)
				return la?la:ra;
			//Operation of segment tree
			return gcd(la,ra);
		}

	public:
		segment_tree_gcd(){ST.clear();A.clear();n=0;}
		segment_tree_gcd(VI& baseArray)	//construct using a vector
		{
			A = baseArray;
			n = SZ(baseArray);
			ST = VI(4*n,0);
			build(1,0,n);
		}
		segment_tree_gcd(int *begin,int *end)	//construct using an array
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
class segment_tree_min{
	private:
		VI ST;
		VI A;	//base array
		VI cnt;
		int n;

		void build(int node,int l,int r)
		{
			if(l==r-1)
			{
				ST[node]=A[l];
				cnt[node]=1;
				return;
			}

			int leftChild = node<<1;
			int rightChild = leftChild | 1;
			int mid = (l+r)>>1;
			
			build(leftChild,l,mid);
			build(rightChild,mid,r);
			if(ST[leftChild] < ST[rightChild])
			{
				ST[node] = ST[leftChild];
				cnt[node] = cnt[leftChild];
			}
			else if(ST[leftChild] > ST[rightChild])
			{
				ST[node] = ST[rightChild];
				cnt[node] = cnt[rightChild];
			}
			else
			{
				ST[node] = ST[leftChild];
				cnt[node] = cnt[leftChild] + cnt[rightChild];
			}
		}

		II range_query(int L,int R,int node,int l,int r)
		{
			if(l>=R || r<=L)
			//Depending on your operation return a value which indicates that there's nothing here
				return MP(INF,0);
		
			int leftChild = node<<1;
			int rightChild = leftChild|1;
			if(L<=l && r<=R)
				return MP(ST[node],cnt[node]);

			int mid = (l+r)>>1;

			II la = range_query(L,R,leftChild,l,mid);
			II ra = range_query(L,R,rightChild,mid,r);
			II ret;
			//Operation of segment tree
			if(la.F == ra.F)
				return MP(la.F,la.S+ra.S);
			else
				return min(la,ra);
		}

	public:
		segment_tree_min(){ST.clear();A.clear();n=0;}
		segment_tree_min(VI& baseArray)	//construct using a vector
		{
			A = baseArray;
			n = SZ(baseArray);
			ST = VI(4*n,0);
			cnt = VI(4*n,0);
			build(1,0,n);
		}
		segment_tree_min(int *begin,int *end)	//construct using an array
		{
			A = VI(begin,end);
			n = SZ(A);
			ST = VI(4*n,0);
			cnt = VI(4*n,0);
			build(1,0,n);
		}

		//returns [L,R)
		II query(int L,int R)
		{
			return range_query(L,R,1,0,n);
		}
};
const int N = int(1e5)+10;
int S[N];
segment_tree_gcd A;
segment_tree_min B;
int main()
{
	int n;
	si(n);
	for(int i=0;i<n;i++)
		si(S[i]);
	A = segment_tree_gcd(S,S+n);
	B = segment_tree_min(S,S+n);
	int t;si(t);
	while(t--)
	{
		int l,r;
		si(l);si(r);
		int g = A.query(l-1,r);
		II mn = B.query(l-1,r);
		int ans = r-l+1;
		if(mn.F==g)
			ans -= mn.S;
		//trace3(mn.F,mn.S,g);
		dout(ans);
	}
	return 0;
}