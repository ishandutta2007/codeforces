#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}


template<typename T,typename M1,typename M2,typename M3>
struct PolynomialHash{
  struct V{
    M1 v1;
    M2 v2;
    M3 v3;
    V(){}
    V(int x):v1(x),v2(x),v3(x){}
    V(long long x):v1(x),v2(x),v3(x){}
    V(M1 v1,M2 v2,M3 v3):v1(v1),v2(v2),v3(v3){}

    V& operator+=(V a){v1+=a.v1;v2+=a.v2;v3+=a.v3;;return *this;}
    V& operator-=(V a){v1-=a.v1;v2-=a.v2;v3-=a.v3;;return *this;}
    V& operator*=(V a){v1*=a.v1;v2*=a.v2;v3*=a.v3;;return *this;}
    V& operator/=(V a){v1/=a.v1;v2/=a.v2;v3/=a.v3;;return *this;}

    V operator+(V a) const{return V(*this)+=a;}
    V operator-(V a) const{return V(*this)-=a;}
    V operator*(V a) const{return V(*this)*=a;}
    V operator/(V a) const{return V(*this)/=a;}

    tuple<M1, M2, M3> norm() const{return make_tuple(v1,v2,v3);}

    bool operator==(const V a)const{return norm()==a.norm();}
    bool operator!=(const V a)const{return norm()!=a.norm();}
    bool operator <(const V a)const{return norm() <a.norm();}
  };
  const T BASE = 1777771;

  vector<M1> po1,op1;
  vector<M2> po2,op2;
  vector<M3> po3,op3;

  template<typename M>
  void init(int n,vector<M>& po,vector<M>& op){
    po.assign(n+1,1);
    op.assign(n+1,1);
    M x(BASE);
    M y=M(x).inv();
    for(int i=1;i<=(int)n;i++) po[i]=po[i-1]*x;
    for(int i=1;i<=(int)n;i++) op[i]=op[i-1]*y;
  }

  PolynomialHash(size_t n){
    init(n,po1,op1);
    init(n,po2,op2);
    init(n,po3,op3);
  }

  V build(const vector<T> &v){
    int n=v.size();
    M1 r1;M2 r2;M3 r3;
    for(int i=0;i<n;i++){
      r1+=M1(v[i])*po1[i];
      r2+=M2(v[i])*po2[i];
      r3+=M3(v[i])*po3[i];
    }
    return V(r1,r2,r3);
  }

  V term(size_t x,T k){
    M1 a1=po1[x]*M1((long long)k);
    M2 a2=po2[x]*M2((long long)k);
    M3 a3=po3[x]*M3((long long)k);
    return V(a1,a2,a3);
  }
};


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


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE

using M1 = Mint<int, 998244353>;
using M2 = Mint<int, 986567471>;
using M3 = Mint<int, int(1e9+9)>;
PolynomialHash<int, M1, M2, M3> ph(1);
using V = decltype(ph)::V;

const int MAX = 101;
V dp[MAX][MAX*MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto as=read(n);

  V one=ph.term(0,1);
  dp[0][0]=one;

  map<int, int> mp;
  for(int a:as) mp[a]++;

  if(mp.size()<=2) drop(n);

  int cnt=0,sum=0;
  for(auto p:mp){
    int a=p.first;
    int b=p.second;

    for(int i=cnt;i>=0;i--)
      for(int j=0;j<=sum;j++)
        for(int k=1;k<=b;k++)
          dp[i+k][j+a*k]+=dp[i][j];

    cnt+=b;
    sum+=b*a;
  }

  int ans=0;
  for(auto p:mp){
    int a=p.first;
    int b=p.second;

    for(int k=1;k<=b;k++)
      if(dp[cnt-k][sum-a*k]==one)
        chmax(ans,k);
  }
  cout<<ans<<newl;
  return 0;
}