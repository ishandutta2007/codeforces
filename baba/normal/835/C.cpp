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

const int N = 101;
int PS[11][N][N];
int main()
{
  int n,q,c;
  si(n);si(q);si(c);
  for(int i=1;i<=n;i++){
    int x,y,s;
    si(x);si(y);si(s);
    PS[s][x][y]++;
  }
  REP(i,11)
    for(int j=1;j<N;j++)
      for(int k=1;k<N;k++){
        PS[i][j][k] += PS[i][j-1][k] + PS[i][j][k-1] - PS[i][j-1][k-1];
      }
  while(q--){
    int t,x1,y1,x2,y2;
    si(t);si(x1);si(y1);si(x2);si(y2);
    LL ans = 0;
    for(int i=0;i<=10;i++){
      int cnt = PS[i][x2][y2] - PS[i][x2][y1-1] - PS[i][x1-1][y2] + PS[i][x1-1][y1-1];
      ans += (t + i)%(c + 1) * 1ll * cnt;
    }
    lldout(ans);
  }
	return 0;
}