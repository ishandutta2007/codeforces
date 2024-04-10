#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T> 
map<T, Int> factorize(T x){
  map<T, Int> res;
  for(Int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}


template<typename T,T MOD = 1000000007>
struct Mint{
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
  
  Mint inv(){return pow(MOD-2);}
  
  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}
  
  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-(){return v?MOD-v:v;}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}

  // find x s.t. a^x = b
  static T log(Mint a,Mint b){
    const T sq=40000;
    unordered_map<T, T> dp;
    dp.reserve(sq);
    Mint res(1);
    for(Int r=0;r<sq;r++){
      if(!dp.count(res)) dp[res]=r;
      res*=a;
    }
    Mint p=pow(a.inv(),sq);
    res=b;
    for(Int q=0;q<=MOD/sq+1;q++){
      if(dp.count(res)){
        T idx=q*sq+dp[res];
        if(idx>0) return idx;
      }
      res*=p;
    }    
    return T(-1);
  }

  static vector<Mint> fact,finv,invs;
  
  static void init(Int n){
    if(n+1<=(signed)fact.size()) return;
    fact.assign(n+1,1);
    finv.assign(n+1,1);
    invs.assign(n+1,1);
    
    for(Int i=1;i<=n;i++) fact[i]=fact[i-1]*Mint(i);
    finv[n]=Mint(1)/fact[n];
    for(Int i=n;i>=1;i--) finv[i-1]=finv[i]*Mint(i);
    for(Int i=1;i<=n;i++) invs[i]=finv[i]*fact[i-1];
  }

  static Mint comb(long long n,Int k){
    Mint res(1);
    for(Int i=0;i<k;i++){
      res*=Mint(n-i);
      res/=Mint(i+1);
    }
    return res;
  }
  
  static Mint C(Int n,Int k){
    if(n<k||k<0) return Mint(0);
    init(n);
    return fact[n]*finv[n-k]*finv[k];
  }

  static Mint P(Int n,Int k){
    if(n<k||k<0) return Mint(0);
    init(n);
    return fact[n]*finv[n-k];
  }
  
  static Mint H(Int n,Int k){
    if(n<0||k<0) return Mint(0);
    if(!n&&!k) return Mint(1);
    init(n+k-1);
    return C(n+k-1,k);
  }

  static Mint S(Int n,Int k){
    Mint res;
    init(k);
    for(Int i=1;i<=k;i++){
      Mint tmp=C(k,i)*Mint(i).pow(n);
      if((k-i)&1) res-=tmp;
      else res+=tmp;
    }    
    return res*=finv[k];
  }

  static vector<vector<Mint> > D(Int n,Int m){
    vector<vector<Mint> > dp(n+1,vector<Mint>(m+1,0));
    dp[0][0]=Mint(1);
    for(Int i=0;i<=n;i++){
      for(Int j=1;j<=m;j++){
        if(i-j>=0) dp[i][j]=dp[i][j-1]+dp[i-j][j];
        else dp[i][j]=dp[i][j-1];
      }
    }
    return dp;
  }

  static Mint B(Int n,Int k){
    Mint res;
    for(Int j=1;j<=k;j++) res+=S(n,j);
    return res;
  }

  static Mint montmort(Int n){
    Mint res;
    init(n);
    for(Int k=2;k<=n;k++){
      if(k&1) res-=finv[k];
      else res+=finv[k];
    }
    return res*=fact[n];
  }

  static Mint LagrangePolynomial(vector<Mint> &y,Mint t){
    Int n=y.size()-1;    
    if(t.v<=n) return y[t.v];
    init(n+1);
    Mint num(1);
    for(Int i=0;i<=n;i++) num*=t-Mint(i);
    Mint res;
    for(Int i=0;i<=n;i++){
      Mint tmp=y[i]*num/(t-Mint(i))*finv[i]*finv[n-i];
      if((n-i)&1) res-=tmp;
      else res+=tmp;
    }
    return res;
  }
};
template<typename T,T MOD>
vector<Mint<T, MOD> > Mint<T, MOD>::fact = vector<Mint<T, MOD> >();
template<typename T,T MOD>
vector<Mint<T, MOD> > Mint<T, MOD>::finv = vector<Mint<T, MOD> >();
template<typename T,T MOD>
vector<Mint<T, MOD> > Mint<T, MOD>::invs = vector<Mint<T, MOD> >();

//INSERT ABOVE HERE
signed main(){
  using M = Mint<Int>;
  Int n,k;
  cin>>n>>k;
  auto d=factorize(n);
  M::init(1000);
  
  M ans(1);
  for(auto p:d){
    Int x=p.first,s=p.second;
    vector<M> dp(s+1,0);
    dp[s]=1;
    for(Int i=0;i<k;i++){
      vector<M> nx(s+1,0);
      for(Int a=0;a<=s;a++)
        for(Int b=0;b<=a;b++)
          nx[b]+=dp[a]*M::invs[a+1];
      swap(dp,nx);
    }
    
    M res(0),tmp(1);
    for(Int a=0;a<=s;a++){
      res+=dp[a]*tmp;
      tmp*=M(x);
    }
    ans*=res;
  }

  cout<<ans.v<<endl;
  return 0;
}