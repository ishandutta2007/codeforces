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

const int B=16;
const int L=1<<B;
const int mod=INF+7;

struct vals{
  vector<int> A;

  vals():A(L){}

  void var(int v,bool inv){
    int q=0;
    forn(i,B){
      if(((i>>v)&1)!=inv)
	q|=1<<i;
    }
    ++A[q];
  }

  void negate(){
    forn(i,L){
      int j=i^(L-1);
      if(i<j)
	swap(A[i],A[j]);
    }
  }
  void accum(){
    forn(i,B){
      forn(j,L){
	if(j&(1<<i))
	  (A[j]+=A[j^(1<<i)])%=mod;
      }
    }
  }
  void unaccum(){
    forn(i,B){
      forn(j,L){
	if(j&(1<<i))
	  (A[j]+=mod-A[j^(1<<i)])%=mod;
      }
    }
  }

  LL sum()const{
    return accumulate(all(A),0ll);
  }
  
  vals& operator*=(const vals &b){
    forn(i,L)
      A[i]=(1ll*A[i]*b.A[i])%mod;
    return *this;
  }
  vals& operator+=(const vals &b){
    forn(i,L)
      A[i]=(A[i]+b.A[i])%mod;
    return *this;
  }
};

string s;

vals doit(int a,int b){
  dbg(a,b);
  assert(b>a);
  if(b==a+1){
    vals r;
    forn(v,4){
      forn(inv,2){
	if(s[a]=='?' || s[a]==(inv?'a':'A')+v)
	  r.var(v,inv);
      }
    }
    return r;
  }
  assert(s[a]=='(' && s[b-1]==')');
  int d=0;
  for(int i=a;i<b;++i){
    if(s[i]=='(')
      ++d;
    else if(s[i]==')'){
      --d;
      if(!d){
	vals x=doit(a+1,i);
	vals y=doit(i+3,b-1);
	vals r;
	char op=s[i+1];
	assert(op=='|' || op=='&'||op=='?');
	dbg(op);
	if(op!='&'){
	  r=x;
	  dbg(r.sum());
	  r.accum();
	  dbg(r.sum());
	  y.accum();
	  dbg(y.sum());
	  r*=y;
	  dbg(r.sum());
	  r.unaccum();
	  if(op=='?')
	    y.unaccum();
	}
	if(op!='|'){
	  x.negate();
	  y.negate();
	  x.accum();
	  y.accum();
	  x*=y;
	  x.unaccum();
	  x.negate();
	  r+=x;
	}
	dbg(a,b,r.sum());
	return r;
      }
    }
  }
  assert(false);
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);

  cin>>s;
  vector<pii> A;
  int n;
  cin>>n;
  forn(i,n){
    int v=0,x;
    forn(q,4){
      int t;
      cin>>t;
      if(t)
	v|=1<<q;
    }
    cin>>x;
    A.pb(mp(v,x));
  }

  vals r=doit(0,sz(s));
  int ans=0;
  forn(i,L){
    bool ok=true;
    for(auto p:A){
      if(((i>>p.X)&1)!=p.Y){
	ok=false;
	break;
      }
    }
    if(ok)
      (ans+=r.A[i])%=mod;
  }
  cout<<ans;

  return 0;
}