#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <array>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<short, short> pss;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
typedef pair<ld, ld> pdd;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
inline LL parse(const string & s) { stringstream ss(s); LL x; ss >> x; return x; }
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define MT make_tuple
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
#define hash asdhash
#define move asdmove
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const LL LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){if(a<=1)return false;for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
LL sqrtup(LL a){if(!a)return 0;LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>=a)--x;while((x+1)*(x+1)<a)++x;return x+1;}
LL sqrtdown(LL a){LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>a)--x;while((x+1)*(x+1)<=a)++x;return x;}
template<class T> ostream& operator<<(ostream &s, const vector<T> &v);
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p);
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m);
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a);
template<class T> ostream& operator<<(ostream &s, const vector<T> &v){s<<'[';forv(i,v){if(i)s<<',';s<<v[i];}s<<']';return s;}
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p){s<<"("<<p.X<<","<<p.Y<<")";return s;}
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it.X<<": "<<it.Y;}s<<"}";return s;}
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a){s<<'[';forv(i,a){if(i)s<<',';s<<a[i];}s<<']';return s;}
template<size_t n,class... T> struct put1 { static ostream& put(ostream &s, const tuple<T...> &t){s<<get<sizeof...(T)-n>(t);if(n>1)s<<',';return put1<n-1,T...>::put(s,t);} };
template<class... T> struct put1<0,T...> { static ostream& put(ostream &s, const tuple<T...> &t){return s;} };
template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t){s<<"(";put1<sizeof...(T),T...>::put(s,t);s<<")";return s;}
ostream& put2(ostream &s, const tuple<> &t){return s;}
template<class U> ostream& put2(ostream &s, const tuple<U> &t){return s<<get<0>(t);}
template<class U,class V,class... T> ostream& put2(ostream &s, const tuple<U,V,T...> &t){return s<<t;}
#define dbg(...) do { cerr << #__VA_ARGS__ << " = "; put2(cerr, make_tuple(__VA_ARGS__)); cerr << endl; }while(false)

struct DSU{
  struct node{
    int g;
    short f=0,r=0;
  };
  struct upd{
    int b;
    short f,r;
  };
  vector<node> A;
  vector<upd> H;
  void init(int n){
    A.resize(n);
    forn(i,n)
      A[i].g=i;
  }
  pii get(int a){
    if(A[a].g==a)
      return mp(a,A[a].f);
    pii t=get(A[a].g);
    return mp(t.X,t.Y^A[a].f);
  }
  bool merge(int a,int b){
    pii aa=get(a);
    pii bb=get(b);
    if(aa.X==bb.X)
      return aa.Y!=bb.Y;
    int r1=A[aa.X].r;
    int r2=A[bb.X].r;
    if(r2>r1)
      swap(aa,bb);
    upd u;
    u.b=bb.X;
    u.f=A[bb.X].f;
    u.r=A[aa.X].r;
    H.pb(u);
    A[bb.X].g=aa.X;
    A[bb.X].f^=aa.Y^bb.Y^1;
    if(r1==r2)
      ++A[aa.X].r;
    return true;
  }
  void undo(int to){
    assert(sz(H)>=to);
    while(sz(H)>to){
      upd u=H.back();
      H.pop_back();
      A[A[u.b].g].r=u.r;
      A[u.b].f=u.f;
      A[u.b].g=u.b;
    }
  }
};

vector<DSU> D;
vector<pii> E;
vector<pii> Q;
vector<int> C;
vector<char> ans;

void doit(int a,int b,vector<int> U){
  vector<int> st0(sz(D));
  forv(i,D)
    st0[i]=sz(D[i].H);
  auto apply=[&](int e,int c){
    return D[c].merge(E[e].X,E[e].Y);
  };
  {
    vector<int> uu;
    for(int i=a;i<b;++i){
      auto it=lower_bound(all(U),Q[i].X);
      assert(it!=U.end() && *it==Q[i].X);
      uu.pb(*it);
    }
    swap(U,uu);
    sort(all(U));
    U.erase(unique(all(U)),U.end());
    for(int e:uu){
      if(C[e]==-1)
	continue;
      auto it=lower_bound(all(U),e);
      if(it==U.end() || *it!=e){
	int r=apply(e,C[e]);
	assert(r);
      }
    }
  }
  if(b==a+1){
    assert(sz(U)==1 && U[0]==Q[a].X);
    if((ans[a]=apply(Q[a].X,Q[a].Y)))
      C[Q[a].X]=Q[a].Y;
  }else{
    int c=(a+b)/2;
    doit(a,c,U);
    doit(c,b,U);
  }
  forv(i,D)
    D[i].undo(st0[i]);
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);

  int n;
  cin>>n;
  vector<tuple<int,int,int,int>> A(n);
  forn(i,n){
    int x,y;
    cin>>x>>y;
    int t=y/1000;
    if(t%2)
      x=-x;
    A[i]=make_tuple(t,x,y,i);
  }
  sort(all(A));
  for(auto a:A){
    cout<<get<3>(a)+1<<' ';
  }

  return 0;
}