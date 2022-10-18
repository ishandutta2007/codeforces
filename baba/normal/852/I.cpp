//TooMuchMath
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
const int LOGN = 20;
const int BLOCK = 500;
VI g[N];
int st[N],en[N],level[N],DP[LOGN][N],Time;
int who[N],f[N], ID[N];
map<int,int> mp;
struct query{
  int l, r, lc, id, bl;
}Q[N];
void dfs(int x, int p){
  st[x] = ++Time;
  ID[Time] = x;
  DP[0][x] = p;
  for(auto y : g[x]){
    if(y == p)continue;
    level[y] = level[x] + 1;
    dfs(y, x);
  }
  en[x] = ++Time;
  ID[Time] = x;
}
int lca(int a,int b){
  if(level[a] > level[b])swap(a,b);
  int d = level[b] - level[a];
  for(int i=0;i<LOGN;i++)
    if((1<<i) & d)
      b = DP[i][b];
  if(a == b)return a;
  for(int i=LOGN-1;i>=0;i--)
    if(DP[i][a] != DP[i][b])
      a = DP[i][a], b = DP[i][b];
  return DP[0][a];
}
int vis[N], sum[N][2];
LL cans, ans[N];
void go(int x){
  int c = f[x], b = who[x];
  if(vis[x]){
    cans -= sum[c][1 - b];
    sum[c][b]--;
  }
  else {
    cans += sum[c][1 - b];
    sum[c][b]++;
  }
  vis[x] ^= 1;
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++)si(who[i]);
  for(int i=1;i<=n;i++)si(f[i]),mp[f[i]];
  int len = 0;
  for(auto &it:mp)it.S = ++len;
  for(int i=1;i<=n;i++)f[i] = mp[f[i]];
  for(int i=1;i<n;i++){
    int a,b;
    si(a);si(b);
    g[a].PB(b);
    g[b].PB(a);
  }
  dfs(1,1);
  for(int i=1;i<LOGN;i++)
    for(int j=1;j<=n;j++)
      DP[i][j] = DP[i-1][DP[i-1][j]];
  int q;si(q);
  for(int i=1;i<=q;i++){
    int a,b;
    si(a);si(b);
    if(st[a] > st[b])swap(a,b);
    Q[i].lc = lca(a, b);
    Q[i].id = i;
    if(Q[i].lc == a){
      //case - 1
      Q[i].l = st[a];
      Q[i].r = st[b];
      Q[i].lc = -1;
    }
    else {
      //case - 2
      Q[i].l = en[a];
      Q[i].r = st[b];
    }
    Q[i].bl = Q[i].l / BLOCK;
  }
  sort(Q+1, Q+1+q, [](query a, query b){return (a.bl != b.bl) ? (a.bl < b.bl) : (a.r < b.r);});
  int L = 1, R = 0;
  for(int i=1;i<=q;i++){
    int l = Q[i].l, r = Q[i].r;
    while(R < r)go(ID[++R]);
    while(L > l)go(ID[--L]);
    while(R > r)go(ID[R--]);
    while(L < l)go(ID[L++]);
    if(Q[i].lc != -1){
      go(Q[i].lc);
      ans[Q[i].id] = cans;
      go(Q[i].lc);
    }
    else {
      ans[Q[i].id] = cans;
    }
  }
  for(int i=1;i<=q;i++)
    lldout(ans[i]);

	return 0;
}