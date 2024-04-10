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
int BIT[N];
void update(int x, int v){
  for(;x<N;x+=x^(x&(x-1)))BIT[x] += v;
}
int query(int x){
  int ret = 0;
  for(;x;x=x&(x-1))ret+=BIT[x];
  return ret;
}
int main()
{
  int n;si(n);
  printf("1 ");
  for(int i=1;i<=n;i++){
    int x;si(x);
    update(n - x + 1, 1);
    int l = 1, h = n, ans = n + 1;
    while(l <= h){
      int mid = (l + h) >> 1;
      if(query(mid) == mid){
        l = mid + 1;
      }
      else {
        ans = mid;
        h = mid - 1;
      }
    }
    printf("%d ",1 + (i - ans + 1));
  }
  puts("");
	return 0;
}