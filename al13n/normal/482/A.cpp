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

vector<int> solve(int n,int k){
  --k;
  int x=n;
  vector<int> A;
  for(int i=1;i<=n/2;++i){
    A.pb(i);
    if(k>=2){
      k-=2;
      A.pb(x--);
    }
  }
  if(k){
    A.pb(n/2+2);
    A.pb(n/2+1);
  } else {
    A.pb(n/2+1);
    if(n/2+2<=x)
      A.pb(n/2+2);
  }
  for(int i=n/2+3;i<=x;++i)
    A.pb(i);
  return A;
}

bool check(int n,int k,vector<int> A){
  set<int> s;
  forn(i,sz(A)-1){
    s.insert(abs(A[i+1]-A[i]));
  }
  if(sz(s)!=k)
    return false;
  if(sz(A)!=n)
    return false;
  sort(all(A));
  A.erase(unique(all(A)),A.end());
  if(A[0]<1 || A.back()>n || sz(A)!=n)
    return false;
  return true;
}

void print(vector<int> A){
  forv(i,A){
    cout<<A[i]<<' ';
  }
  cout<<endl;
}

void stress(){
  for(int n=2;n<=10000;++n){
    cerr<<n<<endl;
    for(int k=1;k<n;++k){
      vector<int> r=solve(n,k);
      if(!check(n,k,r)){
        cout<<"failed "<<n<<' '<<k<<":";
        print(r);
        return;
      }
    }
  }
  cout<<"passed"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  //stress();return 0;

  int n,k;
  cin>>n>>k;
  vector<int> r=solve(n,k);
  print(r);

	return 0;
}