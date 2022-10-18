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
		VI ST;
		VI level;
		VI A;	//base array
		VI lazy;
		int n;

		void build(int node,int l,int r)
		{
			if(l==r-1)
			{
				ST[node]=A[l];
				level[node]=0;
				return;
			}

			int leftChild = node<<1;
			int rightChild = leftChild | 1;
			int mid = (l+r)>>1;
			
			build(leftChild,l,mid);
			build(rightChild,mid,r);

			level[node] = level[leftChild]+1;
			//Operation of segment tree
			if(level[node]&1)
				ST[node] = ST[leftChild] | ST[rightChild];
			else
				ST[node] = ST[leftChild] ^ ST[rightChild];

		}

		int range_query(int L,int R,int node,int l,int r)
		{
			if(l>=R || r<=L)
			//Depending on your operation return a value which indicates that there's nothing here
				return 0;
		
			int leftChild = node<<1;
			int rightChild = leftChild|1;
			if(lazy[node]!=0)
			{
				//Operation of range_update
				ST[node]+=(r-l)*lazy[node]; 	
				
				if(l!=r-1)
				{
					lazy[leftChild]+=lazy[node];
					lazy[rightChild]+=lazy[node];
				}
				lazy[node]=0;
			}

			if(L<=l && r<=R)
				return ST[node];

			int mid = (l+r)>>1;

			int leftAns = range_query(L,R,leftChild,l,mid);
			int rightAns = range_query(L,R,rightChild,mid,r);

			//Operation of segment tree
			return (level[node]&1 ? (leftAns|rightAns) : (leftAns^rightAns));

		}

		void point_update(int pos,int val,int node,int l,int r)
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
			if(level[node]&1)
				ST[node] = ST[leftChild] | ST[rightChild];
			else
				ST[node] = ST[leftChild] ^ ST[rightChild];

		//	trace4(node,l+1,r,ST[node]);
		}
		void range_update(int L,int R,int val,int node,int l,int r)
		{
			int leftChild = node<<1;
			int rightChild = leftChild | 1;
			if(lazy[node]!=0)	//This node needs to be updated
			{
				//Operation of range_update
				ST[node]+=(r-l)*lazy[node]; 	
				if(l!=r-1)
				{
					lazy[leftChild]+=lazy[node];
					lazy[rightChild]+=lazy[node];
				}
				lazy[node]=0;
			}

			if(l>=R || r<=L)	//Segment out of range
				return ;
			
			if(L<=l && r<=R)	//Segment completely within range
			{
				//Operation of range_update
				ST[node]+=(r-l)*val;
				if(l!=r-1)
				{
					lazy[leftChild]+=val;
					lazy[rightChild]+=val;
				}
				return;
			}

			int mid = (l+r)>>1;

			range_update(L,R,val,leftChild,l,mid);
			range_update(L,R,val,rightChild,mid,r);

			//Operation of segment tree
			ST[node] = min(ST[leftChild],ST[rightChild]);

		}

	public:
		segment_tree(){ST.clear();A.clear();n=0;lazy.clear();}
		segment_tree(VI& baseArray)	//construct using a vector
		{
			A = baseArray;
			n = SZ(baseArray);
			ST = VI(4*n,0);
			lazy = VI(4*n,0);
			level = VI(4*n,0);
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
		int query(int L,int R)
		{
			return range_query(L,R,1,0,n);
		}
		void point_update(int pos,int val)
		{
			point_update(pos,val,1,0,n);
		}
		void range_update(int L,int R,int val)
		{
			range_update(L,R,val,1,0,n);
		}
};


int main()
{
	int n,m;
	si(n);si(m);
	VI A((1<<n));
	for(int i=0;i<(1<<n);i++)
		si(A[i]);
	segment_tree S(A);
	while(m--)
	{
		int p,b;
		si(p);si(b);
		S.point_update(p-1,b);
		dout(S.query(0,(1<<n)));
	}

	return 0;
}