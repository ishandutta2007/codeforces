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

vector<pll> doit(vector<LL> A,vector<LL> D,LL L){
  cerr<<"doit"<<endl;
  A.pb(L);
  vector<pll> res(1,mp(A[0],0));
  vector<pll> st(1,mp(0,linf));
  forv(q,D){
    //cerr<<"see "<<A[q]<<' '<<D[q]<<endl;
    st.pb(mp(A[q],D[q]));
    while(true){
      LL to;
      if(sz(st)>1){
        to=st[sz(st)-2].X+st.back().Y*2;
        if(to>=L){
          cout<<0;
          exit(0);
        }
      }else
        to=linf;
      //cerr<<"to="<<to<<endl;
      if(to>res.back().X) {
        LL t=min(A[q+1],to);
        //cerr<<"res.pb "<<t<<' '<<st.back().X<<endl;
        res.pb(mp(t,st.back().X));
      }
      if(to>=A[q+1]){
        //cerr<<"break"<<endl;
        break;
      }
      st.pop_back();
      //cerr<<"pop; "<<st.size()<<" remain"<<endl;
    }
  }
  //cerr<<"done; res:";forv(i,res)cerr<<"("<<res[i].X<<' '<<res[i].Y<<"), ";cerr<<endl;
  return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  int n;
  cin>>n;
  LL L;
  vector<LL> A(n);
  vector<LL> D(n);
  forn(i,n+2){
    int a;
    cin>>a;
    if(i){
      if(i==n+1)
        L=a;
      else
        A[i-1]=a;
    }
  }
  forn(i,n){
    cin>>D[i];
  }

  auto v1 = doit(A,D,L);

  assert(v1.back().X==L);
  if(v1.back().Y==A.back()){
    cout<<0;
    return 0;
  }

  reverse(all(A));
  reverse(all(D));
  forv(i,A){
    A[i]=L-A[i];
  }
  auto v2=doit(A,D,L);

  vector<LL> K;
  forv(i,v1){
    K.pb(v1[i].X);
  }
  forv(i,v2){
    K.pb(L-v2[i].X);
  }
  sort(all(K));
  K.erase(unique(all(K)),K.end());
  assert(K[0]==0 && K.back()==L);

  LL ans=linf;
  for(LL k:K){
    LL a=  lower_bound(all(v1),mp(  k,-linf))->Y;
    LL b=L-lower_bound(all(v2),mp(L-k,-linf))->Y;
    assert(b>a);
    ans=min(ans,b-a);

    if(k!=L){
      a=lower_bound(all(v1),mp(k+1,-linf))->Y;
      assert(b>a);
      ans=min(ans,b-a);
    }
  }

  cout<<ans*.5;

  return 0;
}