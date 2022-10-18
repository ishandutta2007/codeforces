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
const int N = int(2e5)+10;
const int M = int(4e5)+10;
int U[M],V[M],vis[N],ans[N],cno,C[N],len,canS[N],canT[N];
VI g[N];
int adj(int u,int e){
  return U[e]^V[e]^u;
}
void dfs(int u,int ee){
  vis[u]=1;C[u]=cno;
  if(ee)ans[++len] = ee;
  for(auto e : g[u]){
    int w = adj(u,e);
    if(vis[w])continue;
    dfs(w,e);
  }
}
int main()
{
  int n,m;
  si(n);si(m);
  for(int i=1;i<=m;i++){
    scanf("%d %d",U+i,V+i);
    g[U[i]].PB(i);
    g[V[i]].PB(i);
//    trace(U[i],V[i],i);
  }
  int s,t,ds,dt;
  si(s);si(t);si(ds);si(dt);
  vis[s]=vis[t]=1;
  for(int i=1;i<=n;i++)
    if(!vis[i]){
      ++cno;
      dfs(i,0);
    }
  int st = 0;
  for(auto e : g[s]){
    int w = adj(s,e);
//    trace(e,s,w);
    if(w == t){
      st = e;
      continue;
    }
    canS[C[w]] = e;
  }
  for(auto e : g[t]){
    int w = adj(t,e);
   // trace(e,t,w);
    if(w == s)continue;
    canT[C[w]] = e;
  }
  int both = 0;
  for(int i=1;i<=cno;i++){
 //   trace(canS[i],canT[i]);
    if(canS[i] && canT[i])
      both++;
    else if(canS[i])
      ds--,ans[++len] = canS[i];
    else if(canT[i])
      dt--,ans[++len] = canT[i];
    else assert(false);
  }
 // trace(ds,dt);
  if(ds <= 0 || dt <= 0){
    puts("No");
    return 0;
  }
  if(ds + dt < both + 1){
    puts("No");
    return 0;
  }
  bool done=false;
  for(int i=1;i<=cno;i++)
    if(canS[i] && canT[i]){
      if(!done){
        assert(ds > 0 && dt > 0);
        ans[++len] = canS[i];
        ans[++len] = canT[i];
        ds--;dt--;done = true;
      }
      else if(ds > 0){
        ans[++len] = canS[i];ds--;
      }
      else if(dt > 0){
        ans[++len] = canT[i];dt--;
      }
      else assert(false);
    }
  if(!done && st){ans[++len] = st;ds--;dt--;done = true;}
  assert(done);
  puts("Yes");
  assert(len==n-1);
  for(int i=1;i<=len;i++){
    printf("%d %d\n",U[ans[i]],V[ans[i]]);
  }
	return 0;
}