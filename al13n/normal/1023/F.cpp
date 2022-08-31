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
template<class T> inline T parse(const string&s){T x;stringstream ss(s);ss>>x;return x;}
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
#define clr(ar,val) memset(&ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
const ld EPS = 1e-12;
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

vector<vector<pii>> G;
vector<array<int,20>> J,K;
vector<int> D;
vector<vector<int>> E1,E2;

void dfs1(int v,int pr,int d){
  D[v]=d;
  J[v][0]=pr;
  forn(i,sz(J[v])-1) J[v][i+1]=J[J[v][i]][i];
  forv(i,K[0]) K[v][i]=INF*2;
  for(pii p:G[v]){
    if(p.X==pr) continue;
    dfs1(p.X,v,d+1);
  }
}

int todep(int v,int d,int c){
  assert(D[v]>=d);
  for(int i=sz(J[0])-1;i>=0;--i){
    if(D[v]-d>=(1<<i)){
      K[v][i]=min(K[v][i],c);
      v=J[v][i];
    }
  }
  return v;
}

vector<int> dsu;

int get(int a){
  return dsu[a]==a?a:(dsu[a]=get(dsu[a]));
}

LL ans;
bool unbounded;

void dfs2(int v,int pr,int wp){
  for(pii p:G[v]){
    if(p.X==pr) continue;
    dfs2(p.X,v,p.Y);
  }
  for(int i=sz(K[0])-1;i>0;--i){
    K[v][i-1]=min(K[v][i-1],K[v][i]);
    K[J[v][i-1]][i-1]=min(K[J[v][i-1]][i-1],K[v][i]);
  }
  if(v){
    if(wp==-1){
      if(K[v][0]==2*INF) unbounded=true;
      else ans+=K[v][0];
    } else assert(wp<=K[v][0]);
  }
}

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);srand(time(0));

  int n,k,m;
  cin>>n>>k>>m;
  G.resize(n);
  J.resize(n);
  K.resize(n);
  D.resize(n,-1);
  E1.resize(n);
  E2.resize(n);
  dsu.resize(n);
  forn(i,k){
    int a,b;
    cin>>a>>b;
    --a;--b;
    G[a].pb(mp(b,-1));
    G[b].pb(mp(a,-1));
  }

  vector<pair<int,pii>> E(m);
  forn(i,m){
    int a,b,w;
    cin>>a>>b>>w;
    --a;--b;
    E[i]=mp(w,mp(a,b));
  }

  iota(all(dsu),0);
  int ce=0;
  forn(i,n){
    for(pii p:G[i]){
      if(p.X<i) continue;
      int a=get(i);
      int b=get(p.X);
      assert(a!=b);
      dsu[a]=b;
      ++ce;
    }
  }
  for(auto e:E){
    int a=get(e.Y.X);
    int b=get(e.Y.Y);
    if(a==b) continue;
    dsu[a]=b;
    G[e.Y.X].pb(mp(e.Y.Y,e.X));
    G[e.Y.Y].pb(mp(e.Y.X,e.X));
    ++ce;
  }
  assert(ce==n-1);

  dfs1(0,0,0);
  dbg(G);
  dbg(D);
  dbg(J);

  for(auto e:E){
    int a=e.Y.X;
    int b=e.Y.Y;
    int c=e.X;
    int d=min(D[a],D[b]);
    int aa=todep(a,d,c);
    int bb=todep(b,d,c);
    if(aa!=bb){
      for(int i=sz(J[0])-1;i>=0;--i){
        if(J[aa][i]!=J[bb][i]){
          K[aa][i]=min(K[aa][i],c);
          K[bb][i]=min(K[bb][i],c);
          aa=J[aa][i];
          bb=J[bb][i];
        }
      }
      K[aa][0]=min(K[aa][0],c);
      K[bb][0]=min(K[bb][0],c);
    }
  }

  dfs2(0,0,-1);
  cout<<(unbounded?-1ll:ans);
  
  return 0;
}