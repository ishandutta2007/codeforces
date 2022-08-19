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

const int B=60;

struct val{
  LL t[B];
  val operator+(const val &v)const{
    val r;
    forn(i,B){
      r.t[i]=t[i]+v.t[(i+t[i])%B];
    }
    return r;
  }
  static val road(int a){
    val r;
    forn(i,B){
      r.t[i]=1+(i%a==0);
    }
    return r;
  }
  static val zero(){
    val r;
    clr(r.t,0);
    return r;
  }
};

int n;
val T[410000];
int A[110000];

void init(int a,int b,int k){
  if(b==a+1){
    T[k]=val::road(A[a]);
    return;
  }
  int c=(a+b)/2;
  init(a,c,k*2+1);
  init(c,b,k*2+2);
  T[k]=T[k*2+1]+T[k*2+2];
}

val getsum(int l,int r,int a,int b,int k){
  if(l>=b || r<=a)
    return val::zero();
  if(l<=a && r>=b)
    return T[k];
  int c=(a+b)/2;
  return getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2);
}

void setval(int p,val v,int a,int b,int k){
  if(b==a+1){
    T[k]=v;
    return;
  }
  int c=(a+b)/2;
  if(p<c)
    setval(p,v,a,c,k*2+1);
  else
    setval(p,v,c,b,k*2+2);
  T[k]=T[k*2+1]+T[k*2+2];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  cin>>n;
  forn(i,n){
    cin>>A[i];
  }
  init(0,n,0);
  int tc;
  cin>>tc;
  forn(qqq,tc){
    char c;
    int x,y;
    cin>>c>>x>>y;
    if(c=='A'){
      --x;
      --y;
      val t=getsum(x,y,0,n,0);
      cout<<t.t[0]<<'\n';
    }else{
      --x;
      setval(x,val::road(y),0,n,0);
    }
  }

  return 0;
}