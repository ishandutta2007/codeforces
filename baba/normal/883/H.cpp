//TooWeakTooSlow
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


int main()
{
  int n;
  vector<char> even, odd;
  int cnt[255], ecnt, ocnt;
  REP(i,255){
    cnt[i] = 0;
  }
  si(n);
  char s[1000006];
  scanf("%s", s);
  REP(i, n){
    cnt[s[i]]++;
  }
  ecnt=0;
  ocnt=0;
  REP(i, 255){
    while(cnt[i] >= 2){
      even.PB(i);
      cnt[i]-=2;
      ecnt++;
    }
    if(cnt[i]){
      cnt[i]--;
      odd.PB(i);
      ocnt++;
    }
  }
  if(ocnt == 0){
    REP(i, SZ(even)){
      s[i] = even[i];
      s[n - 1 - i] = even[i];
    }
    printf("1\n%s\n", s);
    return 0;
  }
  int k;
  while(ecnt%ocnt != 0){
    char x = even[SZ(even) - 1];even.pop_back();
    odd.PB(x);
    odd.PB(x);
    ocnt+=2;
    ecnt--;
  }
  trace(ecnt, ocnt);
  k = ecnt/ocnt;
  printf("%d\n", ocnt);
  s[n/ocnt]='\0';
  while(SZ(odd)){
    REP(j, k){
      char x = even[SZ(even) - 1];even.pop_back();
      s[j] = x;
      s[2*k - j] = x;
    }
    s[k] = odd[SZ(odd) - 1];odd.pop_back();
    printf("%s ", s);
  }
  printf("\n");

  return 0;
}