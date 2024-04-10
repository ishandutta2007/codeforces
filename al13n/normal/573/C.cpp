#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <array>
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
#define MT make_tuple
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
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const LL LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
LL sqrtup(LL a){if(!a)return 0;LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>=a)--x;while((x+1)*(x+1)<a)++x;return x+1;}
LL sqrtdown(LL a){LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>a)--x;while((x+1)*(x+1)<=a)++x;return x;}
template<class T> ostream& operator<<(ostream &s, const vector<T> &v);
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p);
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m);
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a);
template<class T> ostream& operator<<(ostream &s, const vector<T> &v){s<<'[';forv(i,v){if(i)s<<',';s<<v[i];}s<<']';return s;}
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p){s<<"("<<p.X<<","<<p.Y<<")";return s;}
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it.X<<": "<<it.Y;}s<<"}";return s;}
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a){s<<'[';forv(i,a){if(i)s<<',';s<<a[i];}s<<']';return s;}
//template<size_t i,class... T> struct put1 { static ostream& put(ostream &s, const tuple<T...> &t){if(i)s<<',';s<<get<i>(t);return put1<i+1,T...>::put(s,t);} };
//template<class... T> struct put1<sizeof...(T),T...> { static ostream& put(ostream &s, const tuple<T...> &t){return s;} };
//template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t){s<<"(";put1<0,T...>::put(s,t);s<<")";return s;}
//#define dbg(...) cerr << #__VA_ARGS__ << " = " << make_tuple(__VA_ARGS__) << endl;

vector<vector<int>> gr;
vector<int> T;
int v0;

int dfs1(int v,int pr){
  vector<int> ts;
  for(int p:gr[v]){
    if(p==pr)
      continue;
    //cerr<<v<<' '<<pr<<' '<<p<<endl;
    ts.pb(dfs1(p,v));
  }
  assert(!T[v]);
  if(!sz(ts) || (sz(ts)==1 && ts[0]==1))
    T[v]=1;
  else if(sz(ts)==2 && ts[0]==1 && ts[1]==1)
    T[v]=2;
  else
    T[v]=3;
  return T[v];
}

void dfs2(int v,int tp,int pr){
  vector<pii> ts(1,mp(tp,-1));
  for(int p:gr[v]){
    if(p==pr)
      continue;
    ts.pb(mp(T[p],p));
  }
  sort(all(ts));
  reverse(all(ts));
  if(ts[0].X<=2 || sz(ts)==1)
    return;
  int c=0;
  forv(i,ts){
    if(ts[i].X==3){
      ++c;
      if(ts[i].Y!=-1){
	int tt;
	if(sz(ts)==2 && ts[1].X==1)
	  tt=1;
	else if(sz(ts)==3 && ts[1].X==1)
	  tt=2;
	else
	  tt=3;
	dfs2(ts[i].Y,tt,v);
      }
    }
  }
  if(c>2){
    cout<<"No";
    exit(0);
  }
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);

  int n;
  cin>>n;
  if(n<4){
    cout<<"Yes";
    return 0;
  }
  gr.resize(n);
  T.resize(n);
  forn(i,n-1){
    int a,b;
    cin>>a>>b;
    --a;--b;
    gr[a].pb(b);
    gr[b].pb(a);
  }
  v0=-1;
  forn(i,n){
    assert(sz(gr[i]));
    if(sz(gr[i])==1)
      v0=i;
  }
  assert(v0!=-1);

  dfs1(v0,-1);
  dfs2(gr[v0][0],1,v0);
  cout<<"Yes";
  
  return 0;
}