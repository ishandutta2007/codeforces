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
LL inv(LL a,LL m){assert(m>1);LL x,y,g;g=gcdex(a,m,x,y);return (x%(m/g)+m/g)%m/g;}
LL crt(LL a1,LL m1,LL a2,LL m2){LL a=(a2-a1%m2+m2)%m2;LL x,y,g;g=gcdex(m1,m2,x,y);if(a%g)return -1;LL m=m1/g*m2;x*=a/g;x=(x%m2+m2)%m2;LL r=(a1+x*m1)%m;assert(r%m1==a1 && r%m2==a2);return r;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){if(a<=1)return false;for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
LL sqrtup(LL a){if(!a)return 0;LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>=a)--x;while((x+1)*(x+1)<a)++x;return x+1;}
LL isqrt(LL a){assert(a>=0);LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>a)--x;while((x+1)*(x+1)<=a)++x;return x;}
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
template<class T,class V,class C> ostream& operator<<(ostream &s, const priority_queue<T,V,C> &q) {auto a=q;s<<"{";bool f=false;while(!a.empty()){if(f)s<<",";f=true;s<<a.top();a.pop();}return s<<"}";}
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a){s<<'[';forv(i,a){if(i)s<<',';s<<a[i];}s<<']';return s;}
template<size_t n,class... T> struct put1 { static ostream& put(ostream &s, const tuple<T...> &t){s<<get<sizeof...(T)-n>(t);if(n>1)s<<',';return put1<n-1,T...>::put(s,t);} };
template<class... T> struct put1<0,T...> { static ostream& put(ostream &s, const tuple<T...> &t){return s;} };
template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t){s<<"(";put1<sizeof...(T),T...>::put(s,t);s<<")";return s;}
ostream& put3(ostream &s, const char*, bool) {return s;}
template<class U,class... T> ostream& put3(ostream &s, const char *f, bool fs, U&& u, T&&... t) {
  while(*f==' ')++f;if (!fs)s<<", ";auto nf=f;int d=0;while(*nf&&(*nf!=','||d)){if(*nf=='(')++d;else if(*nf==')')--d;++nf;}
  auto nf2=nf;while(nf2>f&&*(nf2-1)==' ')--nf;fs=*f=='"';if(!fs){s.write(f,nf2-f);s<<"=";};s<<u;if(fs)s<<' ';if(*nf)++nf;return put3(s,nf,fs,forward<T>(t)...);}
#ifdef __ASD__
auto asdqwet0 = chrono::steady_clock::now();
#define dbg(...) do { cerr.setf(ios::fixed,ios::floatfield);cerr.precision(6);double asdqwet = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - asdqwet0).count();cerr << '[' << __LINE__ << ' ' << asdqwet << "] "; put3(cerr, #__VA_ARGS__, 1, ##__VA_ARGS__); cerr << endl; }while(false)
#include "draw.h"
#define draw(x,...) dr::get().add((new dr::x)__VA_ARGS__)
#define drawc(x) dr::get().x
#else
#define dbg(...) do{}while(false)
#define draw(...) do{}while(false)
#define drawc(...) do{}while(false)
#endif

void fact(LL a,map<LL,LL>&m){
  for(LL p=2;p*p<=a;++p){
    while(a%p==0){
      a/=p;
      ++m[p];
    }
  }
  if(a>1)
    ++m[a];
}

map<LL,LL> read(){
  map<LL,LL> m;
  forn(i,3){
    LL a;
    cin>>a;
    fact(a,m);
  }
  return m;
}

LL toval(map<LL,LL> m){
  LL r=1;
  for(auto it:m){
    forn(i,it.Y)
      r*=it.X;
  }
  return r;
}

LL doit1(int a,LL n,const vector<LL>&v){
  if(!n)
    return 0;
  LL r=n;
  for(;a<sz(v);++a)
    r-=doit1(a+1,n/v[a],v);
  return r;
}

LL doit2(int a,LL n,const vector<pair<pll,pll>>&v){
  if(!n)
    return 0;
  if(a==sz(v)){
    //dbg(a,n,1);
    return 1;
  }
  if(v[a].X.X<=n){
    //dbg(a,n,v[a].X.Y);
    return v[a].X.Y;
  }
  LL r=1;
  for(;a<sz(v);++a){
    LL t=n;
    forn(k,v[a].Y.Y){
      t/=v[a].Y.X;
      r+=doit2(a+1,t,v);
      //if(!a) dbg(a,k,t,r);
    }
  }
  //dbg(a,n,r);
  return r;
}

LL brute1(LL n,LL m,LL s){
  LL r=0;
  for(LL i=1;i<=m;++i){
    r+=s%gcd(i,n)==0;
  }
  return r;
}

LL brute2(LL n,LL s){
  LL r=0;
  for(LL i=1;i<=n;++i)
    r+=s%i==0;
  return r;
}

LL brute(LL n,LL m,LL s){
  return brute1(n,m,s)+brute2(n,s);
}

LL solve(map<LL,LL> n,map<LL,LL> m,map<LL,LL> s){
  vector<LL> v;
  for(auto it:n){
    LL c=s.count(it.X) ? s.at(it.X) : 0ll;
    if(it.Y<=c)
      continue;
    LL t=1;
    forn(i,c+1)
      t*=it.X;
    v.pb(t);
  }
  //dbg(v);
  LL res=doit1(0,toval(m),v);
  //LL res=brute1(toval(n),toval(m),toval(s));
  vector<pair<pll,pll>> u;
  for(auto it:s){
    LL t=1;
    forn(i,it.Y)
      t*=it.X;
    u.pb(mp(mp(t,it.Y+1),it));
  }
  sort(all(u));
  reverse(all(u));
  for(int i=sz(u)-2;i>=0;--i){
    u[i].X.X*=u[i+1].X.X;
    u[i].X.Y*=u[i+1].X.Y;
  }
  //dbg(u);
  res+=doit2(0,toval(n),u);
  //res+=brute2(toval(n),toval(s));
  return res;
}

void test(){
  for(LL lim=1;lim<=1000;++lim){
    forn(qqq,1000){
      LL n=rand()%lim+1;
      LL m=rand()%lim+1;
      LL s=rand()%lim+1;
      map<LL,LL> nf,mf,sf;
      fact(n,nf);fact(m,mf);fact(s,sf);
      LL r=solve(nf,mf,sf);
      LL b=brute(n,m,s);
      if(r!=b){
        dbg(lim,qqq,n,m,s,b,r);
        return;
      }
    }
  }
  dbg("ok");
}

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

  //test();return 0;
  
  int tc;
  cin>>tc;
  forn(qqq,tc){
    auto n=read();
    auto m=read();
    auto s=read();
    ++s[2];
    LL r=solve(n,m,s);
    cout<<r<<'\n';
  }

  return 0;
}