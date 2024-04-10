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
const int N = int(1e3)+10;
const int M = int(2e5)+10;
int U[M],V[M],dp[N][N],ans[M];
VI qq[M];
struct query{
  int l,r,s,t;
}Q[M];
int main()
{
  int n,m,q;
  si(n);si(m);si(q);
  for(int i=1;i<=m;i++)
    scanf("%d %d",U+i,V+i);
  for(int i=1;i<=q;i++){
    scanf("%d %d %d %d",&Q[i].l,&Q[i].r,&Q[i].s,&Q[i].t);
    qq[Q[i].r].PB(i);
  }
  for(int i=1;i<=m;i++){
    int a = U[i],b = V[i];
    for(int j=1;j<=n;j++){
      dp[a][j] = max(dp[a][j],dp[b][j]);
      dp[b][j] = max(dp[b][j],dp[a][j]);
    }
    dp[a][b]=dp[b][a]=i;
    for(auto j : qq[i])
      if(dp[Q[j].t][Q[j].s] >= Q[j].l)
        ans[j]=1;
  }
  for(int i=1;i<=q;i++)
    puts(ans[i]?"Yes":"No");
	return 0;
}