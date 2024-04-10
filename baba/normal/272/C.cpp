//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<long long int>     VI;
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
		VI lazy;
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
			ST[node] = max(ST[leftChild],ST[rightChild]);
		}

		LL range_query(int L,int R,int node,int l,int r)
		{
			if(l>=R || r<=L)
			//Depending on your operation return a value which indicates that there's nothing here
				return -INF;
		
			int leftChild = node<<1;
			int rightChild = leftChild|1;
			if(lazy[node]!=0)
			{
				//Operation of range_update
				ST[node]=lazy[node]; 	
				
				if(l!=r-1)
				{
					lazy[leftChild]=lazy[node];
					lazy[rightChild]=lazy[node];
				}
				lazy[node]=0;
			}

			if(L<=l && r<=R)
				return ST[node];

			int mid = (l+r)>>1;

			LL leftAns = range_query(L,R,leftChild,l,mid);
			LL rightAns = range_query(L,R,rightChild,mid,r);

			//Operation of segment tree
			return max(leftAns,rightAns);

		}

		void point_update(int pos,int val,LL node,int l,int r)
		{
			if(r<=pos || l>pos)
				return;
			if(l==r-1 && l==pos)
			{
				ST[node]=val;
				A[l]=val;
				return;
			}

			int leftChild = node<<1;
			int rightChild = leftChild | 1;
			int mid = (l+r)>>1;

			point_update(pos,val,leftChild,l,mid);
			point_update(pos,val,rightChild,mid,r);

			//operation of segment tree
			ST[node] = max(ST[leftChild],ST[rightChild]);

		}
		void range_update(int L,int R,LL val,int node,int l,int r)
		{
			int leftChild = node<<1;
			int rightChild = leftChild | 1;
			if(lazy[node]!=0)	//This node needs to be updated
			{
				//Operation of range_update
				ST[node]=lazy[node]; 	
				if(l!=r-1)
				{
					lazy[leftChild]=lazy[node];
					lazy[rightChild]=lazy[node];
				}
				lazy[node]=0;
			}

			if(l>=R || r<=L)	//Segment out of range
				return ;
			
			if(L<=l && r<=R)	//Segment completely within range
			{
				//Operation of range_update
				ST[node]=val;
				if(l!=r-1)
				{
					lazy[leftChild]=val;
					lazy[rightChild]=val;
				}
				return;
			}

			int mid = (l+r)>>1;

			range_update(L,R,val,leftChild,l,mid);
			range_update(L,R,val,rightChild,mid,r);

			//Operation of segment tree
			ST[node] = max(ST[leftChild],ST[rightChild]);

		}

	public:
		segment_tree(){ST.clear();A.clear();n=0;lazy.clear();}
		segment_tree(VI& baseArray)	//construct using a vector
		{
			A = baseArray;
			n = SZ(baseArray);
			ST = VI(4*n,0);
			lazy = VI(4*n,0);
			build(1,0,n);
		}
		segment_tree(int *begin,int *end)	//construct using an array
		{
			A = VI(begin,end);
			n = SZ(A);
			ST = VI(4*n,0);
			lazy = VI(4*n,0);
			build(1,0,n);
		}

		//returns [L,R)
		LL query(int L,int R)
		{
			return range_query(L,R,1,0,n);
		}
		void point_update(int pos,LL val)
		{
			point_update(pos,val,1,0,n);
		}
		void range_update(int L,int R,LL val)
		{
			range_update(L,R,val,1,0,n);
		}
};


int main()
{
	int n;
	si(n);
	VI A(n);
	for(int i=0;i<n;i++)
		sll(A[i]);
	segment_tree S(A);
	int m;
	si(m);
	while(m--)
	{
		int w,h;
		si(w);si(h);
		LL ans = S.query(0,w);
		S.range_update(0,w,ans+h);
		lldout(ans);
	}

	return 0;
}