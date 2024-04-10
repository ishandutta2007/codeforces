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

const int N = 252;
char s[N][N];
LL ans[N][N];
int vis[N][N],n,m,q,p,len;
II temp[N * N];
int dx[] = {+1,-1,0,0}, dy[] = {0,0,+1,-1};
bool ok(int i,int j){
  return i >= 1 && i <= n && j >= 1 && j <= m;
}
void bfs(int x,int y,LL val){
  queue<pair<II,LL>> Q;
  vis[x][y] = 1;
  temp[len++] = {x,y};
  Q.push({{x,y},val});
  while(!Q.empty()){
    auto top = Q.front();Q.pop();
    int x = top.F.F, y = top.F.S;
    LL val = top.S;
    if(val == 0)continue;
    if(s[x][y] == '*')continue;
    ans[x][y] += val;
    REP(i,4){
      int p = x + dx[i], q = y + dy[i];
      if(!ok(p,q))continue;
      if(vis[p][q])continue;
      vis[p][q] = 1;
      temp[len++] = {p,q};
      Q.push({{p,q},val/2});
    }
  }
}
int main()
{
  si(n);si(m);si(q);si(p);
  for(int i=1;i<=n;i++)
    scanf("%s",s[i]+1);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(s[i][j] >= 'A' && s[i][j] <= 'Z'){
        bfs(i,j,(s[i][j] - 'A' + 1)  * q);
        REP(i,len)vis[temp[i].F][temp[i].S] = 0;
        len = 0;
      }
  int cnt = 0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(ans[i][j] > p)
        cnt++;
  dout(cnt);
  return 0;
}