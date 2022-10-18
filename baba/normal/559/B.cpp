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
const int N = int(5e5)+10;
const int LOGN = 23;
int RA[LOGN][N];//RA[i][j] = Rank of suffix S[j...j+2^i] i.e. 2^j length substring starting at i.
int SA[N];	//SA[i] = i'th Lexicographically smallest suffix's index.
int tempSA[N],cnt[N];	//Helper stuff.
int LCP[LOGN][N];	//LCP[0][i] = length of longest common prefix of SA[i] && SA[i+1] (sorted suffixes). Rest is for O(1) rmq;
int msb[N];

char a[200010],b[200010],res[400010];
bool equal(int a,int b,int p,int q)
{
	for(int i=0;i<=(b-a);i++)
		if(res[a+i]!=res[p+i])
			return false;
	return true;
}
bool equiv(int a,int b,int p,int q)
{
	int l1 = b-a+1;
	int l2 = q-p+1;
	if(l1!=l2)return false;
	if(b<a || q<p)return false;
	if(equal(a,b,p,q))return true;
	if(l1&1) return false;
	int m1 = a + l1/2 - 1;
	int m2 = p + l2/2 - 1;
	return (equiv(a,m1,p,m2) && equiv(m1+1,b,m2+1,q))||(equiv(a,m1,m2+1,q) && equiv(m1+1,b,p,m2)); 
}

int main()
{
	scanf("%s\n",a);
	scanf("%s\n",b);
	int l1,l2;
	for(l1=0;a[l1]!='\0';l1++)
		res[l1]=a[l1];
	for(l2=0;b[l2]!='\0';l2++)
		res[l1+l2]=b[l2];
	res[l1+l2]='\0';
	if(equiv(0,l1-1,l1,l1+l2-1))
		puts("YES");
	else
		puts("NO");
	return 0;
}