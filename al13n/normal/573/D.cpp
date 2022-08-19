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
#define hash asdhash
#define move asdmove
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const LL LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
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
template<size_t n,class... T> struct put1 { static ostream& put(ostream &s, const tuple<T...> &t){s<<get<sizeof...(T)-1-n>(t);if(n>1)s<<',';return put1<n-1,T...>::put(s,t);} };
template<class... T> struct put1<0,T...> { static ostream& put(ostream &s, const tuple<T...> &t){return s;} };
template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t){s<<"(";put1<sizeof...(T),T...>::put(s,t);s<<")";return s;}
#define dbg(...) cerr << #__VA_ARGS__ << " = " << make_tuple(__VA_ARGS__) << endl;

struct D{
  LL d[3][3];
};

vector<D> T;
vector<int> P;
vector<LL> A,B;

D unit(int a){
  D d;
  forn(i,3){
    forn(j,3){
      d.d[i][j]=-LINF;
      if(i+j==1)
	d.d[i][j]=0;
    }
  }
  if(P[a]!=a)
    d.d[0][0]=A[a]*B[a];
  return d;
}

D merge(D x,D y,int a,int b,int c){
  D d;
  forn(i,3){
    forn(j,3){
      d.d[i][j]=-LINF;
      if(i==2 && c==a+1)
	d.d[i][j]=y.d[1][j];
      if(j==2 && b==c+1)
	d.d[i][j]=x.d[i][1];
      if(x.d[i][0]>-LINF && y.d[0][j]>-LINF)
	d.d[i][j]=max(d.d[i][j],x.d[i][0]+y.d[0][j]);
      forn(k,2){
	if(x.d[i][1+k]>-LINF && y.d[2-k][j]>-LINF)
	  d.d[i][j]=max(d.d[i][j], x.d[i][1+k]+y.d[2-k][j] +
			max(A[c-1-k]*B[c-k] + A[c-k]*B[c+1-k] + A[c+1-k]*B[c-1-k],
			    B[c-1-k]*A[c-k] + B[c-k]*A[c+1-k] + B[c+1-k]*A[c-1-k]));
      }
      if(x.d[i][1]>-LINF && y.d[1][j]>-LINF)
	d.d[i][j]=max(d.d[i][j], x.d[i][1]+y.d[1][j] + A[c-1]*B[c]+A[c]*B[c-1]);
    }
  }
  return d;
}

void upd(int p,int a,int b,int k){
  if(b==a+1){
    T[k]=unit(a);
    return;
  }
  int c=(a+b)/2;
  if(p==-1 || p<c)
    upd(p,a,c,k*2+1);
  if(p==-1 || p>=c)
    upd(p,c,b,k*2+2);
  T[k]=merge(T[k*2+1],T[k*2+2],a,b,c);
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);

  int n,qc;
  cin>>n>>qc;
  T.resize(n*4+10);
  vector<pii> A(n),B(n);
  P.resize(n);
  forn(i,n){
    P[i]=i;
    cin>>A[i].X;
    A[i].Y=i;
  }
  forn(i,n){
    cin>>B[i].X;
    B[i].Y=i;
  }
  sort(all(A));
  sort(all(B));
  vector<int> iA(n),iB(n);
  forn(i,n){
    iA[A[i].Y]=i;
    iB[B[i].Y]=i;
  }
  ::A.resize(n);
  ::B.resize(n);
  forn(i,n){
    P[iA[i]]=iB[i];
    ::A[i]=A[i].X;
    ::B[i]=B[i].X;
  }
  upd(-1,0,n,0);

  forn(q,qc){
    int a,b;
    cin>>a>>b;
    --a;--b;
    a=iA[a];
    b=iA[b];
    int t=P[b];
    P[b]=P[a];
    upd(b,0,n,0);
    P[a]=t;
    upd(a,0,n,0);
    cout<<T[0].d[0][0]<<'\n';
  }
  
  return 0;
}