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

//#define TRACE

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
set<int> adj[2][100001];
int dx[] = {+1, -1, 0, 0}, dy[] = {0, 0, +1, -1};
bool check(int n, int m, VVI& orig, VVI& ans){
  REP(i, n * m)adj[0][i].clear(), adj[1][i].clear();
  auto f = [&](int idx, VVI &orig){
    REP(i, n)REP(j, m)REP(t, 4){
      int x = i + dx[t], y = j + dy[t];
      if(!(x >= 0 && x < n && y >= 0 && y < m))continue;
      adj[idx][orig[i][j]].insert(orig[x][y]);
    }
  };
  f(0, orig);f(1, ans);
  bool ok = true;
  REP(i, n * m){
    for(auto x : adj[0][i]){
      ok &= (adj[1][i].count(x) == 0);
    }
  }
  return ok;
}
VVI solve2(int n, int m){
  if(n == 4 && m == 3){
    return {
      {1, 3, 5, 2},
        {4, 6, 12, 9},
        {11, 8, 10, 7}};
  }
  if(n == 3 && m == 4){
    return {
      {1, 3, 4},
        {5, 7, 2},
        {11, 6, 8},
        {9, 10, 12}
    };
  }
  VVI ret(n, VI(m, 0)), orig(n, VI(m, 0));
  VI elem;
  REP(i, n * m)elem.PB(i);
  REP(i, n)REP(j, m)orig[i][j] = i * m + j;
  do{
    int i = 0, j = 0;
    for(auto x : elem){
      ret[i][j] = x;
      j++;if(j == m){
        i++; j = 0;
      }
    }
    if(check(n, m, orig, ret))return ret;
  }while(next_permutation(ALL(elem)));
  puts("NO");
  exit(0);
}
VVI solve(int n, int m){
  if(n <= 4 && m <= 4 && !(n == 4 && m == 4)){
    return solve2(n, m);
  }
  VI A, B;
  VVI ret(n, VI(m, 0));
  if(n >= m){
    REP(i, n)REP(j, m)if((i + j) & 1){
      A.PB(i * m + j);
    }
    else B.PB(i * m + j);
    //reverse(ALL(B));
    int i = 0, j = 0;
    for(auto x : A){
      ret[i][j] = x;
      j++;
      if(j == m){
        i++;j=0;
      }
    }
    for(auto x : B){
      ret[i][j] = x;
      j++;if(j == m){i++;j = 0;}
    }
  }
  else {
    REP(j, m)REP(i, n)if((i + j) & 1){
      A.PB(i * m + j);
    }
    else B.PB(i * m + j);
   // reverse(ALL(B));
    int i = 0, j = 0;
    for(auto x : A){
      ret[i][j] = x;
      i++;
      if(i == n){
        i=0;j++;
      }
    }
    for(auto x : B){
      ret[i][j] = x;
      i++;
      if(i == n){
        i=0;j++;
      }
    }
  }
  return ret;
}
int main()
{
  int n, m;
  si(n);si(m);
  auto ans = solve(n, m);
  puts("YES");
  VVI orig(n, VI(m, 0));
  REP(i, n)REP(j, m)orig[i][j] = i * m + j;
  REP(i, n)REP(j, m)printf("%d%s", ans[i][j] + 1, j == m - 1 ? "\n" : " ");
  assert(check(n, m, orig, ans));
  return 0;
}