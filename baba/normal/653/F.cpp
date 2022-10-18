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
namespace SuffixTree{
  const int INF = 1e9;
  const int MAXN = 1e6 + 10;
  const int dollar = 257;
  int s[MAXN];
  map<int, int> to[MAXN];
  int len[MAXN]={INF}, fpos[MAXN], link[MAXN],suff[MAXN],par[MAXN];
  int node, pos, remain;
  int sz = 1, n = 0;
  int make_node(int _pos, int _len,int _par){
    fpos[sz] =  _pos;
    len [sz] = _len;
    suff[sz] = n - remain;
    par[sz] = _par;
    return sz++;
  }
  void go_edge(){
    while(pos > len[to[node][s[n - pos]]]){
      node = to[node][s[n - pos]];
      pos -= len[node];
    }
  }
  void add_letter(int c){
    s[n++] = c;int last = 0;
    for(remain++,pos++;pos > 0;remain--){
      go_edge();
      int edge = s[n - pos];
      int &v = to[node][edge];
      int t = s[fpos[v] + pos - 1];
      if(v == 0){
        v = make_node(n - pos, INF,node);
        link[last] = node;
        last = 0;
      }
      else if(t == c){
        link[last] = node;
        return;
      }
      else{
        int u = make_node(fpos[v], pos - 1,node);
        to[u][c] = make_node(n - 1, INF,u);
        to[u][t] = v;par[v] = u;
        fpos[v] += pos - 1;
        len [v] -= pos - 1;
        v = u;
        link[last] = u;
        last = u;
      }
      if(node == 0) pos--;
      else node = link[node];
    }
  }
}
const int N = int(5e5)+10;
char s[N];
int PS[N],n;
VI ST[4*N];
void build(int l=0,int r=n,int x=1){
  if(l == r - 1)return void(ST[x].PB(l));
  int m = (l + r)/2;
  int lc = x << 1;
  int rc = (x << 1) | 1;
  build(l,m,lc);
  build(m,r,rc);
  int i=0,j=0;
  while(i<SZ(ST[lc]) && j < SZ(ST[rc]))
    if(PS[ST[lc][i]] <= PS[ST[rc][j]])ST[x].PB(ST[lc][i++]);
    else ST[x].PB(ST[rc][j++]);
  while(i < SZ(ST[lc]))ST[x].PB(ST[lc][i++]);
  while(j < SZ(ST[rc]))ST[x].PB(ST[rc][j++]);
}
int queryMin(int L,int R,int l=0,int r=n,int x=1){
  if(l >= L && r <= R)return ST[x][0];
  if(r <= L || R <= l)return -1;
  int m = (l + r) / 2;
  int lc = x << 1;
  int rc = lc | 1;
  int la = queryMin(L,R,l,m,lc);
  int ra = queryMin(L,R,m,r,rc);
  if(la == -1 || ra == -1)return la == -1 ? ra : la;
  if(PS[la] <= PS[ra])return la;
  return ra;
}
bool cmp1(int i,int j){
  return i < PS[j];
}
bool cmp2(int i,int j){
  return PS[i] < j;
}
int queryCnt(int L,int R,int v,int l=0,int r=n,int x=1){
  if(r <= L || R <= l)return 0;
  if(l >= L && r <= R)
    return upper_bound(ALL(ST[x]),v,cmp1) - lower_bound(ALL(ST[x]),v,cmp2);
  int m = (l + r) / 2;
  int lc = x << 1;
  int rc = lc | 1;
  return queryCnt(L,R,v,l,m,lc) + queryCnt(L,R,v,m,r,rc);
}
int queryIdx(int L,int R,int v,int l=0,int r=n,int x=1){
  if(r <= L || R <= l)return -1;
  if(l >= L && r <= R){
    int pos = upper_bound(ALL(ST[x]),v-1,cmp1) - ST[x].begin() - 1;
    if(pos < 0)return -1;
    return *lower_bound(ALL(ST[x]),v-1,cmp2);
  }
  int m = (l + r) / 2;
  int lc = x << 1;
  int rc = lc | 1;
  int la = queryIdx(L,R,v,l,m,lc);
  if(la != -1)return la;
  return queryIdx(L,R,v,m,r,rc);
}
int getSum(int l,int r){
  return PS[r] - (l ? PS[l-1] : 0);
}
LL dfs(int x,int s=0){
  LL ret = 0;
  for(auto it : SuffixTree::to[x]){
    int y = it.S;
    int l = SuffixTree::fpos[y];
    int r = min(n - 1,l + SuffixTree::len[y] - 1);
    if(l > r)continue;
    int idx = queryMin(l,r+1), add = getSum(l,r), sub = l ? PS[l-1] : 0;
    int new_r = queryIdx(l,r+1,sub - s);
    if(s + PS[idx] - sub == 0)
      ret += queryCnt(l,r+1,PS[idx]);
    else if(s + PS[idx] - sub < 0)
      ret += queryCnt(l,new_r,sub - s);
    if(s + PS[idx] - sub < 0)continue;
    ret += dfs(y,s + add);
  }
  return ret;
}
int main()
{
  si(n);
  scanf("%s",s);
  REP(i,n)SuffixTree::add_letter(s[i]);
  SuffixTree::add_letter(SuffixTree::dollar);
  s[n] = '$';
  REP(i,n)PS[i] += (i ? PS[i-1]:0) + (s[i] == '(' ? +1 : -1);
  build();
  lldout(dfs(0));
	return 0;
}