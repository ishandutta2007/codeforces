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
const int N = 2*int(3e5)+10;
char s[N];
int root[N][26],C[N],DD[N],D[N],sub[N];
VI g[N];
inline void merge(int a,int b){
  for(int i=0;i<26;i++)
    if(root[a][i] && root[b][i])
      merge(root[a][i],root[b][i]);
    else if(root[a][i] && !root[b][i])
      root[b][i] = root[a][i];
  DD[b]=0;
  for(int i=0;i<26;i++)
    if(root[b][i])
      DD[b]+=1 + DD[root[b][i]];
}
inline void dfs(int u,int p=1){
  sub[u]=1;
  for(auto w:g[u])
    if(w!=p)
      dfs(w,u),
      sub[u]+=sub[w];
  int mx = 0;
  for(auto w:g[u])
    if(w!=p && sub[w] > sub[mx])
      mx = w;
  if(!mx)return void((root[u][s[u]-'a'] = N-u,D[u]=DD[u]=1));
  for(auto w:g[u])
    if(w!=p && w!=mx)
      merge(w,mx);
  root[u][s[u]-'a'] = mx;
  D[u] = DD[u] = DD[mx] + 1;
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++)si(C[i]);
  scanf("%s",s+1);
  for(int i=2;i<=n;i++){
    int u,v;
    si(u);si(v);
    g[u].PB(v);
    g[v].PB(u);
  }
  dfs(1);
  int ans = 0;
  for(int i=1;i<=n;i++)
    if(D[i]+C[i]>ans)
      ans = D[i]+C[i];
  dout(ans);
  int cnt = 0;
  for(int i=1;i<=n;i++)
    if(D[i]+C[i]==ans)
      cnt++;
  dout(cnt);
	return 0;
}