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

VI idx[302];
int len;
const int inf = 301;
int main()
{
  int n;si(n);
  int noOvertake = 0;
  int ans = 0;
  idx[inf].PB(++len);
  int speed = 0;
  for(int i=1;i<=n;i++){
    int t;si(t);
    if(t == 1){
      int x;si(x);
      speed = x;
    }
    if(t == 2){
      ans += noOvertake;
      noOvertake = 0;
    }
    if(t == 3){
      int s;si(s);
      idx[s].PB(++len);
    }
    if(t == 4){
      noOvertake = 0;
    }
    if(t == 5){
      for(int i=0;i<inf;i++)
        idx[i].clear();
      idx[inf].PB(++len);
    }
    if(t == 6){
      noOvertake++;
    }
    int mx = 0;
    for(int j=speed;j<=inf;j++)
      mx = max(mx,idx[j].empty() ? 0 : idx[j].back());
    for(int j = speed - 1; j >= 0; j--){
      while(!idx[j].empty() && idx[j].back() > mx){
        ans++;
        idx[j].pop_back();
      }
    }
  }
  dout(ans);
  return 0;
}