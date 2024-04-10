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
#include <array>
#include <fstream>
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
template<class T> ostream& operator<<(ostream &s, const vector<T> &v){s<<"[";forv(i,v){if(i)s<<",";s<<v[i];}s<<"]";return s;}
template<class T,size_t S> ostream& operator<<(ostream &s, const array<T,S> &v){s<<"[";forv(i,v){if(i)s<<",";s<<v[i];}s<<"]";return s;}

vector<vector<int>> dsu;
map<int,int> A;

int merge(int a,int b){
  if(a==b)
    return a;
  if(sz(dsu[a])<sz(dsu[b]))
    swap(a,b);
  for(int p:dsu[b]){
    auto it=A.find(p);
    if(it==A.end())
      continue;
    assert(it->Y==b);
    dsu[a].pb(p);
    it->Y=a;
  }
  return a;
}

vector<char> solve(int n,vector<tuple<int,int,int>> Q){
  dsu.clear();
  A.clear();
  dsu.resize(n);
  forn(i,n){
    A[i]=i;
    dsu[i].pb(i);
  }

  vector<char> res;
  for(auto qq:Q){
    int type,a,b;
    tie(type,a,b)=qq;
    if(type==1){
      auto it=A.upper_bound(a);
      auto jt=A.upper_bound(b);
      assert(it!=A.begin());
      assert(jt!=A.begin());
      --it;
      --jt;
      merge(it->Y,jt->Y);
    }else if(type==2){
      auto it=A.upper_bound(a);
      assert(it!=A.begin());
      --it;
      int c=it->Y;
      for(++it;it!=A.end() && it->X<b;){
	c=merge(c,it->Y);
	A.erase(it++);
      }
    }else{
      auto it=A.upper_bound(a);
      auto jt=A.upper_bound(b);
      assert(it!=A.begin());
      assert(jt!=A.begin());
      --it;
      --jt;
      bool r=it->Y==jt->Y;
      res.pb(r);
    }
  }
  return res;
}

void print(int n, vector<tuple<int,int,int>> Q){
  ofstream out("t.txt");
  out<<n<<' '<<sz(Q)<<endl;
  for(auto q:Q){
    int t=get<0>(q);
    if(t!=2)
      ++get<2>(q);
    ++get<1>(q);
    out<<t<<' '<<get<1>(q)<<' '<<get<2>(q)<<'\n';
  }
}

vector<tuple<int,int,int>> gen(int n,int q){
  vector<tuple<int,int,int>> r;
  forn(qq,q){
    int t=rand()%3+1;
    int a=rand()%n;
    int b=rand()%n;
    if(t==2){
      if(b<a)
	swap(a,b);
      ++b;
    }
    r.pb(make_tuple(t,a,b));
  }
  return r;
}

void stress(){
  for(int n=1;n<=20;++n){
    forn(q,20){
      cerr<<n<<' '<<q<<endl;
      forn(qqq,1000){
	auto Q=gen(n,q);
	print(n,Q);
	solve(n,Q);
      }
    }
  }
  cout<<"ok"<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);

  //stress();return 0;
  
  int n,q;
  cin>>n>>q;
  vector<tuple<int,int,int>> Q;
  forn(qqq,q){
    int type,a,b;
    cin>>type>>a>>b;
    --a;
    if(type!=2)
      --b;
    Q.pb(make_tuple(type,a,b));
  }
  auto r=solve(n,Q);
  forv(i,r)
    cout<<(r[i]?"YES":"NO")<<'\n';
  
  return 0;
}