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
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> PII;
typedef pair<short, short> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<ulng, ulng> PUU;
typedef pair<lng, int> PLI;
typedef pair<int, lng> PIL;
typedef pair<ld, ld> PDD;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
inline lng parse(const string & s) { stringstream ss(s); lng x; ss >> x; return x; }
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
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}

const lng mod=INF+7;
vector<vector<int>> gr;

PLL dfs(int v){
  int n=sz(gr[v]);
  vector<PLL> ts(n);
  forn(i,n){
    ts[i]=dfs(gr[v][i]);
  }

  vector<PLL> dp1(n+1);
  vector<PLL> dp2(n+1);

  forn(qqq,2){
    dp1.assign(n+1,mp(0,0));
    dp1[0].X=1;
    forn(i,n){
      (dp1[i+1].X+=dp1[i].X*(1+ts[i].X))%=mod;
      (dp1[i+1].Y+=dp1[i].Y*(1+ts[i].X))%=mod;
      (dp1[i+1].X+=dp1[i].Y*ts[i].Y)%=mod;
      (dp1[i+1].Y+=dp1[i].X*ts[i].Y)%=mod;
    }
    reverse(all(ts));
    swap(dp1,dp2);
  }

  vector<PLL> dp3(n+1);
  dp3[0]=mp(1,0);
  forn(i,n){
    (dp3[i+1].X+=dp3[i].X*1)%=mod;
    (dp3[i+1].Y+=dp3[i].Y*1)%=mod;
    (dp3[i+1].X+=dp3[i].Y*ts[i].Y)%=mod;
    (dp3[i+1].Y+=dp3[i].X*ts[i].Y)%=mod;
  }

  vector<lng> dp4(n+1);
  dp4[0]=1;
  forn(i,n){
    (dp4[i+1]+=dp4[i]*(1+ts[i].X))%=mod;
  }

  PLL r((dp1.back().X+dp2.back().X+mod-dp4.back())%mod,(dp1.back().Y+dp2.back().Y+mod-dp3.back().Y)%mod);
  swap(r.X,r.Y);
  return r;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  int n;
  cin>>n;
  gr.resize(n);
  forn(i,n-1){
    int p;
    cin>>p;
    --p;
    gr[p].pb(i+1);
  }

  PLL r=dfs(0);
  cout<<(r.X+r.Y)%mod<<endl;

  return 0;
}