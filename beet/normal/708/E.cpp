#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

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

using M = Mint<Int>;

template<typename M_>
class Enumeration{
  using M = M_;
protected:
  static vector<M> fact,finv,invs;
public:
  static void init(Int n){
    n=min<decltype(M::mod)>(n,M::mod-1);

    Int m=fact.size();
    if(n<m) return;

    fact.resize(n+1,1);
    finv.resize(n+1,1);
    invs.resize(n+1,1);

    if(m==0) m=1;
    for(Int i=m;i<=n;i++) fact[i]=fact[i-1]*M(i);
    finv[n]=M(1)/fact[n];
    for(Int i=n;i>=m;i--) finv[i-1]=finv[i]*M(i);
    for(Int i=m;i<=n;i++) invs[i]=finv[i]*fact[i-1];
  }

  static M Fact(Int n){
    init(n);
    return fact[n];
  }
  static M Finv(Int n){
    init(n);
    return finv[n];
  }
  static M Invs(Int n){
    init(n);
    return invs[n];
  }

  static M C(Int n,Int k){
    if(n<k||k<0) return M(0);
    init(n);
    return fact[n]*finv[n-k]*finv[k];
  }

  static M P(Int n,Int k){
    if(n<k||k<0) return M(0);
    init(n);
    return fact[n]*finv[n-k];
  }

  // put n identical balls into k distinct boxes
  static M H(Int n,Int k){
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

const Int MAX = 3030;
M pr[MAX]={};
M nx[MAX]={};

M smL[MAX]={};
M smR[MAX]={};

M nxL[MAX]={};
M nxR[MAX]={};

M pr_sum[MAX]={};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n,m;
  cin>>n>>m;

  Int a,b,k;
  cin>>a>>b>>k;

  if(a==b) drop(2*k<m);

  using E = Enumeration<M>;
  E::init(k);
  {
    M p=M(a)/M(b);
    M q=M(1)-p;

    M pp{1};
    M qq=q.pow(k);
    M qinv=q.inv();
    for(Int j=0;j+1<MAX;j++){
      pr[j]=pp*qq*E::C(k,j);
      pp*=p;
      qq*=qinv;
    }
  }
  // cout<<pr[0]<<' '<<pr[1]<<newl;

  // [0, j]
  pr_sum[0]=pr[0];
  for(Int j=1;j<MAX;j++)
    pr_sum[j]=pr_sum[j-1]+pr[j];

  M all{1};
  for(Int i=0;i<n;i++){
    for(Int j=0;j<=m+1;j++) nxL[j]=nxR[j]=M(0);
    {
      vector<M> cur(m+2,0);
      for(Int r=m;r>=1;r--){
        cur[r]=pr[m-r]*smL[r+1];
        cur[r]+=cur[r+1];
      }

      for(Int l=1;l<=m;l++){
        M res{0};
        res+=(all-smR[l-1])*pr_sum[m-l];
        res-=cur[l];
        nxL[l]+=pr[l-1]*res;
      }
    }

    {
      vector<M> cur(m+2,0);
      for(Int l=1;l<=m;l++){
        cur[l]=pr[l-1]*smR[l-1];
        cur[l]+=cur[l-1];
      }
      for(Int r=1;r<=m;r++){
        M res{0};
        res+=(all-smL[r+1])*pr_sum[r-1];
        res-=cur[r];
        nxR[r]+=pr[m-r]*res;
      }
    }

    for(Int j=0;j<=m;j++) nxR[j+1]+=nxR[j];
    for(Int j=m;j>=0;j--) nxL[j]+=nxL[j+1];

    assert(nxR[m+1]==nxL[0]);

    all=nxL[0];
    for(Int j=0;j<=m+1;j++){
      smL[j]=nxL[j];
      smR[j]=nxR[j];
    }
  }

  cout<<all<<newl;
  return 0;
}