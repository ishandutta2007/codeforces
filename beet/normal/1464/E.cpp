#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}


// O(n \log n)
template<typename T, typename F>
void fwht(vector<T> &as,F f){
  int n=as.size();
  for(int d=1;d<n;d<<=1)
    for(int m=d<<1,i=0;i<n;i+=m)
      for(int j=0;j<d;j++)
        f(as[i+j],as[i+j+d]);
}


auto zeta=[](auto& lo,auto& hi){
  auto x=lo+hi,y=lo-hi;
  lo=x;
  hi=y;
};
auto moebius=[](auto& lo,auto& hi){
  auto x=lo+hi,y=lo-hi;
  lo=x/decltype(x)(2);
  hi=y/decltype(y)(2);
};


struct TopologicalSort{
  vector<vector<int>> G;
  vector<int> indeg;
  TopologicalSort(int n):G(n),indeg(n,0){}

  void add_edge(int s,int t){
    G[s].emplace_back(t);
    indeg[t]++;
  }

  vector<int> build(){
    int n=G.size();

    queue<int> que;
    vector<int> used(n,0);
    auto push=[&](int v){
      if(used[v]) return;
      que.emplace(v);
      used[v]=1;
    };

    for(int i=0;i<n;i++)
      if(indeg[i]==0) push(i);

    vector<int> ps;
    while(!que.empty()){
      int v=que.front();que.pop();
      ps.emplace_back(v);
      for(int u:G[v]){
        indeg[u]--;
        if(indeg[u]==0) push(u);
      }
    }

    if(n!=(int)ps.size()) return {};
    return ps;
  }
};


template<typename T, T MOD = 1000000007>
struct Mint{
  static constexpr T mod = MOD;
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(long long k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }

  static Mint add_identity(){return Mint(0);}
  static Mint mul_identity(){return Mint(1);}

  Mint inv(){return pow(MOD-2);}

  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}

  Mint operator+(Mint a) const{return Mint(v)+=a;}
  Mint operator-(Mint a) const{return Mint(v)-=a;}
  Mint operator*(Mint a) const{return Mint(v)*=a;}
  Mint operator/(Mint a) const{return Mint(v)/=a;}

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}

  static Mint comb(long long n,int k){
    Mint num(1),dom(1);
    for(int i=0;i<k;i++){
      num*=Mint(n-i);
      dom*=Mint(i+1);
    }
    return num/dom;
  }
};
template<typename T, T MOD> constexpr T Mint<T, MOD>::mod;
template<typename T, T MOD>
ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  TopologicalSort G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b);
  }
  auto ps=G.build();
  reverse(ps.begin(),ps.end());
  vector<int> dp(n);
  for(int v:ps){
    set<int> ss;
    for(int u:G.G[v])
      ss.emplace(dp[u]);
    while(ss.count(dp[v])) dp[v]++;
  }

  using M = Mint<int, 998244353>;
  vector<M> gs(1<<10);
  for(int i=0;i<n;i++)
    gs[dp[i]]+=M(1)/M(n+1);

  fwht(gs,zeta);
  for(auto &e:gs) e=M(1)/(M(1)-e);
  fwht(gs,moebius);

  cout<<M(1)-gs[0]/M(n+1)<<newl;
  return 0;
}