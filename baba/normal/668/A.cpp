//Tanuj Khattar
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

pair<int,int> A[101][101];
int ans[101][101];
int main()
{
	int n,m,q;
	si(n);si(m);si(q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			A[i][j]={i,j};
	while(q--){
		int t;si(t);
		if(t==1){
			int r;si(r);
			II x = A[r][1];
			for(int j=1;j<m;j++)
				A[r][j]=A[r][j+1];
			A[r][m]=x;
		}
		else if(t==2){
			int c;si(c);
			II x = A[1][c];
			for(int i=1;i<n;i++)
				A[i][c]=A[i+1][c];
			A[n][c]=x;
		}
		else{
			int r,c,x;
			si(r);si(c);si(x);
			ans[A[r][c].F][A[r][c].S]=x;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			printf("%d%s",ans[i][j],(j==m?"\n":" "));
	return 0;
}