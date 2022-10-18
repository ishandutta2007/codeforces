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
const int N = 1e5 + 10;
const int LOGN = 32;
int L[N*LOGN],R[N*LOGN],ST[N*LOGN],blen,root[N],A[N];
//sparse persistent-segtree. range sum, initially 0
int update(int pos,int add,int l,int r,int id){
  if(l>pos || r<=pos)return id;
  int ID = ++blen, m=l+(r-l)/2;
  if(l==r-1)return (ST[ID]=max(ST[id], add),ID);
  L[ID]=update(pos,add,l,m,L[id]);
  R[ID]=update(pos,add,m,r,R[id]);
  return (ST[ID]=max(ST[L[ID]], ST[R[ID]]),ID);
}
int query(int a, int b, int l, int r, int id){
  if(!id)return 0;
  if(b <= l || r <= a)return 0;
  if(l >= a && r <= b)return ST[id];
  int m = l + (r - l) / 2;
  return max(query(a, b, l, m, L[id]), query(a, b, m, r, R[id]));
}
int main()
{
  int n, m;
  si(n);si(m);
  int ans = 0;
  root[0]=++blen;
  for(int i=1;i<=n;i++)
    root[i] = ++blen;
  REP(i, m){
    int x, y, wt;
    si(x);si(y);si(wt);
    int val = query(0, wt, 0, N, root[x]);
    root[y] = update(wt, val + 1, 0, N, root[y]);
    ans = max(ans, val + 1);
  }
  dout(ans);
  return 0;
}