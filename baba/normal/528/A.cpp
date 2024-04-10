//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<long long int,long long int>   II;
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

#define FLUSHN while(gu()!='\n')

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
const int INF = int(2e9);

class segment_tree{
	private:
		VI P,S,K;	//Prefix,suffix,kadane
		VI total;
		VI A;	//base array
		int n;
		void build(int node,int l,int r)
		{
			if(l==r-1)
			{
				total[node]=K[node]=A[l];
				P[node]=S[node]=A[l];
				return;
			}
			int leftChild = node<<1;
			int rightChild = leftChild | 1;
			int mid = (l+r)>>1;
			build(leftChild,l,mid);
			build(rightChild,mid,r);
			//Operation of segment tree
			total[node] = total[leftChild] + total[rightChild];
			P[node] = max(P[leftChild],total[leftChild] + P[rightChild]);
			S[node] = max(S[rightChild],total[rightChild]+S[leftChild]);
			K[node] = max(S[leftChild]+P[rightChild],max(K[leftChild],K[rightChild]));
		}
		pair<II,II> range_query(int L,int R,int node,int l,int r)
		{
			if(l>=R || r<=L)
				return MP(MP(-INF,-INF),MP(-INF,0));//Depending on your operation return a value which indicates that there's nothing here
			if(L<=l && r<=R)
				return MP(MP(P[node],S[node]),MP(K[node],total[node]));
			int leftChild = node<<1;
			int rightChild = leftChild | 1;
			int mid = (l+r)>>1;
			pair<II,II> leftAns = range_query(L,R,leftChild,l,mid);
			pair<II,II> rightAns = range_query(L,R,rightChild,mid,r);
			//Operation of segment tree
			return MP(MP(max(leftAns.F.F,(leftAns.S.S==-INF?0:leftAns.S.S) + (rightAns.F.F==-INF?0:rightAns.F.F)),max(rightAns.F.S,(rightAns.S.S==-INF?0:rightAns.S.S) + (leftAns.F.S==-INF?0:leftAns.F.S))),
					MP(max((leftAns.F.S==-INF?0:leftAns.F.S) + (rightAns.F.F==-INF?0:rightAns.F.F),max(leftAns.S.F,rightAns.S.F)),leftAns.S.S+rightAns.S.S));
		}
		void point_update(int pos,int val,int node,int l,int r)
		{
			if(pos>=r || pos<l)
				return;
			if(l==r-1)
			{
				total[node]=K[node]=val;
				P[node]=S[node]=val;
				return;
			}
			int leftChild = node<<1;
			int rightChild = leftChild | 1;
			int mid = (l+r)>>1;
			
			point_update(pos,val,leftChild,l,mid);
			point_update(pos,val,rightChild,mid,r);

			//Operation of segment tree
			total[node] = total[leftChild] + total[rightChild];
			P[node] = max(P[leftChild],total[leftChild] + P[rightChild]);
			S[node] = max(S[rightChild],total[rightChild]+S[leftChild]);
			K[node] = max(S[leftChild]+P[rightChild],max(K[leftChild],K[rightChild]));
		}

	public:
		segment_tree(int N)	//construct using a vector
		{
			n = N;
			A = VI(n+1,1);
			A[0]=-INF;
			A[n]=-INF;
			P = VI(4*n,0);
			S = VI(4*n,0);
			K = VI(4*n,0);
			total = VI(4*n,0);
			build(1,0,n);
		}
		//returns answer of [L,R)
		LL query()
		{
			LL ret = range_query(0,n,1,0,n).S.F;
			if(ret==-INF)
				return 1;
			else
				return ret+1;
		}
		void point_update(int pos,int val)
		{
			point_update(pos,val,1,0,n);
		}
};
int main()
{
	int w,h,n;
	si(w);si(h);si(n);

	segment_tree H(w),V(h);
	LL mh=w,mv=h; 
	for(int i=0;i<n;i++)
	{
		char type;int pos;
		FLUSHN;
		scanf("%c %d",&type,&pos);
		//trace2(type,pos);
		if(type=='H')
		{
			V.point_update(pos,-INF);
			mv = V.query();
		}	
		else if(type == 'V')
		{
			H.point_update(pos,-INF);
			mh = H.query();
		}
		//trace4(type,pos,mv,mh);
		lldout(mv*mh);
	}

	return 0;
}