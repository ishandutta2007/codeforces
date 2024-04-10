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

char str[1000006];
int n, k;
int dar[1000006], rightp[1000006], leftp[1000006], interest[1000006], r[1000006];
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

inline int dp(int x){
  if(x >= n || x<0)return 1;
  if(dar[x] != -1)return dar[x];
  int &ret = dar[x];
  int i;
  i = rightp[x];
  if(i < 0 || i >= n || x+k < i){
    return ret = 0;
  }
  if(i == x){
    if(r[i]+1 >= n || r[i] < 0){
      return ret = 1;
    }
    return ret = dp(interest[r[i]+1]);
  }
  if(i + 1 >= n){
    return ret = 1;
  }
  if(dp(interest[i + 1])){
    return ret = 1;
  }
  int j;
  j= rightp[i + 1];
  if(j >= n || j < 0 || x + k < j){
    return ret = 0;
  }
  if(leftp[(i+k)<n?(i + k):(n - 1)] == j){
    if(i + k + 1 >= n){
      return ret = 1;
    }
    return ret = dp(interest[i + k+ 1]);
  }
  if(r[i]+1 >= n){
    return ret = 1;
  }
  return ret = dp(interest[r[i]+1]);
}

int possib(){
  REP(i, n){
    dar[i] = -1;
  }
  int i, cur = -1;
  for(i = 0;i < n;i++){
    if(str[i] == 'P')cur = i;
    leftp[i] = cur;
  }
  for(i = n-1, cur = -1;i >=0;i--){
    if(str[i] == 'P')cur=i;
    rightp[i] = cur;
  }
  for(i = n-1, cur = -1;i >=0;i--){
    if(str[i] != '.')cur=i;
    interest[i] = cur;
  }
  for(i = n-1, cur = -1;i >=0;i--){
    if(str[i] == 'P'){
      if(i + k >= n){
        r[i] = n;
      }
      else{
        if(leftp[i + k]  >=0 && leftp[i+k] <n && leftp[i+k]> i){
          r[i] = r[leftp[i+k]];
        }
        else{
          r[i] = i + k;
        }
      }
    }
  }
  for(i = n - 1; i >= 0;i--){
    dp(interest[i]);
  }
  return dp(interest[0]);
}

int main()
{
  si(n);
  scanf("%s", str);
  int s, e, m;
  int cnt = 0;
  REP(i, n){
    if(str[i] == 'P')cnt++;
  }
  if(cnt == 1){
    //later
    int idx;
    REP(i, n){
      if(str[i] == 'P')idx=i;
    }
    int leftc, leftt, rightc, rightt;
    int i;
    leftc = 0;
    rightc = 0;
    for(i = 0;(idx-i) >= 0;i++){
      if(str[idx-i] == '*'){
        leftc++;
        leftt = i;
      }
    }
    for(i = 0;(idx+i) < n;i++){
      if(str[idx+i] == '*'){
        rightc++;
        rightt = i;
      }
    }
    if(leftc > rightc){
      printf("%d %d\n", leftc, leftt);
    }
    else if(leftc < rightc){
      printf("%d %d\n", rightc, rightt);
    }
    else{
      printf("%d %d\n", leftc, min(leftt, rightt));
    }
    return 0;
  }
  s= 1;
  e = n;
  cnt =0;
  REP(i, n){
    if(str[i] == '*')cnt++;
  }
  while(s < e){
    m = (s+e)/2;
    k = m;
    if(possib()){
      e = m;
    }
    else{
      s = m + 1;
    }
  }
  printf("%d %d\n", cnt, s);
  return 0;
}