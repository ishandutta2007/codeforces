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

struct graph{
  vector<vector<int>> gr;
  vector<vector<int>> gr2;
  vector<int> V;
  vector<char> W;

  graph(int n):gr(n),gr2(n),W(n){}

  void add(int a,int b){
    gr[a].pb(b);
    gr2[a].pb(b);
    gr2[b].pb(a);
  }

  void dfs1(int v){
    if(W[v])
      return;
    V.pb(v);
    W[v]=1;
    for(int vv: gr2[v])
      dfs1(vv);
  }

  bool dfs2(int v){
    if(W[v]==1)
      return true;
    if(W[v]==2)
      return false;
    W[v]=1;
    for(int vv: gr[v])
      if(dfs2(vv))
        return true;
    W[v]=2;
    return false;
  }
};

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  int n,m;
  cin>>n>>m;
  graph g(n);
  forn(i,m){
    int a,b;
    cin>>a>>b;
    --a;--b;
    g.add(a,b);
  }

  vector<vector<int>> V;
  forn(i,n){
    if(!g.W[i]){
      g.V.clear();
      g.dfs1(i);
      V.pb(g.V);
    }
  }
  int ans=0;
  g.W.assign(n,0);
  for(auto vs: V){
    ans+=sz(vs)-1;
    for(int v: vs){
      if(g.dfs2(v)){
        ++ans;
        break;
      }
    }
  }

  cout<<ans;

  return 0;
}