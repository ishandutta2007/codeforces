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
#else
#define dbg(...) do{}while(false)
#endif

int K;

struct val{
  pii v[5];

  val(){
    forn(i,K){
      v[i]=mp(0,-1);
    }
  }
  val(int id,int c){
    forn(i,K){
      v[i]=mp(0,-1);
    }
    v[0]=mp(c,id);
  }

  void add(int id,int c){
    int mn=INF;
    forn(i,K){
      if(v[i].Y==id){
	v[i].X+=c;
	return;
      }
      mn=min(mn,v[i].X);
    }
    int t=min(c,mn);
    assert(t>=0);
    forn(i,K){
      v[i].X-=t;
      if(id!=-1 && !v[i].X){
	v[i]=mp(c-t,id);
	id=-1;
      }
    }
  }

  void merge(const val&b){
    forn(i,K){
      if(b.v[i].X)
	add(b.v[i].Y,b.v[i].X);
    }
  }
};

struct tree{
  vector<int> O;
  vector<val> T;

  tree(int n):O(n*4),T(n*4){}

  void push(int a,int b,int k){
    if(O[k]==-1)
      return;
    if(b>a+1)
      O[k*2+1]=O[k*2+2]=O[k];
    T[k]=val(O[k],b-a);
    O[k]=-1;
  }
  void pull(int k){
    assert(O[k]==-1);
    T[k]=T[k*2+1];
    T[k].merge(T[k*2+2]);
  }
  
  void setv(int l,int r,int v,int a,int b,int k){
    if(l<=a && r>=b){
      O[k]=v;
      push(a,b,k);
      return;
    }
    push(a,b,k);
    if(l>=b || r<=a)
      return;
    int c=(a+b)/2;
    setv(l,r,v,a,c,k*2+1);
    setv(l,r,v,c,b,k*2+2);
    pull(k);
  }

  val getv(int l,int r,int a,int b,int k){
    if(l>=b || r<=a)
      return val();
    push(a,b,k);
    if(l<=a && r>=b)
      return T[k];
    int c=(a+b)/2;
    val t=getv(l,r,a,c,k*2+1);
    t.merge(getv(l,r,c,b,k*2+2));
    return t;
  }
};

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

  int n,m,p;
  cin>>n>>m>>p;
  K=100/p;
  tree T(n);
  forn(i,n){
    int a;
    cin>>a;
    T.setv(i,i+1,a,0,n,0);
  }
  forn(qqq,m){
    int t,l,r;
    cin>>t>>l>>r;
    --l;
    if(t==1){
      int id;
      cin>>id;
      T.setv(l,r,id,0,n,0);
    }else{
      assert(t==2);
      val t=T.getv(l,r,0,n,0);
      cout<<K;
      forn(i,K){
	cout<<' '<<max(1,t.v[i].Y);
      }
      cout<<'\n';
    }
  }
 
  return 0;
}