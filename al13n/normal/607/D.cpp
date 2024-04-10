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
const ld EPS = 1e-10;
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

const LL mod=INF+7;

struct segtree{
  vector<LL> C,S;

  segtree(int n):C(n*4,1),S(n*4){}

  void mulc(int l,int r,LL v,int a,int b,int k){
    if(!k) dbg("mulc",l,r,v);
    if(l>=b || r<=a)
      return;
    if(l<=a && r>=b){
      (C[k]*=v)%=mod;
      (S[k]*=v)%=mod;
      return;
    }
    int c=(a+b)/2;
    mulc(l,r,v,a,c,k*2+1);
    mulc(l,r,v,c,b,k*2+2);
    S[k]=(S[k*2+1]+S[k*2+2])*C[k]%mod;
  }

  LL gets(int l,int r,int a,int b,int k){
    if(!k) dbg("gets",l,r);
    if(l>=b || r<=a)
      return 0;
    if(l<=a && r>=b)
      return S[k];
    int c=(a+b)/2;
    return (gets(l,r,a,c,k*2+1)+gets(l,r,c,b,k*2+2))*C[k]%mod;
  }

  LL getc(int p,int a,int b,int k){
    if(b==a+1)
      return C[k];
    int c=(a+b)/2;
    return (p<c?getc(p,a,c,k*2+1):getc(p,c,b,k*2+2))*C[k]%mod;
  }

  void setv(int p,LL v,int a,int b,int k){
    if(!k) dbg("setv",p,v);
    if(b==a+1){
      S[k]=v*C[k]%mod;
      return;
    }
    int c=(a+b)/2;
    if(p<c)
      setv(p,v,a,c,k*2+1);
    else
      setv(p,v,c,b,k*2+2);
    S[k]=(S[k*2+1]+S[k*2+2])*C[k]%mod;
  }
};

struct vert{
  vector<int> g;
  int a=-1,b=-1;
  LL v=LINF;
  int p=-1,c=1;
};

vector<vert> G(1);
int cnt=0;

void dfs(int v){
  G[v].a=cnt;
  ++cnt;
  for(int p:G[v].g){
    dfs(p);
  }
  G[v].b=cnt;
}

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);

  int tc;
  cin>>G[0].v>>tc;
  vector<int> Q(tc);
  forn(q,tc){
    int t;
    cin>>t;
    if(t==1){
      int p;
      LL x;
      cin>>p>>x;
      --p;
      int v=sz(G);
      assert(p<v);
      Q[q]=~v;
      G.pb(vert());
      G[v].p=p;
      G[p].g.pb(v);
      G[v].v=x;
    }else{
      cin>>Q[q];
      --Q[q];
    }
  }

  dfs(0);

  segtree T(sz(G));
  T.setv(G[0].a,G[0].v,0,sz(G),0);
  for(int v:Q){
    dbg("Q");
    if(v<0){
      v=~v;
      int p=G[v].p;
      T.setv(G[v].a,G[v].v,0,sz(G),0);
      int &c=G[p].c;
      LL x=powmod(c,mod-2,mod)*(c+1)%mod;
      ++c;
      T.mulc(G[p].a,G[p].b,x,0,sz(G),0);
    }else{
      LL s=T.gets(G[v].a,G[v].b,0,sz(G),0);
      LL c=T.getc(G[v].a,0,sz(G),0);
      LL cc=c*powmod(G[v].c,mod-2,mod)%mod;
      dbg(s,c,cc);
      cout<<s*powmod(cc,mod-2,mod)%mod<<'\n';
    }
  }
  
  return 0;
}