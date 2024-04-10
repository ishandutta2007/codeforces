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
const int INF = int(1e9);
int ST[4*N],lazy[4*N],A[N];
#define lc (x<<1)
#define rc (x<<1)|1
void push(int x,int l,int r){
  ST[x]+=lazy[x]; //Operation of lazy
  if(l==r-1)lazy[x]=0;
  if(!lazy[x])return;
  lazy[lc]+=lazy[x];lazy[rc]+=lazy[x];
  lazy[x]=0;//Propagate Lazy
}
void up(int x){//Operation of Segtree
  ST[x] = max(ST[lc],ST[rc]);
}
void update(int L,int R,int add,int l=0,int r=N,int x=1){
  push(x,l,r);int m = (l+r)/2;
  if(l>=R || r<=L)return;
  if(l>=L && r<=R){
    lazy[x]+=add;//operation of lazy update
    return push(x,l,r);
  }
  update(L,R,add,l,m,lc);
  update(L,R,add,m,r,rc);up(x);
}
int query(int L,int R,int l=0,int r=N,int x=1){
  push(x,l,r);int m = (l+r)/2;
  if(l>=R||r<=L)return -INF;//nothing here
  if(l>=L && r<=R)return ST[x];
  int la = query(L,R,l,m,lc);
  int ra = query(L,R,m,r,rc);
  return max(la,ra);//operation of segtree
}

int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++){
    int p;si(p);
    int t;si(t);
    if(t == 1){
      int x;si(x);
      A[p] = x;
      update(1,p+1,+1);
    }
    else {
      update(1,p+1,-1);
    }
    int l = 1, r = n,ans = -1;
    while(l <= r){
      int m = (l+r)/2;
      int q = query(m,n+1);
      if(q > 0){
        ans = m;
        l = m + 1;
      }
      else r = m - 1;
    }
    if(ans == -1)dout(ans);
    else dout(A[ans]);
  }
	return 0;
}