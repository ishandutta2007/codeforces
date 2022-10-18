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
namespace SuffixTree{//O(Nlog(Sigma)) construction & use.
  const int INF = 1e9,N = 1e6 + 10,dollar = 257;//set
  int s[N];//dollar = 1 + MaxSigma. Ascii in this case
  map<int, int> to[N];//to[from]:(char,to_node).Just like
  int len[N]={INF},fpos[N],link[N],suff[N],par[N];//tries
  int node, pos, remain;//root node = 0.par[node]:mainly
  int sz = 1, n = 0;//valid for leaf nodes.(not much use).
  void init(){
    REP(i,max(sz,n)){
      len[i]=fpos[i]=link[i]=suff[i]=par[i]=s[i]=0;
      to[i].clear();
    }
    node=pos=remain=0;
    sz=1;n=0;len[0]=INF;
  }
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
//current prefix sum >=0.BTW use ST only if you need to :P

const int N = int(1e5)+10;
char s[N];
int n;
LL ans = 0;
LL dfs(int x){
  LL ret = (SuffixTree::len[x] > n);
  for(auto it : SuffixTree::to[x]){
    int y = it.S;
    int sub = dfs(y);
    int L = SuffixTree::fpos[y], R = min(n-1,L+SuffixTree::len[y]-1);
    int num = max(0,R - L + 1); 
    ret += sub;
    ans += sub * 1ll * sub * 1ll * num;
  }
  return ret;
}
int main()
{
  int t;si(t);
  while(t--){
    scanf("%s",s);
    n = strlen(s);
    SuffixTree::init();
    REP(i,n)SuffixTree::add_letter(s[i]);
    SuffixTree::add_letter(SuffixTree::dollar);
    ans = 0;
    dfs(0);
    lldout(ans);
  }
	return 0;
}