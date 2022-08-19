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
#ifdef __ASD__
#define dbg(...) do { cerr << #__VA_ARGS__ << " = "; put2(cerr, make_tuple(__VA_ARGS__)); cerr << endl; }while(false)
#else
#define dbg(...) do{}while(false)
#endif

const int L=10;
struct val{
  int n=0;
  int a[L*2];

  void add(int x){
    a[n++]=x;
    if(n>L){
      nth_element(a,a+L,a+n);
      n=L;
    }
  }
  void add(const val&v){
    forn(i,v.n)
      a[n++]=v.a[i];
    if(n>L){
      nth_element(a,a+L,a+n);
      n=L;
    }
  }

  void ans(int c){
    c=min(n,c);
    partial_sort(a,a+c,a+n);
    cout<<c;
    forn(i,c)
      cout<<' '<<a[i];
    cout<<'\n';
  }
};

ostream& operator<<(ostream&o, const val&v){
  o<<'<';
  forn(i,v.n){
    if(i)
      o<<',';
    o<<v.a[i];
  }
  o<<'>';
  return o;
}

const int B=20;
vector<vector<int>> gr;
vector<int> D;
vector<array<int,B>> J;
vector<array<val,B>> V;

void dfs(int v,int pr,int d){
  D[v]=d;
  J[v][0]=pr;
  forn(i,B-1){
    int t=J[v][i];
    V[v][i+1]=V[v][i];
    if(t==-1)
      J[v][i+1]=-1;
    else{
      J[v][i+1]=J[t][i];
      V[v][i+1].add(V[t][i]);
    }
  }
  for(int p:gr[v]){
    if(p==pr)
      continue;
    dfs(p,v,d+1);
  }
}

int tod(int v,int d,val&x){
  for(int i=B-1;i>=0;--i){
    int t=J[v][i];
    if(t!=-1 && D[t]>=d){
      x.add(V[v][i]);
      v=J[v][i];
    }
  }
  assert(D[v]==d);
  return v;
}

val lca(int a,int b){
  val x;
  a=tod(a,min(D[a],D[b]),x);
  b=tod(b,min(D[a],D[b]),x);
  for(int i=B-1;i>=0;--i){
    if(J[a][i]!=J[b][i]){
      x.add(V[a][i]);
      x.add(V[b][i]);
      a=J[a][i];
      b=J[b][i];
    }
  }
  if(a!=b)
    x.add(V[a][1]);
  x.add(V[b][0]);
  return x;
}

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);

  int n,m,q;
  cin>>n>>m>>q;
  gr.resize(n);
  D.resize(n);
  J.resize(n);
  V.resize(n);
  forn(i,n-1){
    int a,b;
    cin>>a>>b;
    --a;--b;
    gr[a].pb(b);
    gr[b].pb(a);
  }
  forn(i,m){
    int a;
    cin>>a;
    --a;
    dbg("add", a, i+1);
    V[a][0].add(i+1);
  }
  dfs(0,-1,0);
  dbg(D);
  dbg(J);
  dbg(V);

  forn(qq,q){
    int a,b,c;
    cin>>a>>b>>c;
    --a;--b;
    lca(a,b).ans(c);
  }
  
  return 0;
}