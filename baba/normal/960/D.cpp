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

//#define TRACE

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
const int N = 64;
int lvl(LL x){
  int ret = 0;
  while(x > 1){
    x >>= 1;
    ret++;
  }
  return ret;
}
LL cnt[N], shift[N][2], st[N];
LL getNode(LL x, int l){
  x = x - st[l] + shift[l][1];
  x = (x + cnt[l]) % cnt[l];
  x = x + st[l];
  return x;
}
LL getVal(LL x, int l){
  x = x - st[l] - shift[l][0];
  x = (x + cnt[l]) % cnt[l];
  x = x + st[l];
  return x;
}
int main()
{
  trace(lvl(LL(1e18)));
  REP(i, N){
    cnt[i] = 1LL << i;
    st[i] = (i ? st[i - 1] + cnt[i - 1] : 1);
  }
  int q;si(q);
  while(q--){
    int t;si(t);
    if(t == 1){
      LL x, k;
      sll(x);sll(k);
      int l = lvl(x);
      int sign = k < 0 ? -1 : +1;
      k = abs(k) % cnt[l];
      shift[l][0] += sign * k;
      shift[l][0] = (shift[l][0] + cnt[l]) % cnt[l];
    }
    if(t == 2){
      LL x, k;
      sll(x);sll(k);
      int l = lvl(x);
      int sign = k < 0 ? -1 : +1;
      k = abs(k) % cnt[l];
      trace(x, l, k, sign);
      shift[l][1] += sign * k;
      shift[l][1] = (shift[l][1] + cnt[l]) % cnt[l];
      trace(t, shift[l][0], shift[l][1]);
    }
    if(t == 3){
      LL x; sll(x);
      int l = lvl(x);
      x = (x + shift[l][0] - st[l]) % cnt[l] + st[l];
      for(; l >= 0; l--){
        trace(x, l, shift[l][0], shift[l][1]);
        printf("%lld ", getVal(x, l));
        x = getNode(x, l);
        trace(x, l);
        x >>= 1;
      }
      puts("");
    }
  }
	return 0;
}