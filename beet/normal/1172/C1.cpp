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
};
template<typename T,T MOD> constexpr T Mint<T, MOD>::mod;


template<typename M>
struct Enumeration{
  static vector<M> fact,finv,invs;
  
  static void init(int n){
    n=min<decltype(M::mod)>(n,M::mod-1);
    
    int m=fact.size();
    if(n<m) return;

    fact.resize(n+1,1);
    finv.resize(n+1,1);
    invs.resize(n+1,1);
    
    if(m==0) m=1;
    for(int i=m;i<=n;i++) fact[i]=fact[i-1]*M(i);
    finv[n]=M(1)/fact[n];
    for(int i=n;i>=m;i--) finv[i-1]=finv[i]*M(i);
    for(int i=m;i<=n;i++) invs[i]=finv[i]*fact[i-1];
  }
  
  static M C(int n,int k){
    if(n<k||k<0) return M(0);
    init(n);
    return fact[n]*finv[n-k]*finv[k];
  }

  static M P(int n,int k){
    if(n<k||k<0) return M(0);
    init(n);
    return fact[n]*finv[n-k];
  }
  
  static M H(int n,int k){
    if(n<0||k<0) return M(0);
    if(!n&&!k) return M(1);
    init(n+k-1);
    return C(n+k-1,k);
  }

  static M S(int n,int k){
    M res;
    init(k);
    for(int i=1;i<=k;i++){
      M tmp=C(k,i)*M(i).pow(n);
      if((k-i)&1) res-=tmp;
      else res+=tmp;
    }    
    return res*=finv[k];
  }

  static vector<vector<M> > D(int n,int m){
    vector<vector<M> > dp(n+1,vector<M>(m+1,0));
    dp[0][0]=M(1);
    for(int i=0;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(i-j>=0) dp[i][j]=dp[i][j-1]+dp[i-j][j];
        else dp[i][j]=dp[i][j-1];
      }
    }
    return dp;
  }

  static M B(int n,int k){
    if(n==0) return M(1);
    k=min(k,n);
    init(k);    
    vector<M> dp(k+1);
    dp[0]=M(1);
    for(int i=1;i<=k;i++)
      dp[i]=dp[i-1]+((i&1)?-finv[i]:finv[i]);    
    M res;
    for(int i=1;i<=k;i++)
      res+=M(i).pow(n)*finv[i]*dp[k-i];    
    return res;
  }

  static M montmort(int n){
    M res;
    init(n);
    for(int k=2;k<=n;k++){
      if(k&1) res-=finv[k];
      else res+=finv[k];
    }
    return res*=fact[n];
  }

  static M LagrangePolynomial(vector<M> &y,M t){
    int n=y.size()-1;    
    if(t.v<=n) return y[t.v];
    init(n+1);
    M num(1);
    for(int i=0;i<=n;i++) num*=t-M(i);
    M res;
    for(int i=0;i<=n;i++){
      M tmp=y[i]*num/(t-M(i))*finv[i]*finv[n-i];
      if((n-i)&1) res-=tmp;
      else res+=tmp;
    }
    return res;
  }
};
template<typename M>
vector<M> Enumeration<M>::fact = vector<M>();
template<typename M>
vector<M> Enumeration<M>::finv = vector<M>();
template<typename M>
vector<M> Enumeration<M>::invs = vector<M>();

//INSERT ABOVE HERE
using M = Mint<int, 998244353>;
using E = Enumeration<M>;
const int MAX = 55;
M dp[MAX][MAX][MAX];
signed main(){
  int n,m;
  cin>>n>>m;
  vector<int> as(n),rs(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>rs[i];

  int sum=0;
  for(int i=0;i<n;i++) sum+=rs[i];    

  E::init(2e5);
  for(int t=0;t<n;t++){
    for(int x=0;x<MAX;x++)
      for(int y=0;y<MAX;y++)
        for(int z=0;z<MAX;z++)
          dp[x][y][z]=M(0);
    dp[0][0][0]=M(1);
    M res{0};

    int add=0,sub=0;
    for(int i=0;i<n;i++){
      if(t==i) continue;
      if(as[i]) add+=rs[i];
      else sub+=rs[i];      
    }
    for(int x=0;x<=m;x++){
      for(int y=0;x+y<=m;y++){
        for(int z=0;x+y+z<=m;z++){
          int cnt=sum+(as[t]?x:-x)+y-z;
          if(cnt<=0) continue;
          if(rs[t]+(as[t]?x:-x)<0) continue;
          if(sub-z<0) continue;          
          dp[x+1][y][z]+=dp[x][y][z]*M(rs[t]+(as[t]?x:-x))*E::invs[cnt];  
          dp[x][y+1][z]+=dp[x][y][z]*M(add+y)*E::invs[cnt];   
          dp[x][y][z+1]+=dp[x][y][z]*M(sub-z)*E::invs[cnt];   
                    
          if(x+y+z==m)
            res+=dp[x][y][z]*M(rs[t]+(as[t]?x:-x));          
        }                  
      }
    }
    cout<<res.v<<endl;
  }
  return 0;
}