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



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  int n,m;
  const int B=30;
  cin>>n>>m;
  vector<pair<PII,int>> A(m);
  vector<vector<int>> D(n+1,vector<int>(B));
  forn(i,m){
    cin>>A[i].X.X>>A[i].X.Y>>A[i].Y;
    --A[i].X.X;
    forn(j,B){
      if(A[i].Y&(1<<j)) {
        ++D[A[i].X.X][j];
        --D[A[i].X.Y][j];
      }
    }
  }
  vector<int> R(n);
  vector<vector<int>> C(n+1,vector<int>(B));
  vector<int> d(B);
  forn(i,n){
    forn(j,B){
      d[j]+=D[i][j];
    }
    forn(j,B){
      C[i+1][j]=C[i][j];
      if(d[j]){
        R[i]|=1<<j;
        ++C[i+1][j];
      }
    }
  }
  forn(i,m){
    forn(j,B){
      if((C[A[i].X.Y][j]-C[A[i].X.X][j]==A[i].X.Y-A[i].X.X)!=!!(A[i].Y&(1<<j))){
        cout<<"NO";
        return 0;
      }
    }
  }
  cout<<"YES\n";
  forv(i,R){
    cout<<R[i]<<' ';
  }
  cout<<endl;

	return 0;
}