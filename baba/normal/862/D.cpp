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
const int N = int(1e3)+10;
char s[N];
int n;
int get(int l, int r,char c){
  for(int i=1;i<=n;i++)
    s[i] = '0';
  for(int i=l;i<=r;i++)
    s[i] = c;
  printf("? %s\n",s+1);
  fflush(stdout);
  int x;si(x);
  return x;
}
int main()
{
  si(n);
  // first determine the 1st bit
  int v1 = get(0,0,'0');
  int v2 = get(1,1,'1');
  int b = v1 < v2 ? 0 : 1;
  int ans[2];
  ans[b] = 1;
  //determine the remaining bit
  int l = 2, r = n, pos = -1;
  while(l <= r){
    int mid = (l + r) >> 1;
    int v = get(l, mid, '1');
    int diff = v - v1;
    int bad_diff = b ? -(mid - l + 1) : (mid - l + 1);
    if(diff == bad_diff){
      l = mid + 1;
    }
    else {
      pos = mid;
      r = mid - 1;
    }
  }
  //done :)
  assert(pos != -1);
  ans[1 - b] = pos;
  printf("! %d %d\n",ans[0],ans[1]);
  fflush(stdout);
	return 0;
}