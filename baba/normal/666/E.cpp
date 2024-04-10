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
const int INF = 1e9,N = 1.2e6 + 10, LOGN = 22, dollar = 257, MAX = 5e6;
#define fpos ffpos
int s[N], len[N]={INF}, fpos[N], suff[N], n, sz = 1;
map<int, int> to[N];
namespace SuffixTree{//O(Nlog(Sigma)) construction & use.
  //set dollar = 1 + MaxSigma.
  //#define fpos ffpos
  //Ascii in this case to[from]:(char,to_node).
  int link[N],par[N];//Just like tries
  int node, pos, remain;//root node = 0.par[node]:mainly 
  //valid for leaf nodes.(not much use).
  int make_node(int _pos, int _len,int _par){//fpos[node]:  
    fpos[sz] =  _pos;len[sz] = _len;//the leftmost index of 
    suff[sz] = n - remain;par[sz] = _par;//the substring
    if(sz == N - 1)exit(1);
    return sz++;//represented by the parent edge of node.
  }//len[node]:stores the length of the subtring of parent
  void go_edge(){//edge of the node.Note that for leaves, 
    while(pos > len[to[node][s[n - pos]]]){//len[node]=INF. 
      node = to[node][s[n - pos]];//The [L,R] of the parent
      pos -= len[node];//edge of a node can be computed as:
    }}//L=fpos[y],R=min(n-1,l+len[y]-1),where n=strlen(s).
  void add_letter(int c){//suff[node]:represents what is
    s[n++] = c;int last = 0;//the index of the suffix which
    for(remain++,pos++;pos > 0;remain--){//ends at this node.
      go_edge();//useful only for leaves, and when inserting
      int edge = s[n - pos];//concatenation of many strings 
      int &v = to[node][edge];//separeted by (dollar + i)
      int t = s[fpos[v] + pos - 1];//distinct separators.
      if(v == 0){//In case of multiple strings, note that 
        v = make_node(n - pos, INF,node);//a dollar can
        link[last] = node;//occur on an edge,so be careful 
        last = 0;//while traversing such edges. In general, 
      }else if(t == c){//do not traverse an edge having a
        link[last] = node;//dollar and add it's contribution
        return;//there itself coz only one usefull suffix 
      }else{//will be there in ths subtree of this node
        int u = make_node(fpos[v], pos - 1,node);//whose
        to[u][c] = make_node(n - 1, INF,u);//parent edge has
        to[u][t] = v;par[v] = u;//a dollar in it. This is so
        fpos[v] += pos - 1;//coz any suffix staring at < l 
        len [v] -= pos - 1;//would have traversed at least
        v = u;//one more dollar sign before, which is not 
        link[last] = u;//possible since this is the first
        last = u;//encountered dollar & any suffix starting
      }//at > r cannot traverse this dollar since all dollars
      if(node == 0) pos--;//are distinct. Only one suffix can
      else node = link[node];//start from [l,r] and be here 
    }//coz different suffixes will have different lengths.
  }//In general,be careful about adding contributions of egdes.
}//Ex:for distinct bracket substrings, check if a bracket seq
//ends on this edge,and if yes, where all?go forward only if
//current prefix sum >=0.BTW use ST only if you need to :P
int ST[MAX], IDX[MAX], L[MAX], R[MAX], blen;
map<int, int> val[MAX];
inline int update(int p, int v, int l, int r, int x){
  if(!(p >= l && p < r))return x;
  if(!x)x = ++blen;
  if(l == r - 1)return ((ST[x] += v, IDX[x] = l), x);
  int mid = (l + r) >> 1;
  L[x] = update(p, v, l, mid, L[x]);
  R[x] = update(p, v, mid, r, R[x]);
  ST[x] = max(ST[L[x]], ST[R[x]]);
  IDX[x] = ST[L[x]] >= ST[R[x]] ? IDX[L[x]] : IDX[R[x]];
  return x;
}
inline void update(int p, int v, int root){
  assert(root);
  val[root][p] += v;
  update(p, v, 1, 5e4 + 1, root);
}
inline II query(int a, int b, int l, int r, int x){
  if(r <= a || b <= l)return {0, 0};
  if(!x)return {0, 0};
  if(l >= a && r <= b)return {ST[x], IDX[x]};
  int mid = (l + r) >> 1;
  auto la = query(a, b, l, mid, L[x]);
  auto ra = query(a, b, mid, r, R[x]);
  return la.F >= ra.F ? la : ra;
}
inline II query(int a, int b, int root){
  return query(a, b, 1, 5e4 + 1, root);
}
int idx[N], DP[LOGN][N], level[N], node[N], depth[N], dollars[N], sub[N], next_tree;
II ans[N];
string S1, S2[N];
vector<int> pos[N];
vector<pair<int, II>> queries[N];
inline int getWeight(int x){
  if(len[x] > INF / 2)return dollars[fpos[x]] - fpos[x] + 1;
  return len[x];
}
inline int getKth(int x, int k){
  REP(i, LOGN)if((1 << i) & k)x = DP[i][x];
  return x;
}
inline int getAnc(int x, int len){
  int l = 0, h = n, ans = -1;
  while(l <= h){
    int mid = (l + h) >> 1;
    int v = getKth(x, mid);
    if(depth[v] >= len){
      ans = mid;
      l = mid + 1;
    }
    else h = mid - 1;
  }
  if(ans == -1)exit(1);
  return getKth(x, ans);
}
inline void dfs1(int x, int p){
  DP[0][x] = p;sub[x] = 1;
  if(x && len[x] > INF / 2){
    if(node[suff[x]])exit(1);
    node[suff[x]] = x;
  }
  for(auto it : to[x]){
    int y = it.S;
    level[y] = level[x] + 1;
    depth[y] = depth[x] + getWeight(y);
    dfs1(y, x);
    sub[x] += sub[y];
  }
}
string in;
inline void dfs2(int x, int sid){
  if(x && len[x] > INF / 2){
    if(!idx[suff[x]] || s[suff[x]] >= dollar)return;
    update(idx[suff[x]], 1, sid);
  }
  int mx = -1;
  for(auto it : to[x]){
    int y = it.S;
    if(mx == -1 || sub[y] > sub[mx])
      mx = y;
  }
  if(mx != -1)dfs2(mx, sid);
  for(auto it : to[x]){
    int y = it.S;
    if(y == mx)continue;
    int cval = ++blen;
    dfs2(y, cval);
    for(auto it : val[cval])update(it.F, it.S, sid);
  }
  for(auto it : queries[x]){
    int i = it.F, l = it.S.F, r = it.S.S;
    ans[i] = max(ans[i], query(l, r + 1, sid));
  }
}
int main()
{
  fast_io;
  cin >> S1;
  in += S1 + "$";
  REP(i, SZ(S1)){
    dollars[n] = SZ(S1);
    pos[0].PB(n);
    SuffixTree::add_letter(S1[i]);
  }
  dollars[n] = SZ(S1);
  SuffixTree::add_letter(dollar);
  int m;cin>>m;
  FOR(i, 1, m + 1){
    cin >> S2[i];
    in += S2[i] + "$";
    int dpos = n + SZ(S2[i]);
    REP(j, SZ(S2[i])){
      dollars[n] = dpos;
      pos[i].PB(n);
      idx[n] = i;
      SuffixTree::add_letter(S2[i][j]);
    }
    dollars[n] = dpos;
    idx[n] = i;
    SuffixTree::add_letter(dollar + i);
  }

  dfs1(0, 0);
  FOR(i, 1, LOGN)REP(j, sz)DP[i][j] = DP[i-1][DP[i-1][j]];
  int q; cin >> q;
  REP(i, q){
    int l, r, pl, pr;
    cin >> l >> r >> pl >> pr;
    pl--;pr--;
    if(!(node[pl] && depth[node[pl]] >= pr - pl + 1))exit(1);
    int x = getAnc(node[pl], pr - pl + 1);
    queries[x].PB({i, {l, r}});
    ans[i] = {0, l};
  }
  dfs2(0, ++blen);
  REP(i, q)printf("%d %d\n",ans[i].S, ans[i].F);
  return 0;
}