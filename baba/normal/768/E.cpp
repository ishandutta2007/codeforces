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
map<LL,int> G[61];
int f(int x,LL mask){
  if(G[x].count(mask))return G[x][mask];
  if(x == 0)return 0;
  int &ret =  G[x][mask];
  set<int> A;
 // trace(x,mask);
  for(int i=1;i<=x;i++)
    if((mask & (1ll<<(i-1))) == 0)
      A.insert(f(x - i, mask | (1ll << (i - 1))));
 // for(int i=0;i<SZ(A);i++)
 //   trace(x,bitset<5>(mask),i,A[i]);
  bool done = false;
  int cnt = 0;
  for(auto x : A)
    if(x != cnt){
      ret = cnt;
      done = true;
      break;
    }
    else cnt++;
  if(!done)ret = SZ(A);
  //trace(x,bitset<10>(mask),ret);
  return ret;
}
int main()
{
  int n;si(n);
  int s = 0;
  for(int i=0;i<n;i++){
    int x;si(x);
    s ^= f(x,0);
  }
  puts(s ? "NO" : "YES");
	return 0;
}