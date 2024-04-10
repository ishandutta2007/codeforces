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

const int N = int(5e3)+10;
const int INF = int(1e9)+10;
int d[N][N];
VI g[N];
int C[N],K[N],P[N],n,m,vis[N],Q[N],st,en,want[N];
void bfs(int s,int d[]){
  SET(vis,0);vis[s]=1;
  for(int i=1;i<=n;i++)
    d[i] = INF;
  d[s] = 0;
  st = en = 0;
  Q[++en] = s;
  while(st < en){
    int u = Q[++st];
    for(auto w : g[u]){
      if(!vis[w]){
        vis[w] = 1;
        d[w] = d[u] + 1;
        Q[++en] = w;
      }
    }
  }
}
int gg,r,a,A[N],len,w;
bool cmp(int i,int j){
  return P[i] < P[j];
}
bool ok(int t){
  int have = 0;
  int curcost = a;
  for(int i=1;i<=w;i++)
    if(d[gg][C[A[i]]] <= t){
      int take = min(K[A[i]],r - have);
      if((curcost + P[A[i]]) / P[A[i]] >= take)curcost = curcost - take * P[A[i]];
      else break;
      have += take;
    }
  return curcost >=0 && have == r;
}
int main()
{
  si(n);si(m);
  for(int i=1;i<=m;i++){
    int x,y;
    si(x);si(y);
    g[x].PB(y);
    g[y].PB(x);
  }
  si(w);
  for(int i=1;i<=w;i++){
    scanf("%d %d %d",C+i,K+i,P+i);
    A[i] = i;
  }
  sort(A+1,A+1+w,cmp);
  int q;si(q);
  while(q--){
    si(gg);si(r);si(a);
    if(!want[gg]){
      want[gg] = 1;
      bfs(gg,d[gg]);
    }
    int l = 0, h = n+1, ans = -1;
    while(l <= h){
      int m = (l + h) / 2;
      if(ok(m)){ans = m; h = m - 1;}
      else l = m + 1;
    }
    dout(ans);
  }
	return 0;
}