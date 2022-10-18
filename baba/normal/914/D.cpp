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

const int N = 5e5 + 10;
int A[N];
int ST[4 * N];
#define lc (x << 1)
#define rc (x << 1) | 1
void up(int x){
  ST[x] = __gcd(ST[lc], ST[rc]);
}
void build(int l = 1, int r = N, int x = 1){
  if(l == r - 1)return void(ST[x] = A[l]);
  int mid = (l + r) >> 1;
  build(l, mid, lc);
  build(mid, r, rc);
  up(x);
}
int query_pos(int L, int R, int val, int l = 1, int r = N, int x = 1){
  if(r <= L || l >= R)return -1;//out of range
  if(l >= L && r <= R){
    if(ST[x] % val == 0){
      //all good here.
      return -1;
    }
    //else fucked in this range.
    if(l == r - 1)return l;
  }
  int mid = (l + r) >> 1;
  int la = query_pos(L, R, val, l, mid, lc);
  if(la != -1)return la;
  return query_pos(L, R, val, mid, r, rc);
}
int query_val(int L, int R, int l = 1, int r = N, int x = 1){
  if(l >= L && r <= R)return ST[x];
  if(r <= L || l >= R)return -1;
  int mid = (l + r) >> 1;
  int la = query_val(L, R, l, mid, lc);
  int ra = query_val(L, R, mid, r, rc);
  if(la == -1 || ra == -1)return la == -1 ? ra : la;
  return __gcd(la, ra);
}
void update(int pos, int val, int l = 1, int r = N, int x = 1){
  if(pos < l || pos >= r)return;
  if(l == r - 1)return void(ST[x] = val);
  int mid = (l + r) >> 1;
  update(pos, val, l, mid, lc);
  update(pos, val, mid, r, rc);
  up(x);
}
int main()
{
  int n;si(n);
  for(int i = 1; i <= n; i++)si(A[i]);
  build();
  int q;si(q);
  while(q--){
    int t;si(t);
    if(t == 1){
      int l, r, x;
      si(l);si(r);si(x);
      int idx = query_pos(l, r + 1, x);
      int val = x + 1;
      if(idx == -1){
        val = query_val(l, r + 1);
        assert(val % x == 0);
      }
      else {
        int la = query_val(l, idx);
        int ra = query_val(idx + 1, r + 1);
        if(la == -1 && ra == -1){
          val = x;
        }
        else if(la == -1 || ra == -1)
          val = la == -1 ? ra : la;
        else val = __gcd(la, ra);
      }
      puts(val % x == 0 ? "YES" : "NO");
    }
    else {
      int pos, val;
      si(pos);si(val);
      update(pos, val);
    }
  }
	return 0;
}