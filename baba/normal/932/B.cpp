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

const int N = 1e6 + 10;
int V[N], PS[10][N];
int main()
{
  REP(i, 10)V[i] = i;
  FOR(x, 10, N){
    int y = 1;
    for(int temp = x; temp; temp = temp / 10){
      int p = temp % 10;
      if(p)y = y * p;
    }
    assert(y < x);
    V[x] = V[y];
  }
  REP(t, 10)REP(i, N)if(V[i] == t)PS[t][i]++;
  REP(t, 10)FOR(i, 1, N)PS[t][i] += PS[t][i - 1];
  int q;si(q);
  while(q--){
    int l, r, k;
    si(l);si(r);si(k);
    dout(PS[k][r] - PS[k][l - 1]);
  }

	return 0;
}