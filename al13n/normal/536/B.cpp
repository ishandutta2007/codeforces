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



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  int n,m;
  string P;
  cin>>n>>m>>P;

  vector<int> F(sz(P)+1);
  for(int i=2;i<=sz(P);++i){
    int k=F[i-1];
    while(k && P[k]!=P[i-1])
      k=F[k];
    if(P[k]==P[i-1])
      F[i]=k+1;
    else
      F[i]=0;
  }

  set<int> off;
  int k=sz(P);
  while(k){
    k=F[k];
    off.insert(k);
  }

  vector<int> A(m);
  forn(i,m){
    cin>>A[i];
    --A[i];
  }
  
  vector<int> evs(n+1);
  for(int i=0;i+1<sz(A);++i){
    if(!off.count(max(0,sz(P)-A[i+1]+A[i]))){
      cout<<0;
      return 0;
    }
  }
  forv(i,A){
    ++evs[A[i]];
    --evs[A[i]+sz(P)];
  }

  LL r=1;
  const LL mod=inf+7;
  int d=0;
  forn(i,n){
    d+=evs[i];
    if(!d)
      r=r*26%mod;
  }

  cout<<r;

  return 0;
}