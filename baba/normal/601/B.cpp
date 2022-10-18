//Mobius_Treap
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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

//#define TRACE

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

const int N = int(1e5)+10;
const int LOGN = 20;
int A[N],B[N],msb[N];
int DP[LOGN][N];
void build_msb()
{
	int mx=-1;
	for(int i=0;i<N;i++)
	{
		if(i>=(1<<(mx+1)))mx++;
		msb[i]=mx;
	}
}
int MAX(int l,int r)
{
	int idx = msb[r-l+1];
	int sub= (1<<idx);
	int ret= ((A[DP[idx][l]]>A[DP[idx][r-sub+1]])?DP[idx][l]:DP[idx][r-sub+1]);
	return ret;
}
LL solve(int l,int r)
{
	if(l>=r)return 0;
	int mx = MAX(l,r-1);
	trace(l,r-1,mx);
	LL count=(mx-l+1)*1ll*(r-mx);
	LL add = A[mx]*count;
	trace(l,r,mx,A[mx],count);
	return add + solve(l,mx) + solve(mx+1,r);
}
int main()
{
	build_msb();
	int n;si(n);
	int q;si(q);
	for(int i=1;i<=n;i++)
		scanf("%d",B+i);
	for(int i=1;i<n;i++)
		A[i]=abs(B[i+1]-B[i]);
	for(int i=1;i<=n;i++)
		DP[0][i]=i;
	for(int i=1;i<LOGN;i++)
		for(int j=1;j<=n;j++)
		{
			int l=j,r=j+(1<<(i-1));
			if(r>n)DP[i][j]=DP[i-1][j];
			else DP[i][j] = (A[DP[i-1][l]]>A[DP[i-1][r]]?DP[i-1][l]:DP[i-1][r]);
		}
	while(q--)
	{
		int l,r;
		si(l);si(r);
		lldout(solve(l,r));
	}
	return 0;
}