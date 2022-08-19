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

vector<int> solve(vector<int> A, bool fast=true){
  int n=sz(A);
  vector<int> res;
  const int B=450;
  vector<vector<int>> C(B,vector<int>(n+1));
  forn(q,min(n,B)){
    forn(i,n){
      C[q][i+1]=C[q][i]+(A[i]<A[q]);
    }
  }
  for(int k=1;k<n;++k){
    int r=0;
    if(fast && 1+k+1ll*k*k>=n){
      for(int i=1;i*k+1<n;++i){
        assert(i<=k);
        r+=C[i][min(n,i*k+k+1)]-C[i][min(n,i*k+1)];
      }
      r+=C[0][k+1]-C[0][1];
    }else{
      for(int i=1;i<n;++i){
        r+=A[i]<A[(i-1)/k];
      }
    }
    res.pb(r);
  }
  return res;
}

void stress(){
  for(int n=2;n<100;++n){
    vector<int> A(n);
    forn(i,n)
      A[i]=i;
    forn(q,10000){
      random_shuffle(all(A));
      auto b=solve(A,false);
      auto r=solve(A,true);
      if(b!=r){
        cerr<<"failed "<<n<<' '<<q<<endl;
        cout<<sz(A)<<endl;
        forv(i,A){
          cout<<A[i]<<' ';
        }
        return;
      }
    }
  }
  cerr<<"passed"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

//  stress();return 0;

  int n;
  cin>>n;
  vector<int> A(n);
  forn(i,n)
    cin>>A[i];
  vector<int> r=solve(A);
  forv(i,r)
    cout<<r[i]<<' ';

  return 0;
}