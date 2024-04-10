//Tanuj Khattar
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define fpos fposs
const int INF = 1e9,N = 1e6 + 10;
namespace SuffixTree{//O(Nlog(Sigma)) construction & use.
  const int dollar = 257;//set
  int s[N];//dollar = 1 + MaxSigma. Ascii in this case
  map<int, int> to[N];//to[from]:(char,to_node).Just like
  int len[N]={INF},fpos[N],link[N],suff[N],par[N];//tries
  int node, pos, remain;//root node = 0.par[node]:mainly 
  int sz = 1, n = 0;//valid for leaf nodes.(not much use).
  int make_node(int _pos, int _len,int _par){//fpos[node]:  
    fpos[sz] =  _pos;len[sz] = _len;//the leftmost index of 
    suff[sz] = n - remain;par[sz] = _par;//the substring
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
//current prefix sum >= 0.BTW use ST only if you need to :P
string in;
int idx[N], node[N], ans[N], sub[N], dollar[N], t; 
vector<pair<int, II>> queries[N];
int len(int x){
  int ln = SuffixTree::len[x], sf = SuffixTree::fpos[x];
  if(ln > INF / 2){
    return dollar[sf] - sf + 1;
  }
  else return ln;
}
void dfs(int x, int p){
  if(x && SuffixTree::len[x] > INF / 2){
    int v = idx[SuffixTree::suff[x]];
    if(v != -1 && len(x) == 1)
      node[v] = p;
  }
  sub[x] = 1;
  for(auto it : SuffixTree::to[x]){
    dfs(it.S, x);
    sub[x] += sub[it.S];
  }
}
typedef tree<II,
  null_type,
  less<II>,
  rb_tree_tag,
  tree_order_statistics_node_update>
  ordered_set;

void dfs1(int x, ordered_set &v){
  if(x && SuffixTree::len[x] > INF / 2){
    int sf = SuffixTree::suff[x];
    if(dollar[sf] == sf)return;
    v.insert({SuffixTree::s[dollar[sf]] - SuffixTree::dollar, t++});
  }
  int mx = -1;
  for(auto it : SuffixTree::to[x]){
    int y = it.S;
    if(mx == -1 || sub[mx] < sub[y])
      mx = y;
  }
  if(mx == -1)return;
  dfs1(mx, v);
  for(auto it : SuffixTree::to[x]){
    int y = it.S;
    if(y == mx)continue;
    ordered_set temp;
    dfs1(y, temp);
    for(auto x : temp)
      v.insert(x);
  }
  for(auto it : queries[x]){
    int i = it.F, l = it.S.F, r = it.S.S;
    ans[i] = v.order_of_key({r+1, 0}) - v.order_of_key({l, 0});
  }
}
int main()
{
  int n;si(n);
  int q;si(q);
  SET(idx, -1);
  SET(node, -1);
  REP(i, n){
    string s;cin>>s;
    idx[SZ(in)] = i;
    REP(j, SZ(s)){
      dollar[SZ(in) + j] = SZ(in) + SZ(s);
      SuffixTree::add_letter(s[j]);
    }
    dollar[SZ(in) + SZ(s)] = SZ(in) + SZ(s);
    SuffixTree::add_letter(SuffixTree::dollar + i);
    in += s + "$";
  }
  dfs(0, -1);
  REP(i, q){
    int l, r, k;
    si(l);si(r);si(k);
    l--;r--;k--;
    if(node[k] == -1){
      ans[i] = k >= l && k <= r;
      continue;
    }
    queries[node[k]].PB({i, {l, r}});
  }
  ordered_set temp;
  dfs1(0, temp);
  REP(i, q)dout(ans[i]);
	return 0;
}