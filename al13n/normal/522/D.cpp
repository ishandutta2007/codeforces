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
  cin>>n>>m;
  vector<int> A(n);
  forn(i,n){
    cin>>A[i];
  }
  vector<pair<pii,int>> B(m);
  forn(i,m){
    cin>>B[i].X.X>>B[i].X.Y;
    --B[i].X.X;
    B[i].Y=i;
  }
  sort(all(B));
  vector<int> R(m);
  map<int,int> vs;
  map<int,int> rs;
  for(int i=n-1;i>=0;--i){
    if(vs.count(A[i])){
      do{
        int p=vs[A[i]];
        int d=p-i;
        auto it = rs.upper_bound(p);
        if(it!=rs.begin()) {
          auto it2=it;
          --it2;
          if(it2->Y<=d)
            break;
        }
        while(it != rs.end() && it->Y>=d){
          rs.erase(it++);
        }
        rs[p]=d;
      } while(false);
    }
    vs[A[i]]=i;
    while(sz(B) && B.back().X.X==i){
      auto it=rs.lower_bound(B.back().X.Y);
      int r=-1;
      if(it!=rs.begin()){
        --it;
        r=it->Y;
      }
      R[B.back().Y]=r;
      B.pop_back();
    }
  }

  forn(i,m)
    cout<<R[i]<<'\n';

  return 0;
}