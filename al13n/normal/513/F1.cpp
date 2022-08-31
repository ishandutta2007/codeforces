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
  struct edge{
    int v,i,c;
  };

  vector<vector<edge>> gr;
  vector<char> W;
  int S,T;

  graph(int n):gr(n){}

  void add(int a,int b,int c){
    edge e1={b,sz(gr[b]),c};
    edge e2={a,sz(gr[a]),0};
    gr[a].pb(e1);
    gr[b].pb(e2);
  }

  bool dfs(int v){
    if(v==T)
      return true;
    if(W[v])
      return false;
    W[v]=true;
    forv(i,gr[v]){
      edge &e=gr[v][i];
      if(e.c && dfs(e.v)){
        edge &e2=gr[e.v][e.i];
        --e.c;
        ++e2.c;
        return true;
      }
    }
    return false;
  }

  bool flow(){
    W.assign(sz(gr),false);
    return dfs(S);
  }
};

vector<string> A;
vector<vector<int>> I;
int ii;

void numb(){
  I.resize(sz(A),vector<int>(sz(A[0]),-1));
  int c=0;
  forv(i,A){
    forv(j,A[0]){
      if(A[i][j]!='#')
        I[i][j]=c++;
    }
  }
  ii=c;
}

struct guy{
  int a,b,t;
  vector<pll> v;

  void read(){
    cin>>a>>b>>t;
    --a;--b;
  }

  void prep(){
    vector<vector<int>> D(sz(A),vector<int>(sz(A[0]),inf));
    queue<pii> qu;
    D[a][b]=0;
    qu.push(mp(a,b));
    while(!qu.empty()){
      pii p=qu.front();
      qu.pop();
      v.pb(mp(I[p.X][p.Y],D[p.X][p.Y]*1ll*t));
      int da[]={0,0,-1,1};
      int db[]={-1,1,0,0};
      forn(q,4){
        int aa=p.X+da[q];
        int bb=p.Y+db[q];
        if(aa<0||aa>=sz(A)||bb<0||bb>=sz(A[0])||D[aa][bb]!=inf||A[aa][bb]=='#')
          continue;
        D[aa][bb]=D[p.X][p.Y]+1;
        qu.push(mp(aa,bb));
      }
    }
  }
};

vector<guy> M,F;

bool check(LL k){
  int n=sz(M);
  graph g(n*2+ii*2+2);
  g.S=n*2+ii*2;
  g.T=g.S+1;
  forn(i,n){
    g.add(g.S,i,1);
    g.add(n+i,g.T,1);
  }
  forn(i,ii){
    g.add(n*2+i*2,n*2+i*2+1,1);
  }
  forv(q,M){
    forv(i,M[q].v){
      if(M[q].v[i].Y>k)
        break;
      g.add(q,n*2+2*M[q].v[i].X,1);
    }
    forv(i,F[q].v){
      if(F[q].v[i].Y>k)
        break;
      g.add(n*2+2*F[q].v[i].X+1,n+q,1);
    }
  }
  forn(i,n){
    if(!g.flow())
      return false;
  }
  return true;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  int n,m,x,y;
  cin>>n>>m>>x>>y;
  A.resize(n);
  forn(i,n){
    cin>>A[i];
  }
  numb();

  M.resize(x);
  F.resize(y);
  guy bi;
  bi.read();
  forn(i,x){
    M[i].read();
  }
  forn(i,y){
    F[i].read();
  }
  if(x<y)
    M.pb(bi);
  else
    F.pb(bi);

  if(sz(M)!=sz(F)){
    cout<<-1;
    return 0;
  }
  
  forv(i,M){
    M[i].prep();
  }
  forv(i,F){
    F[i].prep();
  }


  LL a=-1,b=inf*1000ll;
  while(b>a+1){
    LL k=(a+b)/2;
    if(check(k))
      b=k;
    else
      a=k;
  }

  if(b==inf*1000ll){
    cout<<-1;
    return 0;
  }

  cout<<b;

  return 0;
}