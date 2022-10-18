//Mobius_Treap
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
const int N = int(1e6)+10;
int ST[4*N],rev[N],A[N],len,ans[N],last[N],n,PS[N];
map<int,int> mp;
pair<II,int>Q[N];
void update(int pos,int s,int l=1,int r=n+1,int x=1){
  if(!(pos>=l && pos<r))return;
  if(l==r-1){
    ST[x] = rev[A[pos]]*s;
    return;
  }
  int m = (l+r)/2;
  int lc = 2*x;
  int rc = 2*x+1;
  update(pos,s,l,m,lc);
  update(pos,s,m,r,rc);
  ST[x] = ST[lc] ^ ST[rc];
}
int query(int L,int R,int l=1,int r=n+1,int x=1){
  if(l>=R || r<=L)return 0;
  if(l>=L && r<=R)return ST[x];
  int m = (l+r)/2;
  int lc = 2*x;
  int rc = 2*x+1;
  int la = query(L,R,l,m,lc);
  int ra = query(L,R,m,r,rc);
  return la^ra;
}
int main()
{
  si(n);
  for(int i=1;i<=n;i++){
    si(A[i]);mp[A[i]];
    PS[i]=PS[i-1]^A[i];
  }
  for(auto &it:mp){
    it.S = ++len;
    rev[it.S]=it.F;
  }
  for(int i=1;i<=n;i++)
    A[i]=mp[A[i]];
  int m;si(m);
  for(int i=1;i<=m;i++){
    si(Q[i].F.S);si(Q[i].F.F);
    Q[i].S=i;
  }
  sort(Q+1,Q+m+1);
  int st = 1;
  for(int i=1;i<=m;i++){
    int idx = Q[i].S;
    int l = Q[i].F.S,r = Q[i].F.F;
    while(st <= r){
      if(last[A[st]])
        update(last[A[st]],0);
      last[A[st]]=st;
      update(st,1);
      st++;
    }
    ans[idx] = query(l,r+1)^(PS[r]^PS[l-1]);
  }
  for(int i=1;i<=m;i++)
    dout(ans[i]);
	return 0;
}