#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename T,T MOD = 1000000007>
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

  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}

  // find x s.t. a^x = b
  static T log(T a,T b){
    const T sq=40000;
    unordered_map<T, T> dp;
    dp.reserve(sq);
    Mint res(1);
    for(Int r=0;r<sq;r++){
      if(!dp.count(res.v)) dp[res.v]=r;
      res*=a;
    }
    Mint p=Mint(a).inv().pow(sq);
    res=b;
    for(Int q=0;q<=MOD/sq+1;q++){
      if(dp.count(res.v)){
        T idx=q*sq+dp[res.v];
        if(idx>0) return idx;
      }
      res*=p;
    }
    assert(0);
    return T(-1);
  }

  static Mint comb(long long n,Int k){
    Mint num(1),dom(1);
    for(Int i=0;i<k;i++){
      num*=Mint(n-i);
      dom*=Mint(i+1);
    }
    return num/dom;
  }
};
template<typename T,T MOD> constexpr T Mint<T, MOD>::mod;
template<typename T,T MOD>
ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}


template<typename Data, typename T>
struct ReRooting{
  struct Node{
    Int to,rev;
    Data data;
    Node(Int to,Int rev,Data data):to(to),rev(rev),data(data){}
  };

  using F1 = function<T(T,T)>;
  using F2 = function<T(T,Data)>;

  vector<vector<Node> > G;
  vector<vector<T> > ld,rd;
  vector<Int> lp,rp;

  const F1 f1;
  const F2 f2;
  const T id;

  ReRooting(Int n,const F1 f1,const F2 f2,const T id):
    G(n),ld(n),rd(n),lp(n),rp(n),f1(f1),f2(f2),id(id){}

  void add_edge(Int u,Int v,Data d){
    G[u].emplace_back(v,(Int)G[v].size(),d);
    G[v].emplace_back(u,(Int)G[u].size()-1,d);
  }

  T dfs(Int v,Int p){
    while(lp[v]!=p&&lp[v]<(Int)G[v].size()){
      auto &e=G[v][lp[v]];
      ld[v][lp[v]+1]=f1(ld[v][lp[v]],f2(dfs(e.to,e.rev),e.data));
      lp[v]++;
    }
    while(rp[v]!=p&&rp[v]>=0){
      auto &e=G[v][rp[v]];
      rd[v][rp[v]]=f1(rd[v][rp[v]+1],f2(dfs(e.to,e.rev),e.data));
      rp[v]--;
    }
    if(p<0) return rd[v][0];
    return f1(ld[v][p],rd[v][p+1]);
  }

  vector<T> build(){
    for(Int i=0;i<(Int)G.size();i++){
      ld[i].assign((Int)G[i].size()+1,id);
      rd[i].assign((Int)G[i].size()+1,id);
      lp[i]=0;
      rp[i]=(Int)G[i].size()-1;
    }
    vector<T> res;
    for(Int i=0;i<(Int)G.size();i++){
      res.emplace_back(dfs(i,-1));
    }
    return res;
  }
};

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;

  using M = Mint<Int>;
  auto f1=[&](M a,M b){return a*b;};
  auto f2=[&](M a,Int d){return a+M(d);};
  M id(1);
  ReRooting<Int, M> G(n,f1,f2,id);
  for(Int i=1;i<n;i++){
    Int p;
    cin>>p;
    p--;
    G.add_edge(p,i,1);
  }

  auto res=G.build();
  for(Int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<res[i];
  }
  cout<<endl;
  return 0;
}