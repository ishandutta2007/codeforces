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
LL crt(LL a1,LL m1,LL a2,LL m2){LL a=(a2-a1%m2+m2)%m2;LL x,y,g;g=gcdex(m1,m2,x,y);if(a%g)return -1;LL m=m1/g*m2;assert(x+m2>=0);x=a/g*(x+m2)%m2;LL r=(a1+x*m1)%m;assert(r%m1==a1 && r%m2==a2);return r;}
LL powmod(LL a,LL p,LL m){assert(p>=0);LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
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

const int K=5;

struct val{
  array<int,K> v{},c{};

  val()=default;
  val(int x){
    v[0]=x;
    c[0]=1;
  }

  void add(int x,int n){
    pii mn(INF,-1);
    //dbg(*this,x,n);
    forv(i,v){
      if(v[i]==x&&c[i]){
        c[i]+=n;
        //dbg(i);
        return;
      }
      if(c[i]<n) mn=min(mn,mp(c[i],i));
    }
    dbg(mn);
    int q;
    if(mn.Y!=-1){
      v[mn.Y]=x;
      q=mn.X;
      c[mn.Y]=n;
    }else q=n;
    //dbg(q,*this);
    if(q)
      forv(i,v)
        c[i]=max(0,c[i]-q);
  }

  val operator+(const val&x)const{
    val r=*this;
    forv(i,v)
      if(x.c[i]>0)
        r.add(x.v[i],x.c[i]);
    dbg(*this,x,r);
    return r;
  }
};
ostream&operator<<(ostream&o,const val&x){
  o<<"{";
  bool w=false;
  forv(i,x.v){
    if(!x.c[i]) continue;
    if(w) o<<',';
    w=1;
    o<<x.v[i]<<":"<<x.c[i];
  }
  return o<<'}';
}

vector<int> A;

struct tree{
  vector<val> T;

  explicit tree(int n):T(n*4){}

  void init(int a,int b,int k){
    if(b==a+1){
      T[k]=val(A[a]);
      return;
    }
    int c=(a+b)/2;
    init(a,c,k*2+1);
    init(c,b,k*2+2);
    T[k]=T[k*2+1]+T[k*2+2];
  }

  val get(int l,int r,int a,int b,int k){
    if(l>=b || r<=a) return val();
    if(l<=a && r>=b) return T[k];
    int c=(a+b)/2;
    return get(l,r,a,c,k*2+1)+get(l,r,c,b,k*2+2);
  }
};

vector<int> solve(vector<int> A0,vector<pair<pii,int>> Q){
  A=move(A0);
  int n=sz(A);
  vector<vector<int>> I(n+1);
  forn(i,n)
    I[A[i]].pb(i);
  tree T(n);
  T.init(0,n,0);
  dbg(T.T);
  vector<int> ans;
  forv(q,Q){
    int a=Q[q].X.X,b=Q[q].X.Y,k=Q[q].Y;
    val v=T.get(a,b,0,n,0);
    dbg(q,v);
    int r=-1;
    forv(i,v.v){
      if(v.c[i]<=0) continue;
      int x=v.v[i];
      int c=lower_bound(all(I[x]),b)-lower_bound(all(I[x]),a);
      if(c*k>b-a && (r==-1||x<r))
        r=x;
    }
    ans.pb(r);
  }
  return ans;
}

vector<int> brute(vector<int> A,vector<pair<pii,int>> Q){
  vector<int> ans;
  vector<int> v;
  forv(q,Q){
    int a=Q[q].X.X,b=Q[q].X.Y,k=Q[q].Y;
    v.clear();
    for(int i=a;i<b;++i)
      v.pb(A[i]);
    sort(all(v));
    int r=-1;
    for(int i=0;i<sz(v);){
      int ii=i+1;
      while(ii<sz(v)&&v[ii]==v[i]) ++ii;
      if((ii-i)*k>b-a && (r==-1 || v[i]<r)) r=v[i];
      i=ii;
    }
    ans.pb(r);
  }
  return ans;
}

void stress(){
  for(int n=1;n<=100;++n){
    dbg(n);
    forn(qq,1000){
      vector<int> A(n);
      forn(i,n)
        A[i]=rand()%n+1;
      vector<pair<pii,int>> Q(100);
      forv(i,Q){
        int a=rand()%n,b=rand()%n,k=rand()%4+2;
        if(b<a) swap(a,b);
        Q[i]=mp(mp(a,b),k);
      }
      auto b=brute(A,Q);
      auto r=solve(A,Q);
      if(b!=r){
        int i=0;
        while(b[i]==r[i]) ++i;
        dbg(n,qq,A,Q[i],b[i],r[i]);
        Q[0]=Q[i];
        Q.resize(1);
        assert(solve(A,Q)[0]==r[i]);
        return;
      }
    }
  }
  dbg("ok");
}

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

  //stress();return 0;
  
  int n,q;
  cin>>n>>q;
  vector<int> a(n);
  forn(i,n)
    cin>>a[i];
  vector<pair<pii,int>> Q;
  forn(i,q){
    int a,b,k;
    cin>>a>>b>>k;
    --a;
    Q.pb(mp(mp(a,b),k));
  }
  auto r=solve(a,Q);
  forv(i,r)
    cout<<r[i]<<'\n';

  return 0;
}