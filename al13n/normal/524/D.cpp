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

  int n,M,T;
  cin>>n>>M>>T;
  int N=24*3600;
  vector<vector<int>> A(N);
  forn(i,n){
    string s;
    cin>>s;
    int x=((s[0]-'0')*10+(s[1]-'0'))*3600+((s[3]-'0')*10+(s[4]-'0'))*60+((s[6]-'0')*10+(s[7]-'0'));
    assert(x>=0 && x<=N);
    A[x].pb(i);
  }

  vector<int> B(N+1);
  vector<int> res(n);
  int cur=0;
  int p=-1;
  int d=0;
  bool ok=false;
  forn(q,N){
    d+=B[q];
    for(int id: A[q]){
      if(d==M){
        assert(p!=-1);
        assert(cur>0);
        ++B[p];
        res[id]=cur;
      }else{
        ++d;
        if(d==M)
          ok=true;
        res[id]=++cur;
      }
      p=q+T;
      assert(p<=N);
      --B[p];
    }
  }
  if(!ok){
    cout<<"No solution";
    return 0;
  }
  cout<<cur<<'\n';
  forn(i,n){
    cout<<res[i]<<'\n';
  }

  return 0;
}