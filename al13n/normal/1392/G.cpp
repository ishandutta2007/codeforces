#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
#include <random>
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
#define EB emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(&ar, val, sizeof(ar))
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
ld randf(){ld m=RAND_MAX+1.;return (((rand()+.5)/m+rand())/m+rand())/m;}
int rand30(){assert(RAND_MAX>=(1<<15)-1); return (int)((((uint32_t)rand())*(1u+(uint32_t)RAND_MAX)+(uint32_t)rand())&((1u<<30)-1));}
template<class T> void smin(T& a,T b){a=min(a,b);}
template<class T> void smax(T& a,T b){a=max(a,b);}
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
mt19937 mtrng;


int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);srand(35964);mtrng.seed(765674737);

  int n,M,k;
  cin>>n>>M>>k;
  int m0,m1;
  for(int* m:{&m0,&m1}){
    *m=0;
    string s;
    cin>>s;
    forn(i,k) if(s[i]=='1') *m|=1<<i;
  }
  if(__builtin_popcount(m1)*2>k){
    m0^=(1<<k)-1;
    m1^=(1<<k)-1;
  }
  int c0=__builtin_popcount(m0);
  int c1=__builtin_popcount(m1);
  const int lim=10;
  assert(c1<=lim);
  array<int,lim+1> a0;
  fill(all(a0),INF);
  vector<array<int,11>> A(1<<k,a0);
  vector<int> B(1<<k,-1);
  using perm=array<int,20>;
  auto pm=[k](int m,const perm&p){
            int mm=0;
            forn(i,k) mm|=((m>>i)&1)<<p[i];
            return mm;
          };
  {
    perm P;
    iota(all(P),0);
    forn(q,n+1){
      smin(A[pm(m0,P)][0],q);
      smax(B[pm(m1,P)],q);
      if(q<n){
        int a,b;
        cin>>a>>b;
        --a;--b;
        swap(P[a],P[b]);
      }
    }
  }

  forn(q,k){
    forn(m,1<<k){
      if(m&(1<<q)) continue;
      for(int s=min(lim,__builtin_popcount(m&((1<<q)-1)));s>=0;--s){
        smin(A[m|(1<<q)][min(lim,s+1)],A[m|(1<<q)][s]);
        int t=A[m|(1<<q)][s];
        A[m|(1<<q)][s]=A[m][s];
        A[m][s]=min(t,A[m][s]);
      }
    }
  }

  pair<int,pii> ans(-1,mp(-1,-1));
  forn(m,1<<k){
    if(B[m]==-1) continue;
    forn(s,c1+1){
      int v=s+((k-c0)-(c1-s));
      if(v<=ans.X) continue;
      if(B[m]-A[m][s]<M) continue;
      dbg(m,s,v,c0,c1);
      ans=mp(v,mp(A[m][s],B[m]));
    }
  }
  cout<<ans.X<<'\n'<<ans.Y.X+1<<' '<<ans.Y.Y;

  return 0;
}