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

int ASK(vector<int>& ask){
  if(ask.empty())return 0;
  printf("? %d ",SZ(ask));
  for(auto x : ask)
    printf("%d ",x);
  fflush(stdout);
  int v;si(v);
  return v;
}
VI get_ask(int p,int idx,int n){
  int num = (1 << 10) - 1;
  num ^= (1 << idx) - 1;
  assert((p & num) == p);
  VI ask;
  for(int i=1;i<=n;i++)
    if((i & num) == p)
      ask.push_back(i);
  return ask;
}
int main()
{
  int n,x,y;
  si(n);si(x);si(y);
  int common = 0, idx = -1;
  for(int i=9;i>=0;i--){
    vector<int> ask;
    for(int k=1;k<=n;k++){
      if(!(k & (1 << i))){
        ask.push_back(k);
      }
    }
    int v = ASK(ask);
    if(v == 0 || v == x){
      continue;
    }
    else {
      for(int j=9;j>i;j--){
        VI newask;
        VI alt;
        for(auto x : ask)
          if(!(x & (1 << j)))
            newask.push_back(x);
          else alt.push_back(x);
        int v = ASK(newask);
        if(v == 0 || v == x){
          common |= (1 << j);
          ask = alt;
        }
        else {
          ask = newask;
        }
      }
      idx = i;
      break;
    }
  }
  assert(idx != -1);
  int p1 = common, p2 = common | (1 << idx);
  //for p1
  {
    VI ask = get_ask(p1,idx,n);
    for(int i = idx-1;i>=0;i--){
      VI newask,alt;
      for(auto x : ask){
        if(!(x & (1 << i)))newask.push_back(x);
        else alt.push_back(x);
      }
      int v = ASK(newask);
      if(v == 0 || v == x){
        p1 |= (1 << i);
        ask = alt;
      }
      else{
        ask = newask;
      }
    }
  }
  swap(p1,p2);
  {
    VI ask = get_ask(p1,idx,n);
    for(int i = idx-1;i>=0;i--){
      VI newask,alt;
      for(auto x : ask){
        if(!(x & (1 << i)))newask.push_back(x);
        else alt.push_back(x);
      }
      int v = ASK(newask);
      if(v == 0 || v == x){
        p1 |= (1 << i);
        ask = alt;
      }
      else{
        ask = newask;
      }
    } 
  }
  swap(p1,p2);
  printf("! %d %d\n",p1,p2);
  fflush(stdout);
  return 0;
}