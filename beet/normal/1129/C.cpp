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


template<typename T,T MOD,T B>
struct RollingHash{
  using ll = long long;
  vector<T> hash,po;
  RollingHash(){}
  RollingHash(vector<T> vs){init(vs);}
  RollingHash(string &s){
    vector<T> vs;
    for(char c:s) vs.emplace_back(c);
    init(vs);
  }
  void init(vector<T> vs){
    int n=vs.size();
    hash.assign(n+1,0);
    po.assign(n+1,1);
    for(int i=0;i<n;i++){
      hash[i+1]=((ll)hash[i]*B+vs[i])%MOD;
      po[i+1]=(ll)po[i]*B%MOD;
    }
  }
  //S[l, r)
  T find(int l,int r){
    T res=(ll)hash[r]+MOD-(ll)hash[l]*po[r-l]%MOD;
    return res>=MOD?res-MOD:res;
  }
};

using M = Mint<int>;
const int sz = 1<<5;
M dp[sz<<1],nx[sz<<1];

int mv1[sz<<1],mv2[sz<<1];

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  string s;
  for(int i=0;i<n;i++){
    char c;
    cin>>c;
    s+=c;
  }

  const int MOD = 1e9+9;
  const int B1 = 1777771;
  const int B2 = 1e9+7;
  RollingHash<int, MOD, B1> rh1(s);
  RollingHash<int, MOD, B2> rh2(s);

  using ll = long long;
  auto P=[&](ll x,ll y){return (x<<31)|y;};
  unordered_set<ll> seen;
  seen.reserve((int)1e7);

  for(int k=1;k<sz*2;k++){
    mv1[k]=k;
    mv2[k]=1;

    /*
      if(k> 0b11111 or
      k==0b10011 or
      k==0b10101 or
      k==0b11110 or
      k==0b11111) mv2[k]=0;
    */

    if(k> 0b11111 or
       k==0b11100 or
       k==0b11010 or
       k==0b10111 or
       k==0b11111) mv2[k]=0;
  }

  if(0){
    for(int p=0;p<2;p++){
      cout<<"if(p=="<<p<<"){"<<endl;
      for(int k=1;k<sz;k++){
        if(0 < mv1[(k<<1)|p] and mv1[(k<<1)|p] < sz)
          cout<<"nx["<<mv1[(k<<1)|p]<<"]+=dp["<<k<<"];"<<endl;
        if(0 < mv2[(k<<1)|p] and mv2[(k<<1)|p] < sz)
          cout<<"nx["<<mv2[(k<<1)|p]<<"]+=dp["<<k<<"];"<<endl;
      }
      cout<<"}"<<endl;
    }
  }

  M ans{0};
  for(int j=0;j<n;j++){
    fill(dp,dp+sz,M(0));
    dp[1]=M(1);
    for(int i=j;i>=0;i--){
      fill(nx,nx+sz,M(0));
      int p=s[i]-'0';
      for(int k=1;k<sz;k++){
        nx[mv1[(k<<1)|p]]+=dp[k];
        nx[mv2[(k<<1)|p]]+=dp[k];
      }
      copy(nx,nx+sz,dp);

      auto q=P(rh1.find(i,j+1),rh2.find(i,j+1));
      if(seen.count(q)) continue;
      seen.emplace(q);
      ans+=dp[1];
    }
    cout<<ans<<newl;
  }
  return 0;
}