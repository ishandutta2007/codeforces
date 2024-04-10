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

struct bigraph{
  vector<vector<int>> G;
  vector<int> mt;
  vector<char> W;
  
  bigraph(int n,int m):G(n),mt(m,-1){}

  void add(int a,int b){
    G[a].pb(b);
  }

  bool dfs(int v){
    if(W[v]) return false;
    W[v]=true;
    for(int p:G[v]){
      if(mt[p]==-1 || dfs(mt[p])){
        mt[p]=v;
        return true;
      }
    }
    return false;
  }
  
  void match(){
    forv(i,G){
      W.assign(sz(G),0);
      dfs(i);
    }
  }

  void dfs2(int v,vector<char>&wr){
    if(W[v]) return;
    W[v]=1;
    for(int p:G[v]){
      wr[p]=1;
      if(mt[p]!=-1) dfs2(mt[p],wr);
    }
  }
  
  void independ(vector<char>&ansl,vector<char>&ansr){
    match();
    vector<char> T(sz(G));
    forv(i,mt) if(mt[i]!=-1) T[mt[i]]=1;
    W.assign(sz(G),0);
    forv(i,G) if(!T[i]) dfs2(i,ansr);
    forv(i,mt) ansr[i]^=1;
    ansl=W;
    dbg(G);
    dbg(vector<short>(all(ansl)));
    dbg(vector<short>(all(ansr)));
    dbg(mt);
  }
};

void solve(vector<pii> R, vector<pair<int,pii>>&ansr, vector<pair<int,pii>>&ansc){
  int n=sz(R);
  vector<pii> C(n);
  forn(i,n) C[i]=mp(R[i].Y,R[i].X);
  sort(all(R));
  sort(all(C));
  dbg(R);
  dbg(C);

  bigraph G(n,n);
  forn(i,n-1){
    if(R[i+1].X!=R[i].X) continue;
    forn(j,n-1){
      if(C[j+1].X!=C[j].X) continue;
      if(C[j].X>R[i].Y && C[j].X<R[i+1].Y && R[i].X>C[j].Y && R[i].X<C[j+1].Y) G.add(i,j);
    }
  }

  vector<char> AR(n),AC(n);
  G.independ(AR,AC);
  for(int i=0;i<n;){
    int j=i+1;
    while(j<n && R[j].X==R[i].X && AR[j-1]) ++j;
    ansr.pb(mp(R[i].X,mp(R[i].Y,R[j-1].Y)));
    i=j;
  }
  for(int i=0;i<n;){
    int j=i+1;
    while(j<n && C[j].X==C[i].X && AC[j-1]) ++j;
    ansc.pb(mp(C[i].X,mp(C[i].Y,C[j-1].Y)));
    i=j;
  }
}

vector<pii> inters(const vector<pair<int,pii>>&R,const vector<pair<int,pii>>&C){
  vector<pii> ans;
  for(auto a:R){
    for(auto b:C){
      if(a.X>=b.Y.X && a.X<=b.Y.Y && b.X>=a.Y.X && b.X<=a.Y.Y) ans.pb(mp(a.X,b.X));
    }
  }
  sort(all(ans));
  return ans;
}

void test(){
  vector<pii> A;
  for(int n=1;n<=20;++n){
    for(int s=1;s<=20;++s){
      if(s*s<n*2) continue;
      forn(qq,10000){
        A.resize(n*2);
        forv(i,A) A[i]=mp(rand()%s,rand()%s);
        sort(all(A));
        A.erase(unique(all(A)),A.end());
        if(sz(A)<n) continue;
        random_shuffle(all(A));
        A.erase(A.begin()+n,A.end());
        sort(all(A));
        vector<pair<int,pii>> r,c;
        solve(A,r,c);
        auto t=inters(r,c);
        if(A!=t){
          dbg(n,s,qq,A,r,c,t);
          return;
        }
      }
    }
  }
  dbg("ok");
}

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);srand(time(0));

  //test();return 0;
  
  int n;
  cin>>n;
  vector<pii> A(n);
  forn(i,n) cin>>A[i].X>>A[i].Y;
  vector<pair<int,pii>> ansr,ansc;
  solve(A,ansr,ansc);
  #ifdef __ASD__
  auto t=inters(ansr,ansc);
  sort(all(A));
  dbg(t);
  assert(t==A);
  #endif
  cout<<sz(ansc)<<'\n';
  for(auto p:ansc){
    cout<<p.Y.X<<' '<<p.X<<' '<<p.Y.Y<<' '<<p.X<<'\n';
  }
  cout<<sz(ansr)<<'\n';
  for(auto p:ansr){
    cout<<p.X<<' '<<p.Y.X<<' '<<p.X<<' '<<p.Y.Y<<'\n';
  }

  return 0;
}