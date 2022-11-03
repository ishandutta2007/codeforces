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


template<typename T>
struct BIT{
  int n;
  vector<T> bit;
  // 1-indexed
  BIT(int n_):n(n_+1),bit(n+1,0){}

  T sum(int i){
    T s(0);
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }

  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }

  // [l, r)
  T query(int l,int r){
    return sum(r-1)-sum(l-1);
  }

  int lower_bound(int w){
    if(w<=0) return 0;
    int x=0,r=1;
    while(r<n) r<<=1;
    for(int k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;
  }

  // 0-indexed
  T sum0(int i){return sum(i+1);}
  void add0(int i,T a){add(i+1,a);}
  T query0(int l,int r){return sum(r)-sum(l);}
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto as=read(n);

  BIT<int> bit(n+1);
  int inv=0;
  for(int a:as){
    inv+=bit.query(a+1,n+1)%2;
    inv%=2;
    bit.add(a,1);
  }

  if((n&1)^(inv&1)) cout<<"Um_nik"<<newl;
  else cout<<"Petr"<<newl;
  return 0;
}