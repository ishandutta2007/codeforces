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
const int N = int(1e5)+10;
VI g[N];
int C[N],cnt[N];
void dfs1(int u,int p){
  cnt[u]=C[u];
  for(auto w : g[u])
    if(w!=p){
      dfs1(w,u);
      if(C[u] != cnt[w])
        cnt[u] = -1;
    }
}
void dfs2(int u,int p,bool ok = true){
  int c = 0;
  for(auto w : g[u])
    if(w!=p && cnt[w] == -1)
      c++;
  if(c == 0){
    puts("YES");
    dout(u);
    exit(0);
  }
  else if(c > 1 || !ok){
    puts("NO");
    exit(0);
  }
  for(auto w : g[u])
    if(w!=p && cnt[w] != -1 && cnt[w] != C[u]){
      puts("NO");
      exit(0);
    }
  for(auto w : g[u])
    if(w != p && cnt[w] == -1)
      dfs2(w,u,C[u] == C[w]);
}
int main()
{
  int n;si(n);
  for(int i=1;i<n;i++){
    int u,v;
    si(u);si(v);
    g[u].PB(v);
    g[v].PB(u);
  }
  for(int i=1;i<=n;i++)si(C[i]);
  dfs1(1,0);
  dfs2(1,0);
  assert(false);
	return 0;
}