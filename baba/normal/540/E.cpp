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
const int N = int(1e5)+1;
II A[N];
int pos[2*N]; 
int R[2*N];
map<int,int> M;
int normal[2*N];
int temp[2*N];
LL count_inv(int A[],int l,int r)
{
//	trace4(l,r,A[l],A[r]);
	if(l >= r-1)
		return 0;
	int mid = (l+r)/2;
	LL L = count_inv(A,l,mid);
	LL R = count_inv(A,mid,r);
	LL merge = 0;
	int sz = 0;
	int i,j;
	for(i=l,j=mid;i<mid && j < r;)
		if(A[i] <= A[j])
			temp[sz++]  = A[i++];
		else
		{
			temp[sz++]  = A[j++];
			merge += (LL)mid - (LL)i;
		}
	while(i<mid)
		temp[sz++] = A[i++];
	while(j<r)
		temp[sz++] = A[j++];
//	trace3(sz,l,r);
	for(int i=0;i<sz;i++)
		A[l+i] = temp[i];
	return L + R + merge;

}
int main()
{
	int n;
	si(n);
	set<int> in;
	for(int i=0;i<n;i++)
	{
		si(A[i].F);si(A[i].S);
		in.insert(A[i].F);
		in.insert(A[i].S);
	}
	int cnt=0;
	int nn = SZ(in);
	//trace1(nn);
	while(!in.empty())
	{
		M[*in.begin()] = cnt;
		pos[cnt] = *in.begin();
		R[cnt] = *in.begin();
		cnt++;
		in.erase(in.begin());
	}
	for(int i=0;i<n;i++)
	{
		int a = M[A[i].F],b = M[A[i].S];
		swap(pos[a],pos[b]);
	}
	normal[0] = R[0]-1;
	for(int i=1;i<nn;i++)
		normal[i] = normal[i-1]+ R[i] - R[i-1] -1;
	//i = co-ordinate compressed number
	//R[i] = Actual pos in the array (stored in increasing order)
	//pos[i] = Element at pos R[i]
	//normal[i] = No of elements which are at their respective positions until R[i]
	//normal[0] = R[i]-1
	//normal[i] = normal[i-1] + R[i]-R[i-1]-1
	LL ans=0;
	//contribution of normals
	for(int i=0;i<nn;i++)
	{
		int Pos = R[i];
		int Elem = pos[i];
		if(Elem < Pos)
			ans += (LL)normal[i] - (LL)normal[M[Elem]];
		else
			ans += (LL)normal[M[Elem]] - (LL)normal[i];
	}
	ans += count_inv(pos,0,nn);
	lldout(ans);
	return 0;
}