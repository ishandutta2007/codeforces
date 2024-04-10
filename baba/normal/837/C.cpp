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
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

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

const int N=105;
int X[N],Y[N];
int n,a,b;
int func2(int r1,int c1,int r2,int c2){
  int r=r1+r2;
  int c=max(c1,c2);
  if(r>c)
    swap(r,c);
  if(r<=a&&c<=b)
    return 1;
  r=c1+c2;
  c=max(r1,r2);
  if(r>c)
    swap(r,c);
  if(r<=a&&c<=b)
    return 1;
  return 0;
}
int func(int i,int j){
  //try to fix them one r1+c2,c1+r2
  int ret=0;
  ret=max(func2(X[i],Y[i],X[j],Y[j]),ret);
  ret=max(func2(X[i],Y[i],Y[j],X[j]),ret);
  return ret;
}
int main()
{
  cin>>n>>a>>b;
  if(a>b)
    swap(a,b);
  for(int i=0;i<n;i++)
    cin>>X[i]>>Y[i];
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(func(i,j))
        ans=max(ans,X[i]*Y[i]+X[j]*Y[j]);
    }
  }
  cout<<ans<<"\n";
	return 0;
}