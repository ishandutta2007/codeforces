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

const int N = int(1e5)+10;
const int MAX = int(2e5)+10;
const int LOGN = 20;
int L[2][N*LOGN],R[2][N*LOGN],blen[2],root[2][N];
struct node{
  LL a,b,y1,y2;
  node(int _a=0,int _b=0,int _y1=0,int _y2=0){
    a=_a;
    b=_b;
    y1=_y1;
    y2=_y2;
  }
}ST[2][N*LOGN];
node merge(node a,node b){
  node ret;
  ret.a = a.a + b.a;
  ret.b = a.b + b.b;
  ret.y1 = a.y1 + b.y1;
  ret.y2 = a.y2 + b.y2;
  return ret;
}
int t;
//sparse persistent-segtree. range sum, initially 0
int update(int pos,node add,int l,int r,int id){
  if(l>pos || r<=pos)return id;
  int ID = ++blen[t], m=l+(r-l)/2;
  if(l==r-1)return (ST[t][ID]=merge(ST[t][id],add),ID);
  L[t][ID]=update(pos,add,l,m,L[t][id]);
  R[t][ID]=update(pos,add,m,r,R[t][id]);
  return (ST[t][ID]=merge(ST[t][L[t][ID]],ST[t][R[t][ID]]),ID);
}
node dummy;
node query(int L,int R,int l,int r,int x){
  if(r <= L || l >= R || !x)return dummy;
  if(l >= L && r <= R)return ST[t][x];
  int mid = l + (r - l) / 2;
  return merge(query(L,R,l,mid,::L[t][x]),query(L,R,mid,r,::R[t][x]));
}
LL A[2][N],B[2][N],X[2][N],Y[2][N],SY[2][N];
int idx[2][N],a[N],b[N];
node sub(node a,node b){
  a.a -= b.a;
  a.b -= b.b;
  a.y1 -= b.y1;
  a.y2 -= b.y2;
  return a;
}
LL psa[N],psb[N];
int main()
{
  int n;si(n);
  root[0][0] = ++blen[0];
  root[1][0] = ++blen[1];
  for(int i=1;i<=n;i++){
    int x1,x2,a,b,y1,y2;
    scanf("%d %d %d %d %d %d",&x1,&x2,&y1,&a,&b,&y2);
    t = 0;
    root[t][i] = update(x1,node(a,b,y1,y2),0,MAX,root[t][i-1]);
    t = 1;
    root[t][i] = update(x2,node(a,b,y1,y2),0,MAX,root[t][i-1]);
    psa[i] += psa[i-1] + a;
    psb[i] += psb[i-1] + b;
  }
  int m;si(m);
  LL last = 0;
  REP(i,m){
    int l,r,x;
    si(l);si(r);si(x);
    x = (x + last) % int(1e9);
    node val;
    LL ans = 0;
    LL sa = 0, sb = 0;
    //for y1
    t = 0;
    val = sub(query(x,MAX,0,MAX,root[t][r]),query(x,MAX,0,MAX,root[t][l-1]));
    ans += val.y1;
    sa += val.a;
    sb += val.b;
    //for y2
    t = 1;
    val = sub(query(0,x,0,MAX,root[t][r]),query(0,x,0,MAX,root[t][l-1]));
    ans += val.y2;
    sa += val.a;
    sb += val.b;
    //for remaining
    LL a = psa[r] - psa[l-1] - sa;
    LL b = psb[r] - psb[l-1] - sb;
    ans += a * x + b;
    //done :)
    lldout(ans);
    last = ans;
  }
	return 0;
}