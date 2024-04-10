#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


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


constexpr int bmds(int x){
  const int v[] = {1012924417, 924844033, 998244353,
                   897581057, 645922817};
  return v[x];
}
constexpr int brts(int x){
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}

template<int X>
struct NTT{
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);
  using M = Mint<int, md>;
  vector< vector<M> > rts,rrts;

  void ensure_base(int n){
    if((int)rts.size()>=n) return;
    rts.resize(n);rrts.resize(n);
    for(int i=1;i<n;i<<=1){
      if(!rts[i].empty()) continue;
      M w=M(rt).pow((md-1)/(i<<1));
      M rw=w.inv();
      rts[i].resize(i);rrts[i].resize(i);
      rts[i][0]=M(1);rrts[i][0]=M(1);
      for(int k=1;k<i;k++){
        rts[i][k]=rts[i][k-1]*w;
        rrts[i][k]=rrts[i][k-1]*rw;
      }
    }
  }

  void ntt(vector<M> &as,bool f){
    int n=as.size();
    assert((n&(n-1))==0);
    ensure_base(n);

    for(int i=0,j=1;j+1<n;j++){
      for(int k=n>>1;k>(i^=k);k>>=1);
      if(i>j) swap(as[i],as[j]);
    }

    for(int i=1;i<n;i<<=1){
      for(int j=0;j<n;j+=i*2){
        for(int k=0;k<i;k++){
          M z=as[i+j+k]*(f?rrts[i][k]:rts[i][k]);
          as[i+j+k]=as[j+k]-z;
          as[j+k]+=z;
        }
      }
    }

    if(f){
      M tmp=M(n).inv();
      for(int i=0;i<n;i++) as[i]*=tmp;
    }
  }

  vector<M> multiply(vector<M> as,vector<M> bs){
    int need=as.size()+bs.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    as.resize(sz,M(0));
    bs.resize(sz,M(0));

    ntt(as,0);ntt(bs,0);
    for(int i=0;i<sz;i++) as[i]*=bs[i];
    ntt(as,1);

    as.resize(need);
    return as;
  }

  vector<int> multiply(vector<int> as,vector<int> bs){
    vector<M> am(as.size()),bm(bs.size());
    for(int i=0;i<(int)am.size();i++) am[i]=M(as[i]);
    for(int i=0;i<(int)bm.size();i++) bm[i]=M(bs[i]);
    vector<M> cm=multiply(am,bm);
    vector<int> cs(cm.size());
    for(int i=0;i<(int)cs.size();i++) cs[i]=cm[i].v;
    return cs;
  }
};
template<int X> constexpr int NTT<X>::md;
template<int X> constexpr int NTT<X>::rt;

//INSERT ABOVE HERE
signed main(){
  int n,k;
  cin>>n>>k;
  vector<int> hs(n);
  for(int i=0;i<n;i++) cin>>hs[i];

  int cnt=0;
  for(int i=0;i<n;i++)
    if(hs[i]==hs[(i+1)%n]) cnt++;

  if(cnt==n){
    cout<<0<<endl;
    return 0;
  }

  NTT<2> ntt;
  using M = decltype(ntt)::M;
  vector<M> as(1<<19,M(0));
  as[0]=M(1);
  as[1]=M(k-2LL);
  as[2]=M(1);

  ntt.ntt(as,0);
  for(auto &a:as) a=a.pow(n-cnt);
  ntt.ntt(as,1);

  M ans{0};
  for(int i=n-cnt+1;i<(int)as.size();i++) ans+=as[i];

  ans*=M(k+0LL).pow(cnt);
  cout<<ans<<endl;
  return 0;
}