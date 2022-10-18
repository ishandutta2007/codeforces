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

int main()
{
  int n,k;
  si(n);si(k);
  int two = 0, four = 0, ones = 0;
  for(int i=1;i<=k;i++){
    int x;si(x);
    if(x / 4){
      four += x / 4;
      x = x % 4;
    }
    if(x / 2){
      two += x / 2;
      x = x % 2;
    }
    ones += x;
  }
  while(four > n){
    two += 2;
    four--;
  }
  while(four < n && two > 2 * n){
    four++;
    two--;
    ones--;
  }
  while(two > 2 * n){
    two--;
    ones += 2;
  }
  while(two < 2 * n && ones > 0){
    two++;
    ones--;
  }
  while(four < n && ones > 0){
    four++;
    ones -= 2;
  }
  puts(ones > 0 ? "NO" : "YES");





	return 0;
}