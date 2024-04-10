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

int n;

struct graph{
  vector<pii> E;
  vector<int> is;
  vector<vector<int>> gr;
  vector<vector<int>> C;
  vector<int> I;
  vector<char> W;

  void dfs(int v){
    if(W[v])
      return;
    W[v]=true;
    C.back().pb(is[v]);
    for(int vv: gr[v]){
      dfs(vv);
    }
  }

  void doit(){
    for(auto e: E){
      is.pb(e.X);
      is.pb(e.Y);
    }
    sort(all(is));
    is.erase(unique(all(is)),is.end());
    gr.resize(sz(is));
    for(auto e: E){
      int a=lower_bound(all(is),e.X)-is.begin();
      int b=lower_bound(all(is),e.Y)-is.begin();
      gr[a].pb(b);
      gr[b].pb(a);
    }

    W.resize(sz(is));

    forv(v,is){
      if(W[v])
        continue;
      C.emplace_back();
      dfs(v);
    }
  }

  void getI(){
    I.resize(n,-1);
    forv(i,C){
      for(int v: C[i]){
        I[v]=i;
      }
    }
  }
};

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  int m;
  cin>>n>>m;
  vector<graph> G(m);
  forn(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    --a;--b;--c;
    G[c].E.pb(mp(a,b));
  }
  int q;
  cin>>q;
  vector<pii> Q(q);
  map<pii,int> Qi;
  forn(i,q){
    int a,b;
    cin>>a>>b;
    --a;--b;
    if(b<a)
      swap(a,b);
    Q[i]=mp(a,b);
    Qi[mp(a,b)];
  }
  const int B=300;
  vector<int> I;
  forv(i,G){
    graph &g=G[i];
    g.doit();
    if(sz(g.E)<B){
      for(auto &c: g.C){
        forv(bi,c){
          forn(ai,bi){
            int a=c[ai];
            int b=c[bi];
            if(b<a)
              swap(a,b);
            if(Qi.count(mp(a,b))){
              ++Qi[mp(a,b)];
            }
          }
        }
      }
    }else{
      g.getI();
      I.pb(i);
    }
  }

  forv(i,Q){
    int a,b;
    tie(a,b) = Q[i];
    int r=Qi[mp(a,b)];
    for(int gi: I){
      graph &g=G[gi];
      int x=g.I[a];
      int y=g.I[b];
      if(x!=-1 && x==y)
        ++r;
    }
    cout<<r<<'\n';
  }

  return 0;
}