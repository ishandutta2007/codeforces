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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <forward_list>
#include <thread>
#include <random>
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
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define MT make_tuple
#define pb push_back
#define EB emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(&ar, val, sizeof(ar))
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
const ld EPS = 1e-9;
const int INF = 1000*1000*1000;
const LL LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL gcdex(LL a,LL b,LL &x,LL &y){if(!a){x=0,y=1;return b;}LL k=b/a;LL g=gcdex(b-k*a,a,y,x);x-=k*y;return g;}
LL inv(LL a,LL m){assert(m>1);LL x,y,g;g=gcdex(a,m,x,y);return (x%(m/g)+m/g)%m/g;}
LL crt(LL a1,LL m1,LL a2,LL m2){LL a=(a2-a1%m2+m2)%m2;LL x,y,g;g=gcdex(m1,m2,x,y);if(a%g)return -1;LL m=m1/g*m2;assert(x+m2>=0);x=a/g*(x+m2)%m2;LL r=(a1+x*m1)%m;assert(r%m1==a1 && r%m2==a2);return r;}
LL powmod(LL a,LL p,LL m){assert(p>=0);LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){if(a<=1)return false;for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
LL sqrtup(LL a){if(!a)return 0;LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>=a)--x;while((x+1)*(x+1)<a)++x;return x+1;}
LL isqrt(LL a){if(a<=0){assert(!a);return 0;}LL x=(LL)sqrt((ld)a);while(sqr(x+1)<=a)++x;while(x*x>a)--x;return x;}
LL sgn(LL x){return x<0?-1:x>0?1:0;}
ld randf(){ld m=RAND_MAX+1.;return (((rand()+.5)/m+rand())/m+rand())/m;}
int rand30(){assert(RAND_MAX>=(1<<15)-1); return (int)((((uint32_t)rand())*(1u+(uint32_t)RAND_MAX)+(uint32_t)rand())&((1u<<30)-1));}
template<class T> void smin(T& a,T b){a=min(a,b);}
template<class T> void smax(T& a,T b){a=max(a,b);}
template<class T> ostream& operator<<(ostream &s, const vector<T> &v);
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p);
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m);
template<class T> ostream& operator<<(ostream &s, const set<T> &m);
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a);
template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t);
template<class T> ostream& operator<<(ostream &s, const vector<T> &v){s<<'[';forv(i,v){if(i)s<<',';s<<v[i];}s<<']';return s;}
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p){s<<"("<<p.X<<","<<p.Y<<")";return s;}
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it.X<<": "<<it.Y;}s<<"}";return s;}
template<class T> ostream& operator<<(ostream &s, const set<T> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it;}s<<"}";return s;}
template<class T> ostream& operator<<(ostream &s, const multiset<T> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it;}s<<"}";return s;}
template<class T,class V,class C> ostream& operator<<(ostream &s, const priority_queue<T,V,C> &q) {auto a=q;s<<"{";bool f=false;while(!a.empty()){if(f)s<<",";f=true;s<<a.top();a.pop();}return s<<"}";}
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a){s<<'[';forv(i,a){if(i)s<<',';s<<a[i];}s<<']';return s;}
template<class T> ostream& operator<<(ostream &s, const deque<T> &a){s<<'[';forv(i,a){if(i)s<<',';s<<a[i];}s<<']';return s;}
template<size_t n,class... T> struct put1 { static ostream& put(ostream &s, const tuple<T...> &t){s<<get<sizeof...(T)-n>(t);if(n>1)s<<',';return put1<n-1,T...>::put(s,t);} };
template<class... T> struct put1<0,T...> { static ostream& put(ostream &s, const tuple<T...> &t){return s;} };
template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t){s<<"(";put1<sizeof...(T),T...>::put(s,t);s<<")";return s;}
ostream& put3(ostream &s, const char*, bool) {return s;}
template<class U,class... T> ostream& put3(ostream &s, const char *f, bool fs, U&& u, T&&... t) {
  while(*f==' ')++f;if (!fs)s<<", ";auto nf=f;int d=0;while(*nf&&(*nf!=','||d)){if(*nf=='(')++d;else if(*nf==')')--d;++nf;}
  auto nf2=nf;while(nf2>f&&*(nf2-1)==' ')--nf;fs=*f=='"';if(!fs){s.write(f,nf2-f);s<<"=";};s<<u;if(fs)s<<' ';if(*nf)++nf;return put3(s,nf,fs,forward<T>(t)...);}
