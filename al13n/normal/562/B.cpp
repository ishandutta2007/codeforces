#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <numeric>
#include <cassert>
#include <deque>
#include <sstream>
using namespace std;
#define sz(x) ((int)((x).size()))
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef double ld;
const int INF=1000000000;
const LL LINF=1ll*INF*INF;
const ld EPS=1e-12;
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
template<class T>inline T sqr(T x){return x*x;}
#ifdef __ASD__
#define dbg(x) cerr << #x << "=" << (x) << endl
#define dbg0(x) cerr << x << endl
#else
#define dbg(x)
#define dbg0(x)
#endif
template<class T>
ostream& operator<<(ostream &s, const vector<T> &v){s<<"[";forv(i,v){if(i)s<<",";s<<v[i];}s<<"]";return s;}

const int lim=1010000;
vector<int> D(lim);
vector<int> dp(lim);

int doit(int a,int d){
  if(a==1)
    return dp[d];
  int p=D[a];
  assert(p>=2);
  int k=0;
  while(a%p==0){
    ++k;
    a/=p;
  }
  assert(k);
  int r=0;
  forn(i,k+1){
    r=max(r,doit(a,d));
    d*=p;
  }
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  /*
  cout<<1000000<<endl;
  forn(i,1000000)
    cout<<i+1<<' ';
    return 0;*/
  
  for(int p=2;p<lim;++p){
    if(D[p])
      continue;
    D[p]=p;
    for(LL k=1ll*p*p;k<lim;k+=p)
      D[k]=p;
  }

  int n;
  cin>>n;
  int r=0;
  forn(i,n){
    int a;
    cin>>a;
    r=max(r,dp[a]=doit(a,1)+1);
  }
  cout<<r<<endl;

  return 0;
}