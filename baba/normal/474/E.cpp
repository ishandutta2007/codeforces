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

class sparse_segtree{
	LL low,high;	//range of the segtree [low,high)
	struct node{
		LL mx;
		int index;
		node *l,*r;
		node(){l=r=NULL;mx=0;}
	};
	typedef node* pnode;
	pnode head;
	pair<LL,int> value(pnode t)
	{
		return t?MP(t->mx,t->index):MP(0ll,0);
	}
	void point_update(pnode& t,LL l,LL r,LL pos,LL val,int idx)
	{
		if(pos<l || pos>=r)return;
		if(!t) t = new node;
		if(l==r-1 && l==pos)
		{
			t->mx = val;
			t->index = idx;
			return;
		}
		LL mid = (l+r)>>1;
		point_update(t->l,l,mid,pos,val,idx);
		point_update(t->r,mid,r,pos,val,idx);
		pair<LL,int> mx = max(value(t->l),value(t->r));
		t->mx = mx.F;
		t->index = mx.S;
	}
	pair<LL,int> range_query(pnode t,LL l,LL r,LL L,LL R)
	{
		if(l>=R || L>=r)return MP(0ll,0);
		if(!t)return MP(0ll,0);
		if(l>=L && r<=R)
			return MP(t->mx,t->index);
		LL mid = (l+r)>>1;
		pair<LL,int> la = range_query(t->l,l,mid,L,R);
		pair<LL,int> ra = range_query(t->r,mid,r,L,R);
		return max(la,ra);
	}
	public:
	sparse_segtree(){low=0,high=0,head=NULL;}
	sparse_segtree(LL l,LL h)
	{
		low = l;
		high = h;
		head = NULL;
	}
	void update(LL pos,LL val,int idx)
	{
		point_update(head,low,high,pos,val,idx);
	}
	pair<LL,int> query(LL L,LL R)
	{
		if(L>=R)return MP(0ll,0);
		return range_query(head,low,high,L,R);
	}
};
const LL MXH = LL(1e15)+10;
const int N = int(1e5)+10;
int dp[N];
int ans[N];
LL A[N];
int main()
{
	sparse_segtree H(1,MXH);
	int n,d;
	si(n);si(d);
	for(int i=1;i<=n;i++)
		sll(A[i]);
	for(int i=1;i<=n;i++)
	{
		pair<LL,int> la = H.query(1,A[i]-d+1);
		pair<LL,int> ra = H.query(A[i]+d,MXH);
		pair<LL,int> mx = max(la,ra);
		dp[i] = mx.F + 1;
		ans[i] = mx.S;
		H.update(A[i],dp[i],i);
	}
	int mx = 0;
	for(int i=1;i<=n;i++)
		if(dp[i]>dp[mx])
			mx = i;
	dout(dp[mx]);
	stack<int> s;
	while(mx>0)
	{
		s.push(mx);
		mx = ans[mx];
	}
	while(!s.empty())
	{
		printf("%d ",s.top());
		s.pop();
	}
	printf("\n");
	return 0;
}