#ifdef __ASD__
auto qweasdt0 = chrono::steady_clock::now();
#define dbg(...) do { cerr.setf(ios::fixed,ios::floatfield);cerr.precision(6);double qweasdt = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - qweasdt0).count();cerr << '[' << __LINE__ << ' ' << qweasdt << "] "; put3(cerr, #__VA_ARGS__, 1, ##__VA_ARGS__); cerr << endl; }while(false)
#include "draw.h"
#define draw(x,...) dr::get().add((new dr::x)__VA_ARGS__)
#define drawc(x) dr::get().x
#else
#define dbg(...) do{}while(false)
#define draw(...) do{}while(false)
#define drawc(...) do{}while(false)
#endif
mt19937 mtrng;

struct comp{
  vector<int> V;
  vector<pii> E;
};

struct tree{
  vector<pii> T;

  tree(int n):T(n*4){}
  
  void init(int a,int b,int k,const vector<int>&A){
    if(b==a+1){
      T[k]=mp(A[a],a);
      return;
    }
    int c=(a+b)/2;
    init(a,c,k*2+1,A);
    init(c,b,k*2+2,A);
    T[k]=max(T[k*2+1],T[k*2+2]);
  }

  pii getmax(int l,int r,int a,int b,int k){
    if(l>=b || r<=a) return mp(0,-1);
    if(l<=a && r>=b) return T[k];
    int c=(a+b)/2;
    return max(getmax(l,r,a,c,k*2+1),getmax(l,r,c,b,k*2+2));
  }

  void setv(int p,int v,int a,int b,int k){
    if(b==a+1){
      T[k]=mp(v,p);
      return;
    }
    int c=(a+b)/2;
    if(p<c) setv(p,v,a,c,k*2+1);
    else setv(p,v,c,b,k*2+2);
    T[k]=max(T[k*2+1],T[k*2+2]);
  }
};

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);srand(35964);mtrng.seed(765674737);

  int n,m,tc;
  cin>>n>>m>>tc;
  vector<int> P;
  P.resize(n);
  forn(i,n) cin>>P[i];

  vector<pair<pii,int>> E(m);
  forn(i,m){
    cin>>E[i].X.X>>E[i].X.Y;
    --E[i].X.X;
    --E[i].X.Y;
  }
  
  vector<pii> Q(tc);
  forn(i,tc){
    cin>>Q[i].X>>Q[i].Y;
    --Q[i].Y;
    if(Q[i].X==2) E[Q[i].Y].Y=1;
  }

  vector<int> v2c(n);
  vector<comp> cs(n);
  forn(i,n){
    v2c[i]=i;
    cs[i].V.pb(i);
  }
  auto mer=[&](int a,int b,int q){
             if(a==b) return;
             if(sz(cs[a].V)<sz(cs[b].V)) swap(a,b);
             for(pii x:cs[b].E) cs[a].E.pb(mp(x.X,x.Y+sz(cs[a].V)));
             if(q!=-1) cs[a].E.pb(mp(q,sz(cs[a].V)));
             for(int v:cs[b].V){
               v2c[v]=a;
               cs[a].V.pb(v);
             }
             cs[b].V.clear();
             cs[b].E.clear();
           };
  for(auto e:E){
    if(e.Y) continue;
    mer(v2c[e.X.X],v2c[e.X.Y],-1);
  }
  for(int q=tc-1;q>=0;--q){
    if(Q[q].X!=2) continue;
    pii e=E[Q[q].Y].X;
    int a=v2c[e.X],b=v2c[e.Y];
    mer(a,b,q);
  }
  
  set<int> B;
  vector<int> v2i(n);
  vector<int> i2v;
  vector<pii> ev;
  B.insert(0);
  for(comp&c:cs){
    if(!sz(c.V)) continue;
    for(pii e:c.E) ev.pb(mp(e.X,e.Y+sz(i2v)));
    for(int v:c.V){
      v2i[v]=sz(i2v);
      i2v.pb(v);
    }
    B.insert(sz(i2v));
  }
  assert(sz(i2v)==n);
  sort(all(ev));

  tree T(n);
  vector<int> A(n);
  forn(i,n) A[i]=P[i2v[i]];
  T.init(0,n,0,A);

  int ei=0;
  forn(q,tc){
    if(Q[q].X==1){
      int i=v2i[Q[q].Y];
      auto it=B.upper_bound(i);
      int b=*it;
      --it;
      int a=*it;
      pii t=T.getmax(a,b,0,n,0);
      T.setv(t.Y,0,0,n,0);
      cout<<t.X<<'\n';
    }else if(ei<sz(ev)&&ev[ei].X==q){
      B.insert(ev[ei].Y);
      ++ei;
    }
  }

  return 0;
}