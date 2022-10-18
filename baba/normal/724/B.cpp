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
bool ok(int A[],int n){
  int cnt = 0;
  for(int i=1;i<=n;i++)
    if(A[i]!=i)
      cnt++;
  return cnt<=2;
}
void swp(int A[21][21],int n,int c1,int c2){
  for(int i=1;i<=n;i++)
    swap(A[i][c1],A[i][c2]);
}
bool check(int A[21][21],int n,int m){
  bool ret=true;
  for(int i=1;i<=n;i++)
    ret &= ok(A[i],m);
  return ret;
}
int A[21][21];
int main()
{
  int n,m;
  si(n);si(m);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      si(A[i][j]);
  bool ok = check(A,n,m);
  for(int i=1;i<=m;i++)
    for(int j=i+1;j<=m;j++){
      swp(A,n,i,j);
      ok |= check(A,n,m);
      swp(A,n,i,j);
    }
  puts(ok?"YES":"NO");
	return 0;
}