//Mobius_Treap
#include<bits/stdc++.h>
//#include<testlib.h>
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
const LL INF = LL(1e13);
const int N = int(2e5)+10;
LL ST[2][2][4*N],lazy[2][2][4*N],PS[2][N];
int t;
#define lc (x<<1)
#define rc (x<<1)|1
void push(int x,int l,int r){
  ST[t][0][x]+=lazy[t][0][x]; //Operation of lazy
  ST[t][1][x]+=lazy[t][1][x];
  if(l==r-1)lazy[t][0][x]=lazy[t][1][x]=0;
  //if(!lazy[x])return;
  for(int i=0;i<2;i++)
    lazy[t][i][lc]+=lazy[t][i][x],lazy[t][i][rc]+=lazy[t][i][x],lazy[t][i][x]=0;//Propagate Lazy
}
void up(int x){//Operation of Segtree
  for(int i=0;i<2;i++)
    ST[t][i][x] = min(ST[t][i][lc],ST[t][i][rc]);
}
void build(int l=0,int r=N,int x=1){
  lazy[t][0][x]=lazy[t][1][x]=0;//clear lazy
  if(l==r-1){
    ST[t][0][x]=(l&1?INF:PS[t][l]);
    ST[t][1][x]=(l&1?PS[t][l]:INF);
    return;
  }
  int m = (l+r)/2;
  build(l,m,lc);
  build(m,r,rc);
  up(x);
}
void update(int L,int R,int add,int l=0,int r=N,int x=1){
  push(x,l,r);
  if(l>=R || r<=L)return;
  if(l>=L && r<=R){
    lazy[t][L&1?1:0][x]+=add; //operation of lazy update
    push(x,l,r);
    return;
  }int m = (l+r)/2;
  update(L,R,add,l,m,lc);
  update(L,R,add,m,r,rc);
  up(x);
}
pair<LL,LL> query(int L,int R,int l=0,int r=N,int x=1){
  push(x,l,r);
  if(l>=R||r<=L)return {INF,INF}; //nothing here
  if(l>=L && r<=R)return {ST[t][0][x],ST[t][1][x]};
  int m = (l+r)/2;
  pair<LL,LL> la = query(L,R,l,m,lc);
  pair<LL,LL> ra = query(L,R,m,r,rc);
  return {min(la.F,ra.F),min(la.S,ra.S)};//operation of segtree
}
bool check(int l,int r){
  bool ok1 = true;
  pair<LL,LL> ret = query(l,r+1);
  pair<LL,LL> sub = query(l-1,l);
  pair<LL,LL> last = query(r,r+1);
  //trace(t,l,r);
  sub.F = min(sub.F,sub.S);
  sub.S = min(sub.F,sub.S);
  //trace(ret.F,ret.S,sub.F,sub.S,last.F,last.S);
  if(l&1){
    ok1 &= (ret.S + sub.S >= 1);
    ok1 &= (ret.F - sub.F >= 0);
    ok1 &= ((r & 1 ? last.S : last.F) + (r & 1 ? sub.S: -sub.F) == ((r - l + 1) & 1 ? 1 : 0));
  }
  else{
    ok1 &= (ret.S - sub.S >= 0);
    ok1 &= (ret.F + sub.F >= 1);
    ok1 &= ((r & 1 ? last.S : last.F) + (r & 1 ? -sub.S: +sub.F) == ((r - l + 1) & 1 ? 1 : 0));
  }
  return ok1;
}
int A[2][N];
void Update(int l,int r,int k){
  update(l,r+1,k);
  if((r-l)&1)return;
  update(r+1,N,-k);
  update(r+2,N,+k);
}
namespace brute{
  int PSO[2][N],PSE[2][N],n;
  void build(){
    for(int j=1;j<=n;j++){
      PSO[t][j] = PSO[t][j-1] + (j&1?A[t][j]:0);
      PSE[t][j] = PSE[t][j-1] + (j&1?0:A[t][j]);
    }
  }
  void update(int l,int r,int k){
    for(int i=l;i<=r;i++)
      A[t][i] += k;
    for(int j=1;j<=n;j++){
      PSO[t][j] = PSO[t][j-1] + (j&1?A[t][j]:0);
      PSE[t][j] = PSE[t][j-1] + (j&1?0:A[t][j]);
    }
  }
  bool check(int l,int r){
    bool ret = true;
    for(int i=l;i<=r;i++)
      ret &= ((i&1?1:-1)*((PSO[t][i]-PSO[t][l-1]) - (PSE[t][i]-PSE[t][l-1]))) >= 0;
    ret &= ((r&1?1:-1)*((PSO[t][r]-PSO[t][l-1]) - (PSE[t][r]-PSE[t][l-1])))  ==  ((r-l+1)&1?1:0);
    return ret;
  }
}
int main()
{
  int n;
  si(n);
  //n = 5;brute::n = n;
  for(int i=1;i<=n;i++){
    int x;si(x);
   // x = rnd.next(5,5);
    trace(x);
    A[0][i] = x;
    A[1][n-i+1] = x;
  }
  for(int i=0;i<2;i++)
    for(int j=1;j<=n;j++){
      PS[i][j] = PS[i][j-1]*-1 + A[i][j];
    }
  for(t=0;t<2;t++)
    build();//brute::build();
  int q;si(q);
  //q = 200000;
  while(q--){
    int type;si(type);
    //type = rnd.next(1,2);
    trace(type);
    if(type == 1){
      int l,r,k;
      si(l);si(r);si(k);
      /*l = rnd.next(0,n-1);
      r = rnd.next(0,n-1);
      k = rnd.next(1,1);
      if(l > r)swap(l,r);
      l = rnd.next(0,1); r = n-1;*/
      ++l;++r;
      trace(l,r,k);
      t = 0;Update(l,r,k);//brute::update(l,r,k);
      t = 1;Update(n-r+1,n-l+1,k);//brute::update(n-r+1,n-l+1,k);
    }
    else {
      int l,r;
      si(l);si(r);
      /*l = rnd.next(0,n-1);
      r = rnd.next(0,n-1);
      if(l > r)swap(l,r);*/
      ++l;++r;
      trace(l,r);
      bool ok = false,ok2 = false;
      t = 0;ok |= check(l,r);//ok2|=brute::check(l,r);
      t = 1;ok |= check(n-r+1,n-l+1);//ok2|=brute::check(n-r+1,n-l+1);
      puts(ok?"1":"0");
      trace(ok,ok2);
      //assert(ok == ok2);
    }
  }
  return 0;
}