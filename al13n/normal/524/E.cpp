#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
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
const ld EPS = 1e-9;
const int inf = 1000*1000*1000;
const char cinf = 102;
const LL linf = inf * 1ll * inf;
const ld dinf = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}

struct tree{
  int n;
  vector<int> t;

  tree(int n):n(n),t(n*4+10,inf){}

  void setv(int p,int v,int a=0,int b=-1,int k=0){
    if(b==-1)
      b=n;
    if(b==a+1){
      t[k]=v;
      return;
    }
    int c=(a+b)/2;
    if(p<c)
      setv(p,v,a,c,k*2+1);
    else
      setv(p,v,c,b,k*2+2);
    t[k]=max(t[k*2+1],t[k*2+2]);
  }

  int getmax(int l,int r,int a=0,int b=-1,int k=0){
    if(b==-1)
      b=n;
    if(l>=b || r<=a)
      return -inf;
    if(l<=a && r>=b)
      return t[k];
    int c=(a+b)/2;
    return max(getmax(l,r,a,c,k*2+1),getmax(l,r,c,b,k*2+2));
  }
};

int n,m,k,q;
vector<pii> ps;
vector<pair<pii,pii>> qs;
vector<int> res;

void solve(){
  vector<vector<int>> A(m);
  vector<vector<pair<pii,pii>>> Q(m);
  for(auto a:ps){
    A[a.Y].pb(a.X);
  }
  forv(i,qs){
    Q[qs[i].X.Y].pb(mp(mp(qs[i].X.X,qs[i].Y.X),mp(qs[i].Y.Y,i)));
  }

  cerr<<n<<' '<<m<<' '<<sz(ps)<<' '<<sz(qs)<<' '<<sz(res)<<endl;
  tree tr(n);
  for(int i=m-1;i>=0;--i){
    for(int a:A[i]){
      //cerr<<"x "<<a<<' '<<i<<endl;
      tr.setv(a,i);
    }
    for(auto t:Q[i]){
      int a1=t.X.X;
      int a2=t.X.Y;
      int b2=t.Y.X;
      int id=t.Y.Y;
      int z=tr.getmax(a1,a2);
      //cerr<<"y "<<a1<<' '<<a2<<' '<<z<<' '<<b2<<' '<<id<<endl;
      res[id]|=z<b2;
    }
  }
}

void turn(){
  swap(n,m);
  for(auto &a:ps){
    swap(a.X,a.Y);
  }
  for(auto &a:qs){
    swap(a.X.X,a.X.Y);
    swap(a.Y.X,a.Y.Y);
  }
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  cin>>n>>m>>k>>q;
  res.resize(q);
  ps.resize(k);
  qs.resize(q);
  forn(i,k){
    cin>>ps[i].X>>ps[i].Y;
    --ps[i].X;--ps[i].Y;
  }
  forn(i,q){
    cin>>qs[i].X.X>>qs[i].X.Y>>qs[i].Y.X>>qs[i].Y.Y;
    --qs[i].X.X;--qs[i].X.Y;
  }

  cerr<<"A"<<endl;
  solve();
  cerr<<"B"<<endl;
  turn();
  cerr<<"C"<<endl;
  solve();
  cerr<<"D"<<endl;

  forn(i,q){
    cout<<(res[i]?"YES":"NO")<<'\n';
  }

  return 0;
}