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

struct mat{
  int n;
  vector<vector<ld>> a;

  mat(int n):n(n),a(n,vector<ld>(n)){}

  mat operator*(const mat &b)const{
    mat r(n);
    forn(i,n){
      forn(j,n){
        forn(k,n){
          r.a[i][j]+=a[i][k]*b.a[k][j];
        }
      }
    }
    return r;
  }

  void iden(){
    forn(i,n){
      a[i][i]=1;
    }
  }
};

mat pw(mat a,LL p){
  mat r(a.n);
  r.iden();
  while(p){
    if(p&1){
      r=r*a;
    }
    p>>=1;
    a=a*a;
  }
  return r;
}

int flip(int a,int x,int y){
  if(a<x || a>=y)
    return a;
  return x+(y-x-1)-(a-x);
}


int n,c;
vector<vector<int>> A;
vector<vector<int>> B;
vector<int> ans;

void nope(){
  cout<<"IMPOSSIBLE";
  exit(0);
}

int doit(int a){
  //cerr<<a<<endl;
  int mx1=sz(A[a])?*max_element(all(A[a])):-1;
  int mx2=sz(B[a])?*max_element(all(B[a])):-1;
  int mn2=sz(B[a])?*min_element(all(B[a])):-1;
  int t=a+1;
  if(sz(A[a])){
    while(t<=mx1)
      t=doit(t);
  }
  ans.pb(a);
  if(sz(B[a])){
    if(t>mn2)
      nope();
    while(t<=mx2)
      t=doit(t);
  }
  
  return t;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  cin>>n>>c;
  A.resize(n);
  B.resize(n);
  forn(i,c){
    int a,b;
    string s;
    cin>>a>>b>>s;
    --a;--b;
    if(b<=a){
      cout<<"IMPOSSIBLE";
      return 0;
    }
    if(s[0]=='L')
      A[a].pb(b);
    else
      B[a].pb(b);
  }

  int t=0;
  while(t<n)
    t=doit(t);

  forv(i,ans){
    cout<<ans[i]+1<<' ';
  }

  return 0;
}