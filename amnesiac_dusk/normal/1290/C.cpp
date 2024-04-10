// #pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
using namespace std;
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
template<typename A, typename B>
string to_string(pair<A, B> a) {
  return "{"+to_string(a.first)+","+to_string(a.second)+"}";
}
template<typename A>
string to_string(A v) {
  bool first=1;
  std::string res="{";
  for(auto x : v) {
    if(!first)
      res+=",";
    else
      first=0;
    res+=to_string(x);
  }
  res+="}";
  return res;
}
template<typename T>
void __f(const char* name, T arg1) {
  cout<<name<<" : "<<to_string(arg1)<<endl;
}
template<typename T, typename ... Args>
void __f(const char* names, T arg1, Args ... args) {
  const char* comma=strchr(names+1,',');
  cout.write(names,comma-names)<<" : "<<to_string(arg1)<<" | ";
  __f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0,lim-1);
  return uid(rang);
}

int dsu[300005],par[300005];
int sz1[300005];
int fpar(int i) {
  if(dsu[i]<0)
    return i;
  int pa=dsu[i];
  dsu[i]=fpar(dsu[i]);
  par[i]^=par[pa];
  return dsu[i];
}
int ans=0;
void merge(int u, int v, int w) {
  int uu=u,vv=v;
  if((u=fpar(u))!=(v=fpar(v))) {
    ans-=min(sz1[u],-sz1[u]-dsu[u]);
    ans-=min(sz1[v],-sz1[v]-dsu[v]);
    if(dsu[u]>dsu[v])
      swap(u,v);
    par[v]=par[uu]^par[vv]^w;
    if(par[v]) {
      sz1[u]+=-dsu[v]-sz1[v];
    } else
      sz1[u]+=sz1[v];
    dsu[u]+=dsu[v];
    dsu[v]=u;
    ans+=min(sz1[u],-sz1[u]-dsu[u]);
    trace(u,sz1[u],uu,vv);
  }
}

vi lol[300005];
void solve() {
  memset(dsu,-1,sizeof(dsu));
  int n,k;
  string ori;
  cin>>n>>k>>ori;
  fr(i,1,k) {
    int c;
    cin>>c;
    rep(j,0,c) {
      int hol;
      cin>>hol;
      lol[hol].pb(i);
    }
  }
  dsu[k+1]=-100000000;
  fr(i,1,n) {
    if(sz(lol[i])==1) {
      if(ori[i-1]=='0') {
        merge(k+1,lol[i][0],1);
      } else {
        merge(k+1,lol[i][0],0);    
      }
    } else if(sz(lol[i])==2) {
      if(ori[i-1]=='0') {
        merge(lol[i][1],lol[i][0],1);                
      } else {
        merge(lol[i][1],lol[i][0],0);        
      }
    }
    cout<<ans<<endl;
  }


}


signed main() {
#ifndef ONLINE_JUDGE
  freopen("input","r",stdin);
  freopen("output","w",stdout);
#endif
  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  cout<<fixed<<setprecision(10);
  int t=1;
  // cin>>t;
  fr(i,1,t)
    solve();
#ifndef ONLINE_JUDGE
  cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
}