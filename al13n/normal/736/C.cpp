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
LL gcdex(LL a,LL b,LL &x,LL &y){if(!a){x=0,y=1;return b;}LL k=b/a;LL g=gcdex(b-k*a,a,y,x);x-=k*y;return g;}
LL inv(LL a,LL m){LL x,y,g;g=gcdex(a,m,x,y);return (x%(m/g)+m/g)%m/g;}
LL crt(LL a1,LL m1,LL a2,LL m2){LL a=(a2-a1%m2+m2)%m2;LL x,y,g;g=gcdex(m1,m2,x,y);if(a%g)return -1;LL m=m1/g*m2;x*=a/g;x=(x%m2+m2)%m2;LL r=(a1+x*m1)%m;assert(r%m1==a1 && r%m2==a2);return r;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){if(a<=1)return false;for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
LL sqrtup(LL a){if(!a)return 0;LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>=a)--x;while((x+1)*(x+1)<a)++x;return x+1;}
LL isqrt(LL a){LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>a)--x;while((x+1)*(x+1)<=a)++x;return x;}
LL sgn(LL x){return x<0?-1:x>0?1:0;}
template<class T> ostream& operator<<(ostream &s, const vector<T> &v);
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p);
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m);
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a);
template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t);
template<class T> ostream& operator<<(ostream &s, const vector<T> &v){s<<'[';forv(i,v){if(i)s<<',';s<<v[i];}s<<']';return s;}
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p){s<<"("<<p.X<<","<<p.Y<<")";return s;}
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it.X<<": "<<it.Y;}s<<"}";return s;}
template<class T> ostream& operator<<(ostream &s, const set<T> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it;}s<<"}";return s;}
template<class T> ostream& operator<<(ostream &s, const multiset<T> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it;}s<<"}";return s;}
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a){s<<'[';forv(i,a){if(i)s<<',';s<<a[i];}s<<']';return s;}
template<size_t n,class... T> struct put1 { static ostream& put(ostream &s, const tuple<T...> &t){s<<get<sizeof...(T)-n>(t);if(n>1)s<<',';return put1<n-1,T...>::put(s,t);} };
template<class... T> struct put1<0,T...> { static ostream& put(ostream &s, const tuple<T...> &t){return s;} };
template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t){s<<"(";put1<sizeof...(T),T...>::put(s,t);s<<")";return s;}
ostream& put2(ostream &s, const tuple<> &t){return s;}
template<class U> ostream& put2(ostream &s, const tuple<U> &t){return s<<get<0>(t);}
template<class U,class V,class... T> ostream& put2(ostream &s, const tuple<U,V,T...> &t){return s<<t;}
#ifdef __ASD__
auto asdqwet0 = chrono::steady_clock::now();
#define dbg(...) do { \
ios::fmtflags asdqwef=cerr.flags();cerr.setf(ios::fixed,ios::floatfield);cerr.precision(6);double asdqwet = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - asdqwet0).count();cerr << '[' << __LINE__ << ' ' << asdqwet << "] " << #__VA_ARGS__ << " = "; put2(cerr, make_tuple(__VA_ARGS__)); cerr << endl;cerr.flags(asdqwef); }while(false)
#include "draw.h"
#define draw(x) dr::get().add(x)
#define drawc(x) dr::get().x
#else
#define dbg(...) do{}while(false)
#define draw(...) do{}while(false)
#define drawc(...) do{}while(false)
#endif

int K;
vector<vector<int>> G;
using val=vector<vector<LL>>;
const LL mod=INF+7;

val dfs(int v,int pr){
  val R(2,vector<LL>(K+1));
  R[0][0]=R[1][K]=1;
  for(int p:G[v]){
    if(p==pr)
      continue;
    //dbg(v,p,R);
    val t=dfs(p,v);
    val nr(2,vector<LL>(K+1));
    forn(h0,2){
      forn(k0,K+1){
        if(!R[h0][k0])
          continue;
        forn(h,2){
          forn(k,K+1){
            if(!t[h][k])
              continue;
            int hh=h0,kk=k0;
            if(!h0){
              if(!h){
                kk=max(k0,k+1);
              }else if(k-1>=k0){
                hh=1;
                kk=k-1;
              }
            }else{
              if(h){
                kk=max(k0,k-1);
              }else if(k0-1<k){
                hh=0;
                kk=k+1;
              }
            }
            if(kk>K || kk<0)
              continue;
            (nr[hh][kk]+=R[h0][k0]*t[h][k])%=mod;
          }
        }
      }
    }
    R=nr;
  }
  //dbg(v,R);
  return R;
}

LL solve(int n,int k,vector<pii> E){
  K=k;
  G.clear();G.resize(n);
  for(pii e:E){
    G[e.X].pb(e.Y);
    G[e.Y].pb(e.X);
  }
  val t=dfs(0,0);
  LL r=accumulate(all(t[1]),0ll)%mod;
  return r;
}

LL brute(int n,int k,vector<pii> E){
  vector<vector<int>> G(n);
  for(pii e:E){
    G[e.X].pb(e.Y);
    G[e.Y].pb(e.X);
  }
  LL res=0;
  forn(m,1<<n){
    vector<int> D(n,INF);
    queue<int> qu;
    forn(i,n){
      if(m&(1<<i)){
        D[i]=0;
        qu.push(i);
      }
    }
    bool ok=true;
    while(!qu.empty()){
      int v=qu.front();
      qu.pop();
      if(D[v]>k){
        ok=false;
        break;
      }
      for(int p:G[v]){
        if(D[p]==INF){
          D[p]=D[v]+1;
          qu.push(p);
        }
      }
    }
    forn(i,n)
      if(D[i]>k){
        ok=false;
        break;
      }
    if(ok)
      ++res;
  }
  return res;
}

vector<pii> gen(int n){
  vector<pii> r;
  forn(i,n-1)
    r.pb(mp(i+1,rand()%(i+1)));
  return r;
}

void stress(){
  for(int n=1;n<=12;++n){
    for(int k=0;k<=n-1;++k){
      forn(qq,10000){
        auto E=gen(n);
        LL b=brute(n,k,E);
        LL r=solve(n,k,E);
        if(r!=b){
          dbg(n,k,qq,E,b,r);
          cout<<n<<' '<<k<<endl;
          forn(i,n-1)
            cout<<E[i].X+1<<' '<<E[i].Y+1<<endl;
          return;
        }
      }
    }
  }
  dbg("passed");
}

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

  //stress();return 0;
  
  int n;
  cin>>n>>K;
  vector<pii> E;
  forn(i,n-1){
    int a,b;
    cin>>a>>b;
    --a;--b;
    E.pb(mp(a,b));
  }
  cout<<solve(n,K,E);

  return 0;
}