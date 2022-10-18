//itisalways42
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef vector< vector< double > > VVD;
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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

const int X = 128;
double P[X];

VVD mult(VVD a, VVD b)
{
	VVD C(SZ(a),vector<double>(SZ(a)));
	for(int i=0; i<SZ(a); i++)
		for(int j=0; j<SZ(a); j++)
		{
			C[i][j] = 0;
			for(int k=0; k<SZ(a); k++)
				C[i][j] += a[i][k]*b[k][j];
		}
	return C;
}

VVD matpow(VVD a, int p)
{
	VVD ret(SZ(a),vector<double>(SZ(a)));
	for(int i=0; i<SZ(a); i++)
		for(int j=0; j<SZ(a); j++)
			ret[i][j] = (i==j?1:0);
	while(p)
	{
		if(p&1) ret = mult(ret,a);
		a = mult(a,a);
		p /= 2;
	}
	return ret;
}

int main()
{
	int n,x; si(n); si(x);
	for(int i=0; i<=x; i++)	scanf("%lf",&P[i]);
	for(int i=x+1; i<X; i++) P[i] = 0;
	VVD M(X,vector<double>(X));
	for(int i=0; i<X; i++)
		for(int j=0; j<X; j++)
			M[i][j] = P[i^j];
	VVD ans = matpow(M,n);
	printf("%.9lf\n",1-ans[0][0]);
	return 0;
}