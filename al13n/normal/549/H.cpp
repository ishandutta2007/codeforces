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
typedef long double ld;
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
const ld eps = 1e-12;
const int inf = 1000*1000*1000;
const char cinf = 102;
const LL linf = inf * 1ll * inf;
const ld dinf = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
#define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}

struct mat{
  ld a[2][2];

  ld det(){
    return a[0][0]*a[1][1]-a[0][1]*a[1][0];
  }

  void add(ld v,int m){
    forn(i,4){
      a[i/2][i%2]+=v*((m&(1<<i))?1:-1);
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);

  mat M;
  forn(i,2)
    forn(j,2)
    cin>>M.a[i][j];

  ld d0=M.det();
  if(d0==0){
    cout<<0<<endl;
    return 0;
  }
  ld a=0,b=inf;
  forn(qqq,100){
    ld v=(a+b)*.5;
    bool ok=false;
    forn(m,1<<4){
      mat t=M;
      t.add(v,m);
      if(t.det()*d0<0)
	ok=true;
    }
    if(ok)
      b=v;
    else
      a=v;
  }
  cout.precision(15);
  cout<<fixed<<(a+b)*.5<<endl;
  
  return 0;
}