#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define DRT() int t; si(t); while(t--)

#define FLUSHN while(getchar()!='\n')
#define FLUSHS while(getchar()!=' ')

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
const int N = int(1e5)+10;
LL A[N];
int n;
int S[N];
VI P;
LL gcd(LL a, LL b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
LL lcm() {
	LL res = 1;
	for (int i = 0; i < n; i++) {
		res = (res*A[i])/gcd(res, A[i]);
	}
	return res;
}
void gen()
{
	for(int i=2;i<N;i++)
		if(!S[i])
			for(int j=i*i;j<N;j+=i)
				S[i]=1;
	for(int i=2;i<N;i++)
		if(!S[i])
			P.PB(i);
}
bool isprime(LL x)
{
	for(int i=0;i<SZ(P);i++)
		if(x%P[i]==0 && x!=P[i])
			return false;
	return true;
}
bool check(LL x)
{
	while(x>1)
	{
		if(x%2==0)x=x/2;
		else if(x%3==0)x=x/3;
		else return true;
	}
	return false;
}
int main()
{
	si(n);
	for(int i=0;i<n;i++)
		sll(A[i]);
	LL g = A[0];
	for(int i=1;i<n;i++)
		g = gcd(g,A[i]);
	for(int i=0;i<n;i++)
		A[i] = A[i]/g;
	int cnt2=0;
	for(int i=0;i<n;i++)
		if(A[i]>3 && check(A[i]))
			cnt2++;
	if(cnt2>0)
		puts("No");
	else 
		puts("Yes");
	return 0;
}