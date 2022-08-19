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
const ld EPS = 1e-11;
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
LL mulmod(LL a,LL b,LL m){/*Schrage's*/assert(a>=0&&b>=0&&m>0&&a<m&&b<m);if(b<a)swap(a,b);if(m<INF*2||a<=1)return a*b%m;LL q=m/a,r=m%a;LL v=a*(b%q)-(r<q?r*(b/q):mulmod(r,b/q,m));if(v<0){v+=m;assert(v>=0);}return v;}
LL powmod2(LL a,LL p,LL m){a%=m;LL r=1;while(true){if(p&1) r=mulmod(r,a,m);p>>=1;if(p)a=mulmod(a,a,m);else break;}return r;}
bool isprime(LL a){if(a<=1)return false;for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
LL sqrtup(LL a){if(!a)return 0;LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>=a)--x;while((x+1)*(x+1)<a)++x;return x+1;}
LL isqrt(LL a){if(a<=0){assert(!a);return 0;}LL x=(LL)sqrt((ld)a);while(sqr(x+1)<=a)++x;while(x*x>a)--x;return x;}
LL sgn(LL x){return x<0?-1:x>0?1:0;}
ld randf(){ld m=RAND_MAX+1.;return (((rand()+.5)/m+rand())/m+rand())/m;}
int rand30(){assert(RAND_MAX>=(1<<15)-1); return (int)((((uint32_t)rand())*(1u+(uint32_t)RAND_MAX)+(uint32_t)rand())&((1u<<30)-1));}
template<class T> void smin(T& a,T b){a=min(a,b);}
template<class T> void smax(T& a,T b){a=max(a,b);}
ostream&operator<<(ostream&o,__int128 x){if(x<0)o<<'-',x=-x;if(x>=sqr((__int128)LINF))o<<(LL)(x/LINF/LINF)<<setw(18)<<setfill('0');if(x>=LINF)o<<(LL)(x/LINF%LINF)<<setw(18)<<setfill('0');return o<<(LL)(x%LINF);}
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

int solve(vector<pii> A,vector<pair<int,pii>> B){
  int n=sz(A),m=sz(B);
  auto manh=[](pii a,pii b){
              return abs(a.X-b.X)+abs(a.Y-b.Y);
            };
  sort(all(B));

  vector<vector<int>> DQ(1<<n,vector<int>(m,INF*2)),DT(1<<n,vector<int>(n,INF*2));
  forn(mask,1<<n){
    forn(q,m) forn(i,n) if(mask&(1<<i)) smin(DQ[mask][q],manh(A[i],B[q].Y));
    forn(t,n) forn(i,n) if(mask&(1<<i)) smin(DT[mask][t],manh(A[i],A[t]));
  }

  vector<vector<int>> Q(1<<n,vector<int>(m,-1)),T(1<<n,vector<int>(m+1,INF*2));
  priority_queue<pair<pii,pii>> qu;
  forn(q,m){
    Q[0][q]=1;
    qu.push(mp(mp(-B[q].X,0),mp(-1,q)));
  }
  forn(t,n){
    T[1<<t][0]=0;
    qu.push(mp(mp(-0,1),mp(1<<t,0)));
  }
  int ans=0;
  while(!qu.empty()){
    int d=-qu.top().X.X;
    int ty=qu.top().X.Y;
    int mask=qu.top().Y.X;
    int v=qu.top().Y.Y;
    qu.pop();
    //dbg(d,ty,mask,v);
    if(ty){
      assert(mask);
      if(d!=T[mask][v]) continue;
      forn(q,m){
        if(B[q].X<=d) continue;
        int tt=d+DQ[mask][q];
        if(tt>B[q].X || v+1<=Q[mask][q]) continue;
        //dbg(d,ty,mask,v,q);
        Q[mask][q]=v+1;
      }
      forn(t,n){
        if(mask&(1<<t)) continue;
        int tt=d+DT[mask][t];
        int mm=mask|(1<<t);
        if(tt>=T[mm][v]) continue;
        //dbg(d,ty,mask,v,t,mm,tt);
        T[mm][v]=tt;
        qu.push(mp(mp(-tt,1),mp(mm,v)));
      }
    }else{
      assert(d==B[v].X);
      forn(mask,1<<n){
        if(Q[mask][v]==-1) continue;
        smax(ans,Q[mask][v]);
        for(int q=v+1;q<m;++q){
          int tt=B[v].X+manh(B[q].Y,B[v].Y);
          if(mask) smin(tt,B[v].X+DQ[mask][q]);
          int dd=Q[mask][v]+1;
          if(tt>B[q].X || dd<=Q[mask][q]) continue;
          //dbg(d,ty,mask,v,q,dd);
          Q[mask][q]=dd;
        }
        forn(t,n){
          if(mask&(1<<t)) continue;
          int tt=B[v].X+manh(A[t],B[v].Y);
          if(mask) smin(tt,B[v].X+DT[mask][t]);
          int mm=mask|(1<<t);
          int cc=Q[mask][v];
          if(tt>=T[mm][cc]) continue;
          //dbg(d,ty,mask,v,t,mm,cc,tt);
          T[mm][cc]=tt;
          qu.push(mp(mp(-tt,1),mp(mm,cc)));
        }
      }
    }
  }
  //dbg(Q);
  //dbg(WQ);
  //dbg(T);
  return ans;
}

void gen(int n,int m,int clim,int tlim,vector<pii>&A,vector<pair<int,pii>>&B){
  n=10;
  m=100;
  clim=1000000;
  tlim=INF;
  
  A.resize(n);
  B.resize(m);
  forn(i,n) A[i]=mp(rand()%clim,rand()%clim);
  forn(i,m) B[i]=mp(rand()%tlim,mp(rand()%clim,rand()%clim));
}

void stress(){
  for(int n=0;n<=10;++n){
    dbg(n);
    for(int m=1;m<=10;++m){
      for(int lim=10;lim<=100;lim+=10){
        forn(qq,1000){
          vector<pii> A;
          vector<pair<int,pii>> B;
          gen(n,m,lim,lim,A,B);
          solve(A,B);
        }
      }
    }
  }
  dbg("ok");
}

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);srand(35964);mtrng.seed(765674737);

  //stress();
  
  int n,m;
  cin>>n>>m;
  vector<pii> A(n);
  forn(i,n) cin>>A[i].X>>A[i].Y;
  vector<pair<int,pii>> B(m);
  forn(i,m) cin>>B[i].Y.X>>B[i].Y.Y>>B[i].X;
  cout<<solve(A,B);

  return 0;
}