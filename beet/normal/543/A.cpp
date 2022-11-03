#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

Int MOD = 1000000007;
template<typename T>
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
template<typename T>
ostream& operator<<(ostream &os,Mint<T> m){os<<m.v;return os;}

//INSERT ABOVE HERE
using M = Mint<Int>;
const Int MAX = 505;
M dp[MAX][MAX];
M nx[MAX][MAX];

signed main(){
  Int n,m,b;
  cin>>n>>m>>b>>MOD;
  vector<Int> as(n);

  for(Int i=0;i<n;i++) cin>>as[i];

  for(Int j=0;j<MAX;j++)
    for(Int k=0;k<MAX;k++)
      dp[j][k]=0;
  dp[0][0]=M(1);

  for(Int i=0;i<n;i++){
    for(Int j=0;j<MAX;j++)
      for(Int k=0;k<MAX;k++)
        nx[j][k]=0;

    for(Int j=0;j<=m;j++){
      for(Int k=0;k<=b;k++){
        nx[j][k]=dp[j][k];
        if(j>=1&&k-as[i]>=0)
          nx[j][k]+=nx[j-1][k-as[i]];
      }
    }

    for(Int j=0;j<MAX;j++)
      for(Int k=0;k<MAX;k++)
        dp[j][k]=nx[j][k];
  }

  M ans{0};
  for(Int i=0;i<=b;i++) ans+=dp[m][i];
  cout<<ans<<endl;
  return 0;
}