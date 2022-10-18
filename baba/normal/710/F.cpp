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
const int N = int(6e5)+10;
const int B = 800;
const int sigma = 26;
struct SA{
  VVI to;
  VI dp,link,len,val;
  int last,sz;
  SA(){
    to.clear();dp.clear();link.clear();len.clear();val.clear();
    last=sz=0;
  }
  SA(int n){
    to = VVI(n,VI(sigma,0));
    dp = link = len = val = VI(n,0);
    last = sz = 0;
  }
  SA(string &s){
    int n = 2*SZ(s)+10;
    to = VVI(n,VI(sigma,0));
    dp = link = len = val = VI(n,0);
    last = sz = 0;
    for(auto c:s)
      add_letter(c-'a');
    go();
  }
  void add_letter(int c){
    int p = last;
    last = ++sz;
    len[last]=len[p]+1;
    for(;!to[p][c];p=link[p])to[p][c]=last;
    if(to[p][c]==last)return void(link[last]=0);
    int q = to[p][c];
    if(len[q] == len[p] + 1)return void(link[last]=q);
    int x = ++sz;
    to[x] = to[q];
    link[x]=link[q];len[x]=len[p]+1;
    link[last]=link[q]=x;
    for(;to[p][c]==q;p=link[p])to[p][c]=x;
  }
  void f(int x){
    if(dp[x])return;
    dp[x] = val[x];
    for(int i=0;i<sigma;i++)
      if(to[x][i]){
        f(to[x][i]),dp[x]+=dp[to[x][i]];
      }
  }
  void go(){
    int x = last;
    for(;x;x=link[x])
      val[x]+=1;
    f(0);
  }
  int get(string &s){
    int x = 0;
    for(auto cc:s){
      int c = cc-'a';
      if(!to[x][c])return 0;
      else x = to[x][c];
    }
    return dp[x];
  }
}sa;
struct trie{
  int to[N][sigma],val[N],sz;
  trie(){SET(to,0);sz=0;}
  void add_str(string &s,int add){
    int x = 0;
    for(auto cc:s){
      int c = cc-'a';
      if(!to[x][c])to[x][c] = ++sz;
      x = to[x][c];
    }
    val[x]+=add;
  }
  int get(string s){
    int ret=0,x=0;
    for(auto cc : s){
      int c = cc-'a';
      ret += val[x];
      if(!to[x][c])return ret;
      x = to[x][c];
    }
    ret+=val[x];
    return ret;
  }
}T;
string S[N];
bool P[N];
int len;
int main()
{
  fast_io;
  int m;cin>>m;
  for(int i=1;i<=m;i++){
    int t;string s;
    cin>>t>>s;
    if(t==3){
      LL ans = 0;
      for(int j=0;j<SZ(s);j++)
        ans += T.get(s.substr(j,B));
      sa = SA(s);
      for(int j=0;j<len;j++)
        if(SZ(S[j]) <= SZ(s))
          ans = ans + (P[j]?sa.get(S[j]):-sa.get(S[j]));
      cout<<ans<<endl;
      continue;
    }
    if(SZ(s)>=B){P[len] = t==1?1:0;S[len++] = s;}
    else T.add_str(s,t==1?+1:-1);
  }
  return 0;
}