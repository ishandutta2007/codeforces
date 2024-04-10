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

//INSERT ABOVE HERE
using M = Mint<Int, 998244353>;
const Int MAX = 3030;
M dp[MAX][MAX]={};
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> as(n),ws(n);
  for(Int i=0;i<n;i++) cin>>as[i];
  for(Int i=0;i<n;i++) cin>>ws[i];

  Int sum=0;
  for(Int i=0;i<n;i++) sum+=ws[i];
  
  Int pos=0,neg=0;
  for(Int i=0;i<n;i++){
    if(as[i]==0) neg+=ws[i];
    if(as[i]==1) pos+=ws[i];
  }
  
  vector<M> invs(MAX*2);
  for(Int i=0;i<MAX*2;i++)
    invs[i]=M(i-(MAX-sum)).inv();  
  
  dp[0][0]=M(1);
  for(Int x=0;x<=m;x++){
    for(Int y=0;x+y<=m;y++){      
      Int cnt=sum+x-y;
      if(cnt<0||neg-y<0) continue;
      dp[x+1][y]+=dp[x][y]*M(pos+x)*invs[cnt+(MAX-sum)];  
      dp[x][y+1]+=dp[x][y]*M(neg-y)*invs[cnt+(MAX-sum)];
    }                  
  }
  
  M sa(0),sb(0);
  for(Int j=0;j<=m;j++){
    sa+=dp[m-j][j]*(neg-j);
    sb+=dp[j][m-j]*(pos+j);
  }   
  
  for(Int i=0;i<n;i++){
    if(as[i]==0) cout<<(sa*M(ws[i])/M(neg)).v<<"\n";    
    if(as[i]==1) cout<<(sb*M(ws[i])/M(pos)).v<<"\n";   
  }
  
  return 0;
}