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


vector<Int> zalgorithm(string s){
  Int n=s.size();
  vector<Int> a(n,0);
  a[0]=n;
  Int i=1,j=0;
  while(i<n){
    while(i+j<n&&s[j]==s[i+j]) j++;
    a[i]=j;
    if(j==0){
      i++;
      continue;
    }
    Int k=1;
    while(i+k<n&&k+a[k]<j) a[i+k]=a[k],k++;
    i+=k;
    j-=k;
  }
  return a;
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

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  string p;
  cin>>p;

  vector<Int> ys(m);
  for(Int i=0;i<m;i++) cin>>ys[i],ys[i]--;

  Int len=p.size();
  auto zs=zalgorithm(p);
  for(Int i=0;i+1<m;i++){
    if(ys[i]+len<=ys[i+1]) continue;
    Int k=ys[i+1]-ys[i];
    if(zs[k]!=len-k){
      cout<<0<<endl;
      return 0;
    }
  }

  Int cnt=0,res=0;
  vector<Int> ext(n,0);
  for(Int y:ys) ext[y]=1;
  for(Int i=0;i<n;i++){
    if(ext[i]) res=len;
    if(res==0) cnt++;
    res--;
    if(res<0) res=0;
  }

  using M = Mint<Int>;
  cout<<M(26).pow(cnt)<<endl;
  return 0;
}