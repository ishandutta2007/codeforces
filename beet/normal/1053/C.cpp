#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T> 
struct BIT{
  Int n;
  vector<T> bit;
  //1-indexed
  BIT():n(-1){}
  BIT(Int n_,T d):n(n_),bit(n_+1,d){}
  
  T sum(Int i){
    T s=bit[0];
    for(Int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }
  void add(Int i,T a){
    if(i==0) return;
    for(Int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }
  
  Int lower_bound(Int w){
    if(w<=0) return 0;
    Int x=0,r=1;
    while(r<n) r<<=1;
    for(Int k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
	w-=bit[x+k];
	x+=k;
      }
    }
    return x+1;
  }
  
  T sum0(Int i){
    return sum(i+1);
  }
  void add0(Int i,T a){
    add(i+1,a);
  }

  T query(Int l,Int r){
    return sum(r-1)-sum(l-1);
  }

  T query0(Int l,Int r){
    return sum(r)-sum(l);
  }
};


template<int MOD = 1000000007>
struct Mint{
  int v;
  Mint():v(0){}
  Mint(int v):v(v){}
  Mint(long long t){v=t%MOD;}

  Mint pow(int k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }
  
  Mint inv(){return pow(MOD-2);}
  
  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}
  
  Mint operator+(Mint a){return Mint(v)+=a;};
  Mint operator-(Mint a){return Mint(v)-=a;};
  Mint operator*(Mint a){return Mint(v)*=a;};
  Mint operator/(Mint a){return Mint(v)/=a;};

  Mint operator-(){return v?MOD-v:v;}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  
  vector<Mint> fact(int n){
    vector<Mint> res(n+1,1);
    for(int i=1;i<=n;i++) res[i]=res[i-1]*Mint(i);
    return res;
  }
  
  vector<Mint> finv(int n){
    vector<Mint> res(n+1,1);
    for(int i=1;i<=n;i++) res[i]=res[i-1]*Mint(i);
    res[n]=Mint(1)/res[n];
    for(int i=n;i>=1;i--) res[i-1]=res[i]*Mint(i);
    return res;
  }

  vector<Mint> invs(vector<Mint> &a,vector<Mint> &b){
    int n=a.size()-1;
    vector<Mint> res(n+1,0);
    for(int i=1;i<=n;i++) res[i]=b[i]*a[i-1];
    return res;
  }
};

template<int MOD>
istream& operator>>(istream &is, Mint<MOD>& a){
  is>>a.v;
  return is;
} 
template<int MOD>
ostream& operator<<(ostream &os, Mint<MOD>& a){
  os<<a.v;
  return os;
} 

//INSERT ABOVE HERE

signed main(){
  Int n,q;
  scanf("%lld %lld",&n,&q);
  vector<Int> a(n),w(n);
  for(Int i=0;i<n;i++) scanf("%lld",&a[i]);
  for(Int i=0;i<n;i++) scanf("%lld",&w[i]);

  using M = Mint<>;
  vector<M> A(n),W(n);
  BIT<Int> bit1(n+10,0);
  BIT<M>   bit2(n+10,M(0));
  for(Int i=0;i<n;i++){
    a[i]-=i;
    A[i]=M(a[i]);
    W[i]=M(w[i]);
    bit1.add0(i,w[i]);
    bit2.add0(i,A[i]*W[i]);    
  }

  for(Int i=0;i<q;i++){
    Int x,y;
    scanf("%lld %lld",&x,&y);
    if(x<0){
      x=-x-1;
      
      bit1.add0(x,-w[x]);
      bit2.add0(x,-A[x]*W[x]);  

      w[x]=y;
      W[x]=M(w[x]);
      
      bit1.add0(x,w[x]);
      bit2.add0(x,A[x]*W[x]);     
    }else{
      Int l=x-1,r=y;
      
      Int s=bit1.query0(l,r);
      Int t=bit1.query0(0,l);
      Int m=bit1.lower_bound(t+(s+1)/2)-1;
      
      M X=-bit2.query0(l,m)+A[m]*M(bit1.query0(l,m));      
      M Y=-bit2.query0(m,r)+A[m]*M(bit1.query0(m,r));      

      printf("%d\n",(X-Y).v);
    }
  }
  return 0;
}