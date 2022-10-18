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
const int N = 2001;
int A[N][N],R[N*N],D[N*N],rev[N*N],idx[N][N];
int get(int a,int b){
  int x = 0;
  while(a--)x = D[x];
  while(b--)x = R[x];
  return x;
}
int main()
{
  int n,m,q;
  si(n);si(m);si(q);
  for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
      idx[i][j] = i*(m+1) + j;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      si(A[i][j]),rev[idx[i][j]] = A[i][j];
  for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++){
      R[idx[i][j]] = idx[i][j+1];
      D[idx[i][j]] = idx[i+1][j];
    }
  while(q--){
    int a,b,c,d,h,w,x,y;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&h,&w);
    int xx = get(a-1,b-1),yy = get(c-1,d-1);
    x = xx, y = yy;
    for(int i=0;i<w;i++,x=R[x],y=R[y])swap(D[R[x]],D[R[y]]);
    for(int i=0;i<h;i++,x=D[x],y=D[y])swap(R[D[x]],R[D[y]]);
    x = xx, y = yy;
    for(int i=0;i<h;i++,x=D[x],y=D[y])swap(R[D[x]],R[D[y]]); 
    for(int i=0;i<w;i++,x=R[x],y=R[y])swap(D[R[x]],D[R[y]]);
  }
  for(int i=0,r=0;i<=n;i++,r=D[r])
    for(int j=0,c=r;j<=m;j++,c=R[c])
      if(i&&j)
        printf("%d%s",rev[c],(j==m?"\n":" "));
  return 0;
}