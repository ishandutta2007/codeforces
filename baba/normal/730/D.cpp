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

const int N = int(2e5)+10;
LL L[N],T[N],r;
int main()
{
  int n;si(n);
  sll(r);
  for(int i=1;i<=n;i++){
    sll(L[i]);
  }
  for(int i=1;i<=n;i++){
    sll(T[i]);
  }
  vector<LL> ans;
  LL nxt = 0;
  LL s = 0;
  LL szans = 0;
  for(int i=1;i<=n;i++){
    if(T[i] < L[i]){
      puts("-1");
      return 0;
    }
    LL dleft = L[i] - max(0ll,nxt - s);
    dleft = max(dleft,0ll);
    LL tleft = T[i] - L[i] + dleft;
    s = s + T[i] - tleft;
    if(tleft >= 2 * dleft){
      s += 2 * dleft;
      continue;
    }
    LL x = tleft - dleft;
    assert(x>=0);
    ans.PB(s + 2*x);
    szans++;
    nxt = s + 2 * x + r;
    s = s + 2 * x;
    LL temp = (s + dleft - x - nxt) / r;
    if( (s + dleft - x - nxt)%r != 0  && s + dleft - x - nxt >=0)
        temp++;
    LL tnxt = nxt;
    nxt = nxt + r*temp;
    szans += temp;
    while(szans < int(1e5) && tnxt < s + dleft - x) {
      ans.PB(tnxt);
      tnxt += r;
    }
    s = s + dleft - x;
  }
  lldout(szans);
  if(szans > int(1e5))return 0;
  for(auto x : ans)
    printf("%lld ",x);
  puts("");
	return 0;
}