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

bool isprime(LL x){
  static vector<LL> unprime;
  if(unprime.empty()){
    unprime.resize(10000000);
    unprime[0]=unprime[1]=1;
    for(LL i=2;i*i<sz(unprime);++i){
      if(unprime[i])
        continue;
      for(LL j=i*i;j<sz(unprime);j+=i)
        unprime[j]=true;
    }
  }
  if(x<sz(unprime))
    return !unprime[x];
  for(LL i=2;i*i<=x;++i){
    if(x%i==0)
      return false;
  }
  return true;
}

LL mul(LL a,LL b){
  if(b>linf/a)
    return linf;
  return
    a*b;
}

LL ppow(LL a,LL p){
  LL r=1;
  while(p){
    if(p&1){
      r=mul(r,a);
    }
    p>>=1;
    a=mul(a,a);
  }
  return r;
}

LL ispw(LL x){
  for(int k=1;(1ll<<k)<=x;++k){
    LL t=(LL)pow((ld)x,1./k);
    LL w;
    if((w=ppow(t,k))>x){
      --t;
      while((w=ppow(t,k))>x)
        --t;
    }else if(w<x){
      ++t;
      while((w=ppow(t,k))<x)
        ++t;
    }
    if(w==x && isprime(t))
      return t;
  }
  return -1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

  LL A;
  cin>>A;
  
  vector<LL> D;
  for(LL i=1;i*i<=A;++i){
    if(A%i)
      continue;
    D.pb(i);
    if(i*i!=A)
      D.pb(A/i);
  }
  sort(all(D));

  vector<LL> ps;
  vector<pll> go0;
  forv(i,D){
    LL d=D[i];
    LL p=ispw(d-1);
    if(p==-1)
      continue;
    ps.pb(p);
    go0.pb(mp(d,p));
  }
  ps.pb(1);
  sort(all(ps));
  ps.erase(unique(all(ps)),ps.end());
  vector<vector<pll>> go(sz(D));
  for(auto q:go0){
    LL d=q.X;
    int ii=lower_bound(all(ps),q.Y)-ps.begin();
    LL t=A/d;
    forv(j,D){
      if(t%D[j]==0)
        go[j].pb(mp(lower_bound(all(D),D[j]*d)-D.begin(),ii));
    }
  }

  vector<vector<pll>> dp(sz(ps));
  dp[0].pb(mp(0,1));
  LL ans=0;
  forv(q,dp){
    sort(all(dp[q]));
    forv(i,dp[q]){
      if(i+1<sz(dp[q]) && dp[q][i+1].X==dp[q][i].X){
        dp[q][i+1].Y+=dp[q][i].Y;
        continue;
      }
      if(dp[q][i].X+1==sz(D)){
        ans+=dp[q][i].Y;
        continue;
      }
      for(auto g:go[dp[q][i].X]){
        if(g.Y<=q)
          continue;
        dp[g.Y].pb(mp(g.X,dp[q][i].Y));
      }
    }
  }
  cout<<ans;

  return 0;
}