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
const int N = int(2e3)+10;
const int INF = int(2e9);
double f[N][N][2][2];
int L[N][N],R[N][N];
int n,H;double p;
int X[N];
inline double dp(int L,int i,int j,int R)
{
	if(i>j)return 0;
	if(i==j) return min(H,X[i]-(L?X[i-1]+H:X[i-1]))*p + min(H,(R?X[j+1]-H:X[j+1])-X[i])*(1-p);
	double &ret = f[i][j][L][R];
	if(ret!=-1)return ret;
	ret = 0;
	ret += 0.5*p*(dp(0,i+1,j,R) + min(H,X[i]-(L?X[i-1]+H:X[i-1])));//Left-out
	ret += 0.5*(1-p)*(dp(L,i,j-1,0) + min(H,(R?X[j+1]-H:X[j+1])-X[j]));//Right-out
	//Left-in
	int x = ::L[i][j];
	ret+= 0.5*(1-p)*(dp(1,x,j,R) + min(R?X[j+1]-H:X[j+1],X[x-1]+H)-X[i]);
	//Right-in
	x = ::R[i][j];
	ret+= 0.5*p*(dp(L,i,x,1) + (X[j] - max(L?X[i-1]+H:X[i-1],X[x+1] - H)));
	return ret;
}
int main()
{
	scanf("%d %d %lf\n",&n,&H,&p);
	for(int i=1;i<=n;i++)
		scanf("%d",X+i);
	X[0]=-INF;X[n+1]=INF;
	sort(X+1,X+1+n);
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			for(int k=0;k<2;k++)
				for(int l=0;l<2;l++)
					f[i][j][l][k]=-1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(j==i+1)L[i][j]=(X[j]-X[i]<H?j+1:j);
			else L[i][j] = (L[i][j-1]<j?L[i][j-1]:(X[j]-X[j-1]<H?j+1:j));
		}
	for(int j=1;j<=n;j++)
		for(int i=j-1;i>=1;i--)
		{
			if(i==j-1)R[i][j]=(X[j]-X[i]<H?i-1:i);
			else R[i][j] = (R[i+1][j]>i?R[i+1][j]:(X[i+1]-X[i]<H?i-1:i));
		}
	printf("%.8lf\n",dp(0,1,n,0));
	return 0;
}