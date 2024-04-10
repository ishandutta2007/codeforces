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
LL gcdex(LL a,LL b,LL &x,LL &y){if(!a){x=0,y=1;return b;}LL k=b/a;LL g=gcdex(b-k*a,a,y,x);x-=k*y;return g;}
LL inv(LL a,LL m){LL x,y,g;g=gcdex(a,m,x,y);return (x%(m/g)+m/g)%m/g;}
LL crt(LL a1,LL m1,LL a2,LL m2){LL a=(a2-a1%m2+m2)%m2;LL x,y,g;g=gcdex(m1,m2,x,y);if(a%g)return -1;LL m=m1/g*m2;x*=a/g;x=(x%m2+m2)%m2;LL r=(a1+x*m1)%m;assert(r%m1==a1 && r%m2==a2);return r;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){if(a<=1)return false;for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
LL sqrtup(LL a){if(!a)return 0;LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>=a)--x;while((x+1)*(x+1)<a)++x;return x+1;}
LL isqrt(LL a){LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>a)--x;while((x+1)*(x+1)<=a)++x;return x;}
template<class T> ostream& operator<<(ostream &s, const vector<T> &v);
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p);
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m);
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a);
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
#define dbg(...) do { cerr << #__VA_ARGS__ << " = "; put2(cerr, make_tuple(__VA_ARGS__)); cerr << endl; }while(false)
#else
#define dbg(...) do{}while(false)
#endif

struct vec{
  ld a[2];

  vec(){
    clr(a,0);
  }
  
  vec operator-(const vec &v)const{
    vec r;
    forn(i,2)
      r.a[i]=a[i]-v.a[i];
    return r;
  }
  vec operator+(const vec &v)const{
    vec r;
    forn(i,2)
      r.a[i]=a[i]+v.a[i];
    return r;
  }
  vec norm(ld d)const{
    d/=sqrt(sqr(a[0])+sqr(a[1]));
    vec r;
    forn(i,2)
      r.a[i]=a[i]*d;
    return r;
  }
};

struct mat{
  ld a[2][2];

  mat(){
    clr(a,0);
    a[0][0]=a[1][1]=1;
  }
  
  mat operator*(const mat &m)const{
    mat r;
    forn(i,2){
      forn(j,2){
	r.a[i][j]=0;
	forn(k,2){
	  r.a[i][j]+=a[i][k]*m.a[k][j];
	}
      }
    }
    return r;
  }
  vec operator*(const vec &v)const{
    vec r;
    forn(i,2){
      r.a[i]=0;
      forn(j,2){
	r.a[i]+=a[i][j]*v.a[j];
      }
    }
    return r;
  }

  static mat rot(ld g){
    mat r;
    r.a[0][0]=r.a[1][1]=cos(g);
    r.a[0][1]=r.a[1][0]=sin(g);
    r.a[0][1]*=-1;
    return r;
  }
};

struct tr{
  mat m;
  vec v;

  tr operator*(const tr &t)const{
    tr r;
    r.m=m*t.m;
    r.v=m*t.v+v;
    return r;
  }
  vec operator*(const vec &vv)const{
    return m*vv+v;
  }
};

struct segtree{
  vector<tr> T;

  segtree(int n):T(n*4+10){}

  void mul(int l,int r,tr v,int a,int b,int k){
    if(l>=b || r<=a)
      return;
    if(l<=a && r>=b){
      T[k]=v*T[k];
      return;
    }
    int c=(a+b)/2;
    T[k*2+1]=T[k]*T[k*2+1];
    T[k*2+2]=T[k]*T[k*2+2];
    T[k]=tr();
    mul(l,r,v,a,c,k*2+1);
    mul(l,r,v,c,b,k*2+2);
  }
  tr get(int p,int a,int b,int k){
    if(b==a+1){
      return T[k];
    }
    int c=(a+b)/2;
    if(p<c)
      return T[k]*get(p,a,c,k*2+1);
    else
      return T[k]*get(p,c,b,k*2+2);
  }
};

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);

  int n,m;
  cin>>n>>m;
  segtree T(n+1);
  for(int i=1;i<=n;++i){
    tr t;
    t.v.a[0]=i;
    T.mul(i,i+1,t,0,n+1,0);
  }

  forn(qqq,m){
    int x,y,z;
    cin>>x>>y>>z;
    --y;
    tr tr1=T.get(y,0,n+1,0);
    vec p1=tr1.v;
    tr t;
    if(x==1){
      tr tr2=T.get(y+1,0,n+1,0);
      vec p2=tr2.v;
      vec d=(p2-p1).norm(z);
      t.v=d;
    }else{
      assert(x==2);
      t.m=mat::rot(-z/180.*PI);
      t.v=p1-t.m*p1;
    }
    T.mul(y+1,n+1,t,0,n+1,0);
    tr trr=T.get(n,0,n+1,0);
    vec r=trr.v;
    cout.precision(20);
    cout<<r.a[0]<<' '<<r.a[1]<<'\n';
  }

  return 0;
}