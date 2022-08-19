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

struct node{
  int d=0,m=0,c=0;

  void upd(const node&a,const node&b){
    m=min(a.m,b.m);
    c=0;
    if(a.m==m) c+=a.c;
    if(b.m==m) c+=b.c;
    m+=d;
  }
};

struct tree{
  vector<node> T;
  
  tree(int n):T(n*4+10){}

  void init(int a,int b,int k){
    T[k].c=b-a;
    if(b==a+1) return;
    int c=(a+b)/2;
    init(a,c,k*2+1);
    init(c,b,k*2+2);
  }

  void add(int l,int r,int v,int a,int b,int k){
    if(l>=b || r<=a) return;
    if(l<=a && r>=b){
      T[k].d+=v;
      T[k].m+=v;
      return;
    }
    int c=(a+b)/2;
    add(l,r,v,a,c,k*2+1);
    add(l,r,v,c,b,k*2+2);
    T[k].upd(T[k*2+1],T[k*2+2]);
  }

  int zeros(){
    assert(T[0].m>=0);
    return T[0].m?0:T[0].c;
  }
};

vector<vector<int>> G;
vector<pii> T;
vector<array<int,20>> J;
int cnt=0;

void dfs1(int v,int pr){
  J[v][0]=pr;
  forn(i,sz(J[v])-1) J[v][i+1]=J[J[v][i]][i];
  T[v].X=cnt++;
  for(int p:G[v]){
    if(p==pr) continue;
    dfs1(p,v);
  }
  T[v].Y=cnt;
}

int lca(int a,int b){
  if(T[a].X>T[b].X) swap(a,b);
  if(T[a].Y>T[b].X) return a;
  for(int i=sz(J[a])-1;i>=0;--i) if(T[J[a][i]].Y<=T[b].X) a=J[a][i];
  a=J[a][0];
  assert(T[a].X<=T[b].X && T[a].Y>T[b].X);
  return a;
}
int pre(int a,int b){
  assert(T[a].X<T[b].X && T[a].Y>T[b].X);
  for(int i=sz(J[b])-1;i>=0;--i) if(T[a].X<T[J[b][i]].X) b=J[b][i];
  assert(a==J[b][0]);
  return b;
}

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);srand(time(0));

  int n,tc;
  cin>>n>>tc;
  G.resize(n);
  T.resize(n);
  J.resize(n);
  forn(i,n-1){
    int a,b;
    cin>>a>>b;
    --a;--b;
    G[a].pb(b);
    G[b].pb(a);
  }
  dfs1(0,0);
  assert(cnt==n);

  tree R(n);
  R.init(0,n,0);
  set<pii> E;
  forn(qq,tc){
    int a,b;
    cin>>a>>b;
    --a;--b;
    assert(a!=b);
    if(b<a) swap(a,b);
    int sg=E.count(mp(a,b)) ? -1 : 1;
    if(sg==1) E.insert(mp(a,b));
    else E.erase(mp(a,b));

    int v=lca(a,b);
    if(v==b) swap(a,b);
    if(v==a){
      int t=pre(a,b);
      R.add(T[t].X,T[t].Y,sg,0,n,0);
      R.add(T[b].X,T[b].Y,-sg,0,n,0);
    }else{
      R.add(0,n,sg,0,n,0);
      R.add(T[a].X,T[a].Y,-sg,0,n,0);
      R.add(T[b].X,T[b].Y,-sg,0,n,0);
    }
    cout<<R.zeros()<<'\n';
  }

  return 0;
}