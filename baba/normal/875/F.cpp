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
int U[N], V[N], W[N], E[N], dsu[N];
bool fucked[N];
int Find(int x){
  return dsu[x] = dsu[x] == x ? x : Find(dsu[x]);
}
bool Union(int a, int b){
  a = Find(a); b = Find(b);
  if(a == b){
    bool ret = !fucked[a];
    fucked[a] = true;
    return ret;
  }
  if(fucked[a] && fucked[b])return false;
  dsu[a] = b;
  fucked[b] |= fucked[a];
  return true;
}
int main()
{
  int n;si(n);
  int m;si(m);
  REP(i, m){
    E[i] = i;
    scanf("%d %d %d", U + i, V + i, W + i);
  }
  FOR(i, 1, n + 1)dsu[i] = i;
  sort(E, E + m, [](int a, int b){return W[a] > W[b];});
  int ans = 0;
  REP(i, m)
    if(Union(U[E[i]], V[E[i]]))
      ans += W[E[i]];
  dout(ans);
	return 0;
}