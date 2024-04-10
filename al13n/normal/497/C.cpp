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
typedef pair<int, int> PII;
typedef pair<short, short> PSS;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<ULL, ULL> PUU;
typedef pair<LL, int> PLI;
typedef pair<int, LL> PIL;
typedef pair<ld, ld> PDD;
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
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  struct event{
    LL a,b,k;
    int id;
    bool dude;
    bool operator<(const event &e)const{
      return mp(a,!dude)<mp(e.a,!e.dude);
    }
  };

  vector<event> evs;
  int n;
  cin>>n;
  forn(i,n){
    event e;
    cin>>e.a>>e.b;
    e.id=i;
    e.dude=false;
    evs.pb(e);
  }
  int m;
  cin>>m;
  forn(i,m){
    event e;
    cin>>e.a>>e.b>>e.k;
    e.id=i;
    e.dude=true;
    evs.pb(e);
  }

  sort(all(evs));
  map<LL,vector<PLL>> A;
  vector<int> ans(n);
  for(event e:evs){
    if(e.dude){
      //cerr<<"+ "<<e.b<<": ("<<e.id<<","<<e.k<<endl;
      A[e.b].pb(mp(e.id,e.k));
      continue;
    }
    //cerr<<"? "<<e.b<<endl;
    auto it=A.lower_bound(e.b);
    if(it==A.end()){
      cout<<"NO";
      return 0;
    }
    auto &v=it->Y;
    assert(sz(v));
    assert(v.back().Y);
    --v.back().Y;
    ans[e.id]=v.back().X;
    if(!v.back().Y)
      v.pop_back();
    if(!sz(v))
      A.erase(it);
  }

  cout<<"YES\n";
  forv(i,ans){
    cout<<ans[i]+1<<' ';
  }

  return 0;
}