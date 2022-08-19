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
#include "draw.h"
#define draw(x) dr::get().add(x)
#define drawc(x) dr::get().x
#else
#define dbg(...) do{}while(false)
#define draw(...) do{}while(false)
#define drawc(...) do{}while(false)
#endif

vector<string> P;
map<string,int> I;
vector<LL> C;

struct mat{
  vector<vector<LL>> a;

  mat(int n):a(n,vector<LL>(n,-LINF)){
    forn(i,n)
      a[i][i]=0;
  }
  mat operator*(const mat&b)const{
    mat r(sz(a));
    forv(i,a){
      forv(j,a){
        r.a[i][j]=-LINF;
        forv(k,a){
          LL t1=a[i][k];
          LL t2=b.a[k][j];
          if(t1<0||t2<0)
            continue;
          r.a[i][j]=max(r.a[i][j],t1+t2);
        }
      }
    }
    return r;
  }
};

mat pw(mat a,LL p){
  mat r(sz(a.a));
  while(p){
    if(p&1)
      r=r*a;
    p>>=1;
    a=a*a;
  }
  return r;
}

void gen(){
  int n=1,k=200;
  LL l=LINF/10000;
  cout<<n<<' '<<l<<endl;
  forn(i,n)
    cout<<rand()%100+1<<' ';
  cout<<endl;
  forn(i,n){
    forn(j,k)
      cout<<(char)('a'+rand()%26);
    cout<<endl;
  }
}

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

  if(argc>1){gen();return 0;}
  
  int n;
  LL l;
  cin>>n>>l;
  vector<LL> A(n);
  forn(i,n)
    cin>>A[i];
  map<string,LL> M;
  forn(i,n){
    string s;
    cin>>s;
    M[s]+=A[i];
    forn(k,sz(s)+1){
      string p=s.substr(0,k);
      if(I.count(p))
        continue;
      I[p]=sz(P);
      P.pb(p);
    }
  }
  C.resize(sz(P));
  forv(i,P){
    string p=P[i];
    forn(k,sz(p)+1){
      string s=p.substr(k);
      auto it=M.find(s);
      if(it!=M.end())
        C[i]+=it->Y;
    }
  }

  mat m(sz(P));
  forv(i,P){
    m.a[i][i]=-LINF;
    for(char c='a';c<='z';++c){
      string s=P[i]+c;
      bool f=false;
      forn(k,sz(s)+1){
        string t=s.substr(k);
        auto it=I.find(t);
        if(it==I.end())
          continue;
        int j=it->Y;
        m.a[i][j]=max(m.a[i][j],C[j]);
        f=true;
        break;
      }
      assert(f);
    }
  }
  /*dbg(P);
  dbg(I);
  dbg(C);
  dbg(m.a);*/
  m=pw(m,l);
  LL r=-LINF;
  forv(i,P){
    r=max(r,m.a[I[""]][i]);
  }
  assert(r>=0);
  cout<<r;

  return 0;
}