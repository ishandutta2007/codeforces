#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


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
template<typename T,T MOD> constexpr T Mint<T, MOD>::mod;
template<typename T,T MOD>
ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}


template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  vector<vector<int>> G(n);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  using M = Mint<int, 998244353>;
  vector<M> dp1(n),dp2(n),dp3(n);
  MFP([&](auto dfs,int v,int p)->void{
    dp1[v]=1;
    dp2[v]=0;

    vector<M> vs;
    for(int u:G[v]){
      if(u==p) continue;
      dfs(u,v);
      vs.emplace_back(dp1[u]+dp2[u]+dp2[u]);
    }

    // dp[i]: [0, i)
    // pd[i]: [i, n)

    int m=vs.size();
    vector<M> dp(m+1,1),pd(m+1,1);
    for(int i=0;i<m;i++) dp[i+1]=dp[i]*vs[i];
    for(int i=m-1;i>=0;i--) pd[i]=pd[i+1]*vs[i];

    int k=0;
    for(int u:G[v]){
      if(u==p) continue;
      dp1[v]*=dp1[u]+dp2[u];
      dp2[v]+=dp[k]*(dp1[u]+dp3[u])*pd[k+1];
      k++;
    }
    dp3[v]=dp[m]-dp1[v];
  })(0,-1);

  // cout<<dp1[0]<<' '<<dp2[0]<<newl;
  cout<<dp1[0]+dp2[0]<<newl;
  return 0;
}