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
		vector<set<int> > A;	//base array
		int n;

		void build(int node,int l,int r)
		{
			if(l==r-1)
			{
				ST[node]= *A[l].begin();
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

		int range_query(int L,int R,int node,int l,int r)
		{
			if(l>=R || r<=L)
			//Depending on your operation return a value which indicates that there's nothing here
				return -INF;
		
			int leftChild = node<<1;
			int rightChild = leftChild|1;

			if(L<=l && r<=R)
				return ST[node];

			int mid = (l+r)>>1;

			int leftAns = range_query(L,R,leftChild,l,mid);
			int rightAns = range_query(L,R,rightChild,mid,r);

			//Operation of segment tree
			return max(leftAns,rightAns);

		}

		void point_update(int pos,int node,int l,int r)
		{
			if(r<=pos || l>pos)
				return;
			if(l==r-1 && l==pos)
			{
				A[l].erase(A[l].begin());
				ST[node]= *A[l].begin();
				return;
			}

			int leftChild = node<<1;
			int rightChild = leftChild | 1;
			int mid = (l+r)>>1;

			point_update(pos,leftChild,l,mid);
			point_update(pos,rightChild,mid,r);

			//operation of segment tree
			ST[node] = max(ST[leftChild],ST[rightChild]);

		}

	public:
		segment_tree(){ST.clear();A.clear();n=0;}
		segment_tree(VII& R,int m)	//construct using a vector
		{
			n = m+1;
			A = vector<set<int> >(m+1);
			for(int i=0;i<n;i++)
				A[i].insert(INF);
			for(int i=0;i<SZ(R);i++)
				A[R[i].S].insert(R[i].F);
			ST = VI(4*n,0);
			build(1,0,n);
		}
		//returns [L,R)
		int query(int L,int R)
		{
			return range_query(L,R,1,0,n);
		}
		void point_update(int pos)
		{
			point_update(pos,1,0,n);
		}
};
const int N = (2e5)+10;
int n,m,k,q;
VII R;
vector<pair< pair<II,II>,int > >Q;
bool ans[N];


void checkX()
{
	segment_tree S(R,m);
	sort(ALL(R));
	sort(ALL(Q));
	for(int i=0,j=0;i<q;i++)
	{
		int x1 = Q[i].F.F.F , y1 = Q[i].F.F.S;
		int x2 = Q[i].F.S.F , y2 = Q[i].F.S.S;
		int pos = Q[i].S;
		while(R[j].F<x1 && j<SZ(R))
		{
			S.point_update(R[j].S);
			j++;
		}
		int mx = S.query(y1,y2+1);
		//trace5(mx,y1,y2,x2,pos);
		if(mx <= x2)
			ans[pos]|=true;
	}
}

void rotateBoard()
{
	swap(n,m);
	for(int i=0;i<SZ(R);i++)
		swap(R[i].F,R[i].S);
	for(int i=0;i<q;i++)
	{
		swap(Q[i].F.F.F,Q[i].F.F.S);
		swap(Q[i].F.S.F,Q[i].F.S.S);
	}
}

int main()
{
	si(n);si(m);si(k);si(q);
	R = VII(k);
	for(int i=0;i<k;i++)
		si(R[i].F),si(R[i].S);
	
	Q = vector<pair< pair<II,II>,int > >(q);
	for(int i=0;i<q;i++)
	{
		si(Q[i].F.F.F);si(Q[i].F.F.S);si(Q[i].F.S.F);si(Q[i].F.S.S);
		Q[i].S = i;
		ans[i]=false;
	}
	checkX();
	rotateBoard();
	checkX();

	for(int i=0;i<q;i++)
		printf("%s\n",ans[i]?"YES":"NO");

	return 0;
}