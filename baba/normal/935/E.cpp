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

const int N = 1e4 + 10;
const int K = 1e2 + 10;
const int INF = 1e9;
VI g[N];
char s[N];
int n, buff, val[N], P, M, dp[N][K][2], op;
int eval(int a, int b, int op, int tp){
  if(abs(a) == INF || abs(b) == INF){
    return tp ? INF : -INF;
  }
  if(op == 0)return a + b;
  else if(op == 1) return a - b;
  assert(false);
  return 0;
}
int constructTree(int l, int r){
  assert(l <= r);
  if(l == r){
    assert(s[l] >= '0' && s[l] <= '9');
    val[++buff] = s[l] - '0';
    return buff;
  }
  assert(s[l] == '(' && s[r] == ')');
  int op = 0;
  FOR(i, l, r + 1){
    if(s[i] == '(')op++;
    if(s[i] == ')')op--;
    if(s[i] == '?' && op == 1){
      int cnode = ++buff;
      int lc = constructTree(l + 1, i - 1);
      int rc = constructTree(i + 1, r - 1);
      g[cnode].PB(lc);
      g[cnode].PB(rc);
      return cnode;
    }
  }
  assert(false);
  return 0;
}
void dfs(int x){
  if(g[x].empty()){
    //leaf node
    REP(k, K)dp[x][k][0] = -INF;
    REP(k, K)dp[x][k][1] = +INF;
    dp[x][0][0] = dp[x][0][1] = val[x];
    return;
  }
  assert(SZ(g[x]) == 2);
  int lc = g[x][0], rc = g[x][1];
  dfs(lc);dfs(rc);
  REP(k, min(P, M) + 1){
    //case - 1 : place opposite type here.
    dp[x][k][0] = -INF;
    dp[x][k][1] = +INF;
    REP(left, k + 1){
      REP(t2, 2)REP(t3, 2){
        dp[x][k][0] = max(dp[x][k][0], eval(dp[lc][left][t2], dp[rc][k - left][t3], 1 - op, 0));
        dp[x][k][1] = min(dp[x][k][1], eval(dp[lc][left][t2], dp[rc][k - left][t3], 1 - op, 1));
      }
    }
    //case - 2 : place the same type here.
    REP(left, k){
      REP(t2, 2)REP(t3, 2){
        dp[x][k][0] = max(dp[x][k][0], eval(dp[lc][left][t2], dp[rc][k - left - 1][t3], op, 0));
        dp[x][k][1] = min(dp[x][k][1], eval(dp[lc][left][t2], dp[rc][k - left - 1][t3], op, 1));
      }
    }
  }
}
int main()
{
  scanf("%s", s);
  n = strlen(s);
  int root = constructTree(0, n - 1);
  si(P);si(M);
  if(P < M)op = 0;
  else op = 1;
  dfs(root);
  dout(dp[root][min(P, M)][0]);
	return 0;
}