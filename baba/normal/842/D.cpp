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
const int N = int(3e5)+10;
const int LOGN = 20;
int to[N * LOGN][2], done[N];
int buff = 0, sz[N * LOGN];
void insert(int num){
  int x = 0;
  if(done[num])return;
  for(int i = LOGN - 1; i >= 0; i--){
    sz[x]++;
    int b = ((1 << i) & num) ? 1 : 0;
    if(!to[x][b])to[x][b] = ++buff;
    x = to[x][b];
  }
  sz[x]++;
  done[num] = 1;
}
int query(int num){
  int x = 0;
  int ret = 0;
  for(int i = LOGN - 1; i >= 0; i--){
    int b = ((1 << i) & num) ? 1 : 0;
    int shouldHave = (1 << i);
    int bit = b ^ 0;
    //trace(x,ret,i,shouldHave,bit,to[x][bit],sz[to[x][bit]]);
    if(!to[x][bit])return ret;
    if(sz[to[x][bit]] < shouldHave){
      x = to[x][bit];
    }
    else {
      ret |= (1 << i);
      x = to[x][1 - bit];
      if(!x)return ret;
    }
  }
  return ret;
}
int main()
{
  int n,m;
  si(n);si(m);
  int val = 0;
  for(int i=1;i<=n;i++){
    int x;si(x);
    insert(x);
  }
  REP(i,m){
    int x;si(x);
    val ^= x;
    dout(query(val));
  }
	return 0;
}