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

struct segtree{
  vector<LL> xs;
  vector<pii> t;

  void add(LL x){
    xs.pb(x);
  }
  void init(){
    sort(all(xs));
    xs.erase(unique(all(xs)),xs.end());
    t.resize(sz(xs)*4+10);
  }

  void setmx(int p,pii v,int a,int b,int k){
    if(b==a+1){
      t[k]=max(t[k],v);
      return;
    }
    int c=(a+b)/2;
    if(p<c)
      setmx(p,v,a,c,k*2+1);
    else
      setmx(p,v,c,b,k*2+2);
    t[k]=max(t[k*2+1],t[k*2+2]);
  }

  void setmx(LL p,pii v){
    int i=lower_bound(all(xs),p)-xs.begin();
    assert(i<sz(xs) && xs[i]==p);
    setmx(i,v,0,sz(xs),0);
  }

  pii getmx(int l,int r,int a,int b,int k){
    if(l>=b || r<=a)
      return mp(0,0);
    if(l<=a && r>=b)
      return t[k];
    int c=(a+b)/2;
    return max(getmx(l,r,a,c,k*2+1),getmx(l,r,c,b,k*2+2));
  }

  pii getmx(LL l,LL r){
    int a=lower_bound(all(xs),l)-xs.begin();
    int b=lower_bound(all(xs),r)-xs.begin();
    return getmx(a,b,0,sz(xs),0);
  }
};

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  struct event{
    LL x,a,b,c;
    int id;
    bool chan;
    bool operator<(const event &e)const{
      return mp(x,x==b)<mp(e.x,e.x==b);
    }
  };

  vector<event> evs;
  int n,m;
  cin>>n>>m;
  segtree T;
  forn(i,n){
    LL a,b;
    cin>>a>>b;
    if(a==b)
      continue;
    T.add(a);
    evs.pb({a,a,b,0,i,false});
    evs.pb({b,a,b,0,i,false});
  }
  T.init();
  forn(i,m){
    LL a,b,c;
    cin>>a>>b>>c;
    if(a==b)
      continue;
    evs.pb({a,a,b,c,i,true});
    evs.pb({b,a,b,c,i,true});
  }

  sort(all(evs));
  set<pii> A,B;
  pair<LL,pii> ans(0,mp(0,0));
  for(event &e:evs){
    if(e.chan){
      if(e.x==e.a){
        if(sz(B))
          ans=max(ans,mp((min(e.b,-(LL)B.begin()->X)-e.a)*e.c,mp(B.begin()->Y,e.id)));
      }else{
        if(sz(A))
          ans=max(ans,mp((e.b-max(e.a,(LL)A.begin()->X))*e.c,mp(A.begin()->Y,e.id)));
        pii t=T.getmx(e.a,linf);
        if(t.X)
          ans=max(ans,mp(t.X*e.c,mp(t.Y,e.id)));
      }
    }else{
      if(e.x==e.a){
        A.insert(mp((int)e.a,e.id));
        B.insert(mp((int)-e.b,e.id));
      }else{
        A.erase(mp((int)e.a,e.id));
        B.erase(mp((int)-e.b,e.id));
        T.setmx(e.a,mp((int)(e.b-e.a),e.id));
      }
    }
  }

  cout<<ans.X<<'\n';
  if(ans.X)
    cout<<ans.Y.X+1<<' '<<ans.Y.Y+1<<'\n';

  return 0;
}