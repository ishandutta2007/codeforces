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

struct sufar{
static const int maxlen=1001000;
int pn[maxlen], cn[maxlen];
int p[maxlen], cnt[maxlen], c[maxlen];

void doit(const char *s, int n){
memset (cnt, 0, 200 * sizeof(int));
for (int i=0; i<n; ++i)
  ++cnt[s[i]];
for (int i=1; i<200; ++i)
  cnt[i] += cnt[i-1];
for (int i=0; i<n; ++i)
  p[--cnt[s[i]]] = i;
c[p[0]] = 0;
int classes = 1;
for (int i=1; i<n; ++i) {
  if (s[p[i]] != s[p[i-1]])  ++classes;
  c[p[i]] = classes-1;
}

for (int h=0; (1<<h)<n; ++h) {
  for (int i=0; i<n; ++i) {
    pn[i] = p[i] - (1<<h);
    if (pn[i] < 0)  pn[i] += n;
  }
  memset (cnt, 0, classes * sizeof(int));
  for (int i=0; i<n; ++i)
    ++cnt[c[pn[i]]];
  for (int i=1; i<classes; ++i)
    cnt[i] += cnt[i-1];
  for (int i=n-1; i>=0; --i)
    p[--cnt[c[pn[i]]]] = pn[i];
  cn[p[0]] = 0;
  classes = 1;
  for (int i=1; i<n; ++i) {
    int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
    if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
      ++classes;
    cn[p[i]] = classes-1;
  }
  memcpy (c, cn, n * sizeof(int));
}
}
};

sufar sa;
char S[2001000];
char S0[1001000];
int n;

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(0);

  gets(S);
  n=strlen(S);
  sa.doit(S,n);
  vector<int> ip(n);
  forn(i,n){
    ip[sa.p[i]]=i;
  }

  vector<int> mn1(n+1),mn2(n+1),A(n+1);
  forn(i,n){
    A[i+1]=A[i]+(S[i]=='('?1:-1);
    mn1[i+1]=min(mn1[i],A[i+1]);
  }
  mn2[n]=A[n];
  for(int i=n-1;i>=0;--i){
    mn2[i]=min(mn2[i+1],A[i]);
  }

  pair<pii,pair<pii,int>> res(mp(inf,inf),mp(mp(-1,-1),-1));
  forn(i,n){
    int m=min(mn1[i]+(A[n]-A[i]),mn2[i]-A[i]);
    assert(m<=0);
    int a=-m;
    int b=A[n]-m;
    res=min(res,mp(mp(a+b,ip[i]),mp(mp(a,b),i)));
    //cerr<<i<<": "<<m<<' '<<a<<' '<<b<<' '<<ip[i]<<endl;
  }

  rotate(S,S+res.Y.Y,S+n);
  int d=0;
  forn(i,res.Y.X.X){
    S0[i]='(';
    ++d;
  }
  printf("%s",S0);
  forn(i,res.Y.X.Y){
    S[n++]=')';
  }
  puts(S);
  forn(i,n){
    d+=(S[i]=='('?1:-1);
    assert(d>=0);
  }
  assert(d==0);

  return 0;
}