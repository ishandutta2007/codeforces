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
const int N = int(2e3)+10;
const int M = int(5e5)+10;
bitset<N> A[N],B[N];
int X[M],Y[M];
int main()
{
  int n;si(n);
  int m;si(m);
  for(int i=0;i<m;i++){
    int x,y;
    si(x);si(y);
    x--;y--;
    A[x][y]=1;
    X[i]=x;Y[i]=y;
  }
  for(int i=0;i<n;i++)
    B[i][i]=1;
  for(int i=0;i<n;i++){
    int idx = -1;
    for(int j=i;j<n;j++)
      if(A[j][i]==1){
        idx = j;
        break;
      }
    assert(idx >= 0);
    swap(A[idx],A[i]);
    swap(B[idx],B[i]);
    for(int j=0;j<n;j++)
      if(j!=i && A[j][i]==1){
        A[j] ^= A[i];
        B[j] ^= B[i];
      }
  }
  for(int i=0;i<m;i++)
    puts(!B[Y[i]][X[i]]?"YES":"NO");
	return 0;
}