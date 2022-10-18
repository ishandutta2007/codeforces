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
const int N = int(1e6)+10;
II A[N];
II B[N];
II C[N];
LL ST[4*N];
int n;
void point_update(int pos,int val,int node = 1,int l=0,int r=n)
{
	if(pos<l || pos>=r)
		return;
	if(l==r-1 && l == pos)
	{
		ST[node] += val;
		return;
	}
	int mid = (l+r)/2;
	int lc = node*2;
	int rc = node*2 + 1;
	point_update(pos,val,lc,l,mid);
	point_update(pos,val,rc,mid,r);
	ST[node] = ST[lc] + ST[rc];
}

LL range_query(int L,int R,int node = 1,int l = 0,int r = n)
{
	if(l>=R || L>=r)
		return 0;
	if(L<=l && r<=R)
		return ST[node];
	int mid = (l+r)/2;
	int lc = 2*node;
	int rc = 2*node + 1;
	return (range_query(L,R,lc,l,mid) + range_query(L,R,rc,mid,r));
}


int main()
{
	si(n);
	for(int i=0;i<n;i++)
	{
		si(A[i].F);
		A[i].S = i;
	}
	sort(A,A+n);
	int cnt=1;
	B[A[0].S].F=0;
	bool end;
	for(int i=1;i<n;i++)
	{
		end = false;
		if(A[i].F != A[i-1].F)
		{
			end = true;
			for(int j=i-1;j>=0;j--)
			{
				if(A[j].F!=A[i-1].F)
					break;
				C[A[j].S].F = B[A[i-1].S].F - B[A[j].S].F;
			}
			B[A[i].S].F=0;
			cnt = 1;
		}
		else
			B[A[i].S].F = cnt++;
	}
	if(!end)
		for(int j=n-1;j>=0;j--)
			{
				if(A[j].F!=A[n-1].F)
					break;
				C[A[j].S].F = B[A[n-1].S].F - B[A[j].S].F;
			}
	
	for(int i=0;i<n;i++)
		B[i].S = C[i].S = i;
	sort(B,B+n);
	sort(C,C+n);
	LL ans=0;
	int i,j;
	for(i=0,j=0;i<n&&j<n;)
	{
		while(j<n && B[i].F > C[j].F)
		{
			point_update(C[j].S,1);
			j++;
		}
		ans += range_query(B[i].S+1,n);
		i++;
	}
	while(i<n)
		ans += range_query(B[i].S,n);
	lldout(ans);
	return 0;
}