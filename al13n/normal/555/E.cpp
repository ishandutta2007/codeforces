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
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const LL LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
#define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}

const int B=20;
vector<vector<vector<int>>> rq;

void nope(){
  cout<<"No";
  exit(0);
}

struct graph{
  vector<vector<int>> gr;
  vector<int> D;
  vector<int> up;
  vector<int> C;
  vector<vector<int>> J;

  graph(int n):gr(n),D(n,-1),up(n,-1),C(n,-1),J(B,vector<int>(n)){}

  void add(int a,int b){
    gr[a].pb(b);
    gr[b].pb(a);
  }
  
  void dfs1(int v,int pr,int d,int c){
    C[v]=c;
    D[v]=d;
    J[0][v]=pr;
    forn(i,B-1){
      J[i+1][v]=J[i][J[i][v]];
    }
    up[v]=d;
    for(int p:gr[v]){
      if(p==pr){
	pr=-1;
	continue;
      }
      if(D[p]!=-1){
	up[v]=min(up[v],D[p]);
      }else{
	dfs1(p,v,d+1,c);
	up[v]=min(up[v],up[p]);
      }
    }
  }

  int lca(int a,int b){
    if(D[b]>D[a])
      swap(a,b);
    for(int i=B-1;i>=0;--i)
      if(D[J[i][a]]>=D[b])
	a=J[i][a];
    assert(D[a]==D[b]);
    if(a==b)
      return a;
    for(int i=B-1;i>=0;--i){
      if(J[i][a]!=J[i][b]){
	a=J[i][a];
	b=J[i][b];
      }
    }
    return J[0][a];
  }

  pii dfs2(int v){
    C[v]=-1;
    pii r(D[v],D[v]);
    forn(q,2){
      for(int a:rq[q][v]){
	int &t=q?r.Y:r.X;
	t=min(t,D[lca(v,a)]);
      }
    }
    for(int p:gr[v]){
      if(C[p]==-1)
	continue;
      pii t=dfs2(p);
      r.X=min(r.X,t.X);
      r.Y=min(r.Y,t.Y);
    }
    if(up[v]==D[v] && r.X<D[v] && r.Y<D[v])
      nope();
    return r;
  }
};

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);

  int n,m,q;
  cin>>n>>m>>q;
  graph g(n);
  forn(i,m){
    int a,b;
    cin>>a>>b;
    --a;--b;
    g.add(a,b);
  }
  vector<int> rt;
  forn(i,n){
    if(g.C[i]==-1){
      g.dfs1(i,i,0,sz(rt));
      rt.pb(i);
    }
  }
  rq.resize(2);
  rq[0].resize(n);
  rq[1].resize(n);
  forn(i,q){
    int a,b;
    cin>>a>>b;
    --a;--b;
    if(g.C[a]!=g.C[b])
      nope();
    rq[0][a].pb(b);
    rq[1][b].pb(a);
  }
  for(int v:rt){
    g.dfs2(v);
  }
  cout<<"Yes";
  
  return 0;
}