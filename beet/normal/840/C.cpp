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


template<typename M_>
class Enumeration{
  using M = M_;
protected:
  static vector<M> fact,finv,invs;
public:
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

  static M Fact(int n){
    init(n);
    return fact[n];
  }
  static M Finv(int n){
    init(n);
    return finv[n];
  }
  static M Invs(int n){
    init(n);
    return invs[n];
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

  // put n identical balls into k distinct boxes
  static M H(int n,int k){
    if(n<0||k<0) return M(0);
    if(!n&&!k) return M(1);
    init(n+k);
    return C(n+k-1,n);
  }
};
template<typename M>
vector<M> Enumeration<M>::fact=vector<M>();
template<typename M>
vector<M> Enumeration<M>::finv=vector<M>();
template<typename M>
vector<M> Enumeration<M>::invs=vector<M>();

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto norm=[&](long long x){
    for(long long i=2;i*i<=x;i++)
      while(x%(i*i)==0) x/=i*i;
    return x;
  };

  map<int, int> cnt;
  for(int a:as) cnt[norm(a)]++;

  using M = Mint<int>;
  using E = Enumeration<M>;
  E::init(1e6);

  const int MAX = 303;
  array<M, MAX> dp;
  fill(dp.begin(),dp.end(),M(0));

  int sum=0;
  for(auto p:cnt){
    int num=p.second;
    if(sum==0){
      dp[num-1]=M(1);
      sum+=num;
      continue;
    }

    array<M, MAX> nx;
    fill(nx.begin(),nx.end(),M(0));

    for(int i=0;i<sum;i++){
      for(int j=1;j<=num;j++){
        for(int k=0;k<=min(i,j);k++){
          int ni=i+(num-j)-k;
          if(0<=ni and ni<MAX)
            nx[ni]+=dp[i]*E::H(num-j,j)*E::C(i,k)*E::C(sum+1-i,j-k);

          if(0 and 0<=ni and ni<MAX){
            cout<<i<<' '<<j<<' '<<k<<':'<<ni<<endl;
            cout<<dp[i]<<endl;
            cout<<E::H(num-j,j)<<endl;
            cout<<E::C(i,k)<<endl;
            cout<<E::C(sum+1-i,j-k)<<endl;
          }
        }
      }
    }

    sum+=num;
    swap(dp,nx);
  }

  M ans=dp[0];
  for(auto p:cnt)
    ans*=E::Fact(p.second);
  cout<<ans<<newl;
  return 0;
}