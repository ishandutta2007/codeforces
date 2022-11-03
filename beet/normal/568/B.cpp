#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M>
class Enumeration{
private:
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
    init(n+k-1);
    return C(n+k-1,k);
  }

  static M B(int n,int k){
    if(n==0) return M(1);
    k=min(k,n);
    init(k);
    vector<M> dp(k+1);
    dp[0]=M(1);
    for(int i=1;i<=k;i++)
      dp[i]=dp[i-1]+((i&1)?-finv[i]:finv[i]);
    M res(0);
    for(int i=1;i<=k;i++)
      res+=M(i).pow(n)*finv[i]*dp[k-i];
    return res;
  }

  static M LagrangePolynomial(vector<M> &y,M t){
    int n=y.size()-1;
    if(t.v<=n) return y[t.v];
    init(n+1);
    vector<M> dp(n+1,1),pd(n+1,1);
    for(int i=0;i<n;i++) dp[i+1]=dp[i]*(t-M(i));
    for(int i=n;i>0;i--) pd[i-1]=pd[i]*(t-M(i));
    M res(0);
    for(int i=0;i<=n;i++){
      M tmp=y[i]*dp[i]*pd[i]*finv[i]*finv[n-i];
      if((n-i)&1) res-=tmp;
      else res+=tmp;
    }
    return res;
  }
};
template<typename M>
vector<M> Enumeration<M>::fact=vector<M>();
template<typename M>
vector<M> Enumeration<M>::finv=vector<M>();
template<typename M>
vector<M> Enumeration<M>::invs=vector<M>();
//END CUT HERE
#ifndef call_from_test

//INSERT ABOVE HERE
signed YUKI_117(){
  int T;
  scanf("%d\n",&T);
  using M = Mint<int>;
  using E = Enumeration<M>;
  E::init(2e6+100);
  while(T--){
    char c;
    int n,k;
    scanf("%c(%d,%d)\n",&c,&n,&k);
    if(c=='C') printf("%d\n",E::C(n,k).v);
    if(c=='P') printf("%d\n",E::P(n,k).v);
    if(c=='H') printf("%d\n",E::H(n,k).v);
  }
  return 0;
}
/*
  verified on 2019/10/24
  https://yukicoder.me/problems/no/117
*/

signed ARC033_D(){
  int n;
  scanf("%d",&n);
  using M = Mint<int>;
  using E = Enumeration<M>;
  vector<M> y(n+1);
  for(int i=0;i<=n;i++) scanf("%d",&y[i].v);
  int t;
  scanf("%d",&t);
  printf("%d\n",E::LagrangePolynomial(y,M(t)).v);
  return 0;
}
/*
  verified on 2019/10/08
  https://atcoder.jp/contests/arc033/tasks/arc033_4
*/

signed YUKI_042(){
  using M = Mint<int, int(1e9+9)>;
  using E = Enumeration<M>;
  const int MAX = 666 * 6 + 10;
  vector<M> dp(MAX,0);
  dp[0]=M(1);

  for(int x:{1,5,10,50,100,500})
    for(int j=x;j<MAX;j++) dp[j]+=dp[j-x];

  int T;
  scanf("%d",&T);
  while(T--){
    using ll = long long;
    ll m;
    scanf("%lld",&m);
    vector<M> y(6);
    for(int i=0;i<6;i++) y[i]=dp[(m%500)+(i*500)];
    M ans=E::LagrangePolynomial(y,M(m/500));
    printf("%d\n",ans.v);
  }
  return 0;
}
/*
  verified on 2019/10/24
  https://yukicoder.me/problems/no/42
*/

signed main(){
  //YUKI_117();
  return 0;
}
#endif

#undef call_from_test

#endif
//BEGIN CUT HERE
// put n distinct balls into at most k identical boxes
template<typename M>
M bell(int n,int k){
  if(n==0) return M(1);

  using E = Enumeration<M>;
  k=min(k,n);
  E::init(k);

  vector<M> dp(k+1);
  dp[0]=M(1);
  for(int i=1;i<=k;i++)
    dp[i]=dp[i-1]+((i&1)?-E::Finv(i):E::Finv(i));

  M res(0);
  for(int i=1;i<=k;i++)
    res+=M(i).pow(n)*E::Finv(i)*dp[k-i];
  return res;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
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
//END CUT HERE
#ifndef call_from_test

//INSERT ABOVE HERE
signed ABC127_E(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int h,w,k;
  cin>>h>>w>>k;
  using M = Mint<int>;

  M ans{0};
  for(int d=1;d<h;d++)
    ans+=M(d)*M(h-d)*M(w)*M(w);

  for(int d=1;d<w;d++)
    ans+=M(d)*M(w-d)*M(h)*M(h);

  ans*=M::comb(h*w-2,k-2);
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/06/12
  https://atcoder.jp/contests/abc127/tasks/abc127_e
*/

signed main(){
  //ABC127_E();
  return 0;
}
#endif

#undef call_from_test

signed CFR315_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  using M = Mint<int>;
  using E = Enumeration<M>;
  E::init(n+1);

  M res;
  for(int i=0;i<n;i++)
    res+=E::C(n,i)*bell<M>(i,i);

  cout<<res.v<<endl;
  return 0;
}
/*
  verified on 2019/12/18
  https://codeforces.com/contest/568/problem/B
*/

signed main(){
  CFR315_B();
  return 0;
}
#endif