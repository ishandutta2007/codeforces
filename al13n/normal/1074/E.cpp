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



int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);srand(time(0));

  int N,M;
  cin>>N>>M;
  vector<vector<int>> A(N,vector<int>(M));
  forn(i,N){
    forn(j,M){
      cin>>A[i][j];
      --A[i][j];
    }
  }
  vector<array<int,4>> ans;
  auto spin=[&](int a,int b,bool cw){
              assert(a>=0 && a+1<N && b>=0 && b+1<M);
              ans.pb({A[a][b],A[a][b+1],A[a+1][b+1],A[a+1][b]});
              int t=A[a][b];
              if(cw){
                A[a][b]=A[a+1][b];
                A[a+1][b]=A[a+1][b+1];
                A[a+1][b+1]=A[a][b+1];
                A[a][b+1]=t;
              }else{
                reverse(all(ans.back()));
                A[a][b]=A[a][b+1];
                A[a][b+1]=A[a+1][b+1];
                A[a+1][b+1]=A[a+1][b];
                A[a+1][b]=t;
              }
              //dbg(a,b,cw); forn(i,N){ forn(j,M) cerr<<A[i][j]<<' '; cerr<<'\n'; }
            };
  auto cw=[&](int a,int b) { spin(a,b,true); };
  auto ccw=[&](int a,int b) { spin(a,b,false); };
  auto lookup=[&](int x){
                forn(i,N) forn(j,M) if(A[i][j]==x) return MT(i,j);
                assert(false);
              };
  auto step=[&](int &a,int &b,int da,int db){
              assert(abs(da)+abs(db)==1);
              //dbg(a,b,da,db);
              int v0=A[a][b];
                   if(db== 1) if(a) ccw(a-1,b  ); else  cw(a,b  );
              else if(db==-1) if(a)  cw(a-1,b-1); else ccw(a,b-1);
              else if(da== 1) if(b)  cw(a  ,b-1); else ccw(a  ,b);
              else            if(b) ccw(a-1,b-1); else  cw(a-1,b);
              a+=da;
              b+=db;
              assert(A[a][b]==v0);
            };
  auto deliver=[&](int x,int ra,int rb){
                 int a,b;
                 tie(a,b)=lookup(x);
                 while(a>ra) step(a,b,-1,0);
                 while(b>rb) step(a,b,0,-1);
                 while(a<ra) step(a,b,1,0);
                 while(b<rb) step(a,b,0,1);
               };
  for(int a=N-1;a>=3;--a){
    for(int b=M-1;b>=2;--b) deliver(a*M+b,a,b);
    deliver(a*M+1,a,0);
    if(A[a][1]==a*M){
      ccw(a-1,0);
      ccw(a-2,0);
      cw(a-1,0);
      cw(a-2,0);
      cw(a-2,0);
    }else deliver(a*M,a-1,0);
    ccw(a-1,0);
    for(int aa=a;aa<N;++aa) for(int bb=0;bb<M;++bb) assert(A[aa][bb]==aa*M+bb);
  }
  for(int b=M-1;b>=3;--b){
    deliver(2*M+b,2,b);
    deliver(M+b,0,b);
    if(A[1][b]==b){
      cw(0,b-1);
      cw(0,b-2);
      ccw(0,b-1);
      cw(0,b-2);
      cw(0,b-2);
    }else deliver(b,0,b-1);
    cw(0,b-1);
    forn(i,N) forn(j,M) if(i>=3||j>=b) assert(A[i][j]==i*M+j);
  }
  forn(i,N) forn(j,M) if(i>=3||j>=3) assert(A[i][j]==i*M+j);

  using state=array<int,9>;
  auto scw=[](state s,int a){
              int t=s[a];
              s[a]=s[a+3];
              s[a+3]=s[a+4];
              s[a+4]=s[a+1];
              s[a+1]=t;
              return s;
            };
  map<state,int> W;
  queue<state> qu;
  state s0,to;
  forn(i,3) forn(j,3) s0[i*3+j]=A[i][j]/M*3+A[i][j]%M;
  iota(all(to),0);
  {
    state ts=s0;
    sort(all(ts));
    assert(ts==to);
  }
  qu.push(to);
  W[to]=-1;
  array<LL,1> its{};
  while(!W.count(s0)){
    ++its[0];
    assert(sz(qu));
    state s=qu.front();
    qu.pop();
    //if(its[0]%1==0) dbg(its,sz(W),sz(qu),s);
    forn(i,2){
      forn(j,2){
        state ss=scw(s,i*3+j);
        if(W.count(ss)) continue;
        W[ss]=i*3+j;
        qu.push(ss);
        sort(all(ss));
        assert(ss==to);
      }
    }
  }
  state s=s0;
  while(s!=to){
    int x=W.at(s);
    ccw(x/3,x%3);
    s=scw(scw(scw(s,x),x),x);
  }

  forn(i,N) forn(j,M) assert(A[i][j]==i*M+j);
  assert(sz(ans)*4<=100000);

  cout<<sz(ans)<<'\n';
  for(auto a:ans){
    cout<<4;
    forn(i,4) cout<<' '<<a[i]+1;
    cout<<'\n';
  }

  return 0;
}