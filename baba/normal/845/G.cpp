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

//Blatantly copied since I have seen this problem many times but never cared enough to learn how it works. :( 
//This time I will surely learn it!! :-/ 
const int MAXN = 100005;
int col[MAXN], val[MAXN];
vector <int> A[MAXN], basis[MAXN];
vector < pair<int,int> > G[MAXN];
void dfs(int pos){
  for (int i = 0; i < G[pos].size(); ++i){
    int v = G[pos][i].first, w = G[pos][i].second;
    if(col[v]){
      A[col[v]].push_back((val[pos]^val[v]^w));
      continue;
    }
    col[v] = col[pos];
    val[v] = (val[pos]^w);
    dfs(v);
  }
}
void gaussian(vector <int> &S, vector <int> &B)
{
  int row = 0, col = 29;
  while(col >= 0 && row < S.size()){
    for (int i = row; i < S.size(); ++i)
      if((S[i] & (1<<col))){
        swap(S[row],S[i]);
        break;
      }
    if(!(S[row] & (1<<col))){
      col--;
      continue;
    }
    for (int i = 0; i < S.size(); ++i){
      if(i == row)
        continue;
      if((S[i] & (1<<col)))
        S[i]^=S[row];
    }
    col--;
    row++;
  }
  for (int i = 0; i < row; ++i)
    B.push_back(S[i]);
}
int main()
{
  int n,m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i){
    int u,v,w;
    scanf("%d %d %d", &u, &v, &w);
    G[u].push_back(make_pair(v,w));
    G[v].push_back(make_pair(u,w));
  }
  col[1] = 1;
  dfs(1);
  for (int i = 1; i <= n; ++i)
    gaussian(A[i],basis[i]);
  int ans = (val[1]^val[n]);
  for (int i = 0; i < basis[col[1]].size(); ++i)
    if((ans^basis[col[1]][i]) < ans)
      ans^=basis[col[1]][i];
  printf("%d\n", ans);
  return 0;
}