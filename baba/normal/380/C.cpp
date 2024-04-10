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

typedef pair<int,II > State;

class segment_tree{
	private:
		string A;	//base array
		VI cnt1,cnt2,ans;
		int n;

		void build(int node,int l,int r)
		{
			if(l==r-1)
			{
				cnt1[node] = (A[l]==')'?1:0);
				cnt2[node] = (A[l]=='('?1:0);
				ans[node]=0;
				return;
			}

			int leftchild = node<<1;
			int rightchild = leftchild | 1;
			int mid = (l+r)>>1;
			
			build(leftchild,l,mid);
			build(rightchild,mid,r);

			ans[node] = ans[leftchild] + ans[rightchild] + min(cnt2[leftchild],cnt1[rightchild]);
			cnt1[node] = cnt1[leftchild];
			cnt2[node] = cnt2[rightchild];
			if(cnt2[leftchild] > cnt1[rightchild])
				cnt2[node]+=cnt2[leftchild] - cnt1[rightchild];
			else
				cnt1[node]+=cnt1[rightchild] - cnt2[leftchild];
		}
		State range_query(int L,int R,int node,int l,int r)
		{
			if(l>=R || r<=L)
			//Depending on your operation return a value which indicates that there's nothing here
			{
				return MP(0,MP(0,0));
			}
		
			int leftChild = node<<1;
			int rightChild = leftChild|1;

			if(L<=l && r<=R)
				return MP(ans[node],MP(cnt1[node],cnt2[node]));

			int mid = (l+r)>>1;

			State leftAns = range_query(L,R,leftChild,l,mid);
			State rightAns = range_query(L,R,rightChild,mid,r);
			State ret;
			
			ret.F = leftAns.F + rightAns.F + min(leftAns.S.S,rightAns.S.F);
			ret.S.F = leftAns.S.F;
			ret.S.S = rightAns.S.S;
			if(leftAns.S.S > rightAns.S.F)
				ret.S.S+=leftAns.S.S - rightAns.S.F;
			else
				ret.S.F+=rightAns.S.F - leftAns.S.S;
			return ret;
		}

	public:
		segment_tree(){A.clear();cnt1.clear();ans.clear();cnt2.clear();n=0;}
		segment_tree(string& baseArray)	//construct using a vector
		{
			A = baseArray;
			n = SZ(baseArray);
			cnt1 = VI(4*n);
			cnt2 = VI(4*n);
			ans = VI(4*n,0);
			build(1,0,n);
		}
		//returns [L,R)
		int query(int L,int R)
		{
			return 2*range_query(L,R,1,0,n).F;
		}
};


int main()
{
	string s;
	cin>>s;
	segment_tree A(s);
	int m;
	si(m);
		
	while(m--)
	{
		int l,r;
		si(l);si(r);
		dout(A.query(l-1,r));
	}
	return 0;
}