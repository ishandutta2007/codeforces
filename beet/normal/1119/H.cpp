#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
// https://kazuma8128.hatenablog.com/entry/2018/05/31/144519
//BEGIN CUT HERE
template<typename T, typename F>
void fwht(vector<T> &as,F f){
  int n=as.size();
  for(int d=1;d<n;d<<=1)
    for(int m=d<<1,i=0;i<n;i+=m)
      for(int j=0;j<d;j++)
        f(as[i+j],as[i+j+d]);
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
auto divide_by_two(T x)
  ->enable_if_t<!is_class<T>::value, T>{
  return x/T(2);
}

template<typename T>
auto divide_by_two(T x)
  ->enable_if_t< is_class<T>::value, T>{
  static const T inv = T(2).inv();
  return x*inv;
}
auto zeta=[](auto& lo,auto& hi){
  auto x=lo+hi,y=lo-hi;
  lo=x;
  hi=y;
};
auto moebius=[](auto& lo,auto& hi){
  auto x=lo+hi,y=lo-hi;
  lo=divide_by_two(x);
  hi=divide_by_two(y);
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
template<typename T, T MOD = 1000000007>
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
template<typename T, T MOD> constexpr T Mint<T, MOD>::mod;
template<typename T, T MOD>
ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

#undef call_from_test

signed CGR002_H(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  const int MOD = 998244353;
  using M = Mint<int, MOD>;

  int n,k;
  cin>>n>>k;

  ll p,q,r;
  cin>>p>>q>>r;

  int ofs=0;
  vector<int> a(n),b(n),c(n);
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i]>>c[i];
    ofs^=a[i];
    b[i]^=a[i];
    c[i]^=a[i];
    a[i]=0;
  }

  vector<vector<ll> > vm((1<<k),vector<ll>(4,0));
  for(int t=0;t<4;t++){
    vector<ll> vs(1<<k,0);
    for(int i=0;i<n;i++){
      vs[a[i]]+=(t==0);
      vs[b[i]]+=(t==1);
      vs[c[i]]+=(t==2);
      vs[b[i]^c[i]]+=(t==3);
    }
    fwht(vs,zeta);
    for(int i=0;i<(1<<k);i++) vm[i][t]=vs[i];
  }

  vector<M> vs(1<<k,1);
  for(int i=0;i<(1<<k);i++){
    ll x=(vm[i][0]+vm[i][1]+vm[i][2]+vm[i][3])/4;
    ll y=(vm[i][0]+vm[i][1]-vm[i][2]-vm[i][3])/4;
    ll z=(vm[i][0]-vm[i][1]+vm[i][2]-vm[i][3])/4;
    ll w=(vm[i][0]-vm[i][1]-vm[i][2]+vm[i][3])/4;

    vs[i]*=M(p+q+r).pow(x);
    vs[i]*=M(p+q-r).pow(y);
    vs[i]*=M(p-q+r).pow(z);
    vs[i]*=M(p-q-r).pow(w);
  }

  fwht(vs,moebius);
  for(int i=0;i<(1<<k);i++){
    if(i) cout<<" ";
    cout<<vs[ofs^i].v;
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2020/11/15
  https://codeforces.com/contest/1119/problem/H
*/

//INSERT ABOVE HERE
signed main(){
  CGR002_H();
  return 0;
}
#endif