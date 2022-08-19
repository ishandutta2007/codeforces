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

vector<vector<int>> go;
vector<int> C[2];
vector<vector<int>> id[2];

void add(string s,int c,int ii){
  int v=0;
  for(char x:s){
    x-='a';
    if(!go[v][x]){
      int vv=sz(go);
      go.emplace_back(26);
      C[0].pb(0);
      C[1].pb(0);
      id[0].emplace_back();
      id[1].emplace_back();
      go[v][x]=vv;
    }
    ++C[c][v];
    v=go[v][x];
  }
  ++C[c][v];
  id[c][v].pb(ii);
}

vector<int> ans;
LL ansi;

vector<int>* merge(vector<int>*a,vector<int>*b){
  if(!a)
    return b;
  if(!b)
    return a;
  if(sz(*a)<sz(*b))
    swap(a,b);
  for(int x:*b)
    a->pb(x);
  return a;
}

vector<vector<int>*> doit(int v){
  if(v)
    ansi+=min(C[0][v],C[1][v]);
  vector<vector<int>*> res(2);
  forn(c,2){
    if(sz(id[c][v]))
      res[c]=new vector<int>(id[c][v]);
  }
  forn(i,26){
    int vv=go[v][i];
    if(!vv)
      continue;
    auto t=doit(vv);
    forn(c,2)
      res[c]=merge(res[c],t[c]);
  }
  if(res[0]&&res[1]){
    while(sz(*res[0]) && sz(*res[1])){
      ans[res[0]->back()]=res[1]->back();
      res[0]->pop_back();
      res[1]->pop_back();
    }
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);

  go.emplace_back(26);
  C[0].pb(0);
  C[1].pb(0);
  id[0].emplace_back();
  id[1].emplace_back();
  
  int n;
  cin>>n;
  forn(i,n+n){
    string s;
    cin>>s;
    add(s,i<n,i%n);
  }
  ans.resize(n);
  doit(0);
  cout<<ansi<<'\n';
  forv(i,ans)
    cout<<ans[i]+1<<' '<<i+1<<'\n';
  
  return 0;
}