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

const int N = int(2e5)+10;
int ST[4 * N],A[N];
#define lc (x << 1)
#define rc (x << 1) | 1
void update(int p,int v,int l=0,int r=N,int x=1){
  if(r <= p || l > p)return;
  if(l == r - 1)return void(ST[x] = v);
  int mid = (l + r) >> 1;
  update(p,v,l,mid,lc);
  update(p,v,mid,r,rc);
  ST[x] = max(ST[lc],ST[rc]);
}
int query(int L, int R,int l=0,int r=N,int x=1){
  if(l >= L && r <= R)return ST[x];
  if(r <= L || l >= R)return -1;
  int mid = (l + r) >> 1;
  return max(query(L,R,l,mid,lc),query(L,R,mid,r,rc));
}
int vis[N];
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++)si(A[i]);
  for(int i=1;i<=n;i++)update(i,A[i]);
  auto nxt = [&](int idx){
    int l = idx+1, r = n, ans = n + 1;
    while(l <= r){
      int mid = (l + r) >> 1;
      if(query(l,mid+1) > A[idx]){
        ans = mid;
        r = mid - 1;
      }
      else l = mid + 1;
    }
    update(ans, -1);
    return ans;
  };
  for(int i=1;i<=n;i++){
    if(vis[i])continue;
    for(int j = i; j <= n; j = nxt(j)){
      printf("%d ",A[j]);
      vis[j] =1;
    }
    puts("");
  }
	return 0;
}