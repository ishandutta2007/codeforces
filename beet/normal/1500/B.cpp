#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

// find (x, y) s.t. ax + by = gcd(a, b)
// |x| <= b, |y| <= a
// return gcd(a, b)
template<typename T>
T extgcd(T a,T b,T& x,T& y){
  T d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}

//INSERT ABOVE HERE
const Int MAX = 1e6+10;
Int ps[MAX],qs[MAX];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n,m,k;
  cin>>n>>m>>k;
  auto as=read(n);
  auto bs=read(m);

  memset(ps,-1,sizeof(ps));
  memset(qs,-1,sizeof(qs));

  for(Int i=0;i<n;i++) ps[as[i]]=i;
  for(Int j=0;j<m;j++) qs[bs[j]]=j;

  // drop(k);

  Int x,y;
  Int g=extgcd(n,m,x,y);
  y*=-1;

  Int d=n*m/g;

  //using T = tuple<Int, Int, Int, Int>;
  //vector<T> vt;
  using P = pair<Int, Int>;
  vector<P> vp;
  for(Int v=0;v<MAX;v++){
    if(ps[v]<0 or qs[v]<0) continue;
    Int i=ps[v],j=qs[v];
    if(abs(j-i)%g) continue;

    if(i==j){
      Int k=0,l=0;
      assert(k>=0 and l>=0);
      assert(0<=k*n+i);
      assert(k*n+i==l*m+j);
      vp.emplace_back(i,k);
      continue;
    }

    Int k=x*(j-i)/g;
    Int l=y*(j-i)/g;

    if(k<0){
      Int t=(-k+(m/g)-1)/(m/g);
      k+=t*(m/g);
      l+=t*(n/g);
    }
    if(l<0){
      Int t=(-l+(n/g)-1)/(n/g);
      k+=t*(m/g);
      l+=t*(n/g);
    }
    assert(k>=0 and l>=0);
    assert(0<=k*n+i);
    assert(k*n+i==l*m+j);

    // cerr<<i<<' '<<j<<':'<<k<<' '<<l<<':'<<k*n+i<<endl;

    // vt.emplace_back(i,j,k,l);
    vp.emplace_back(i,k);
  }

  // whether k or more in [0, lim)
  auto check=[&](Int lim){
    Int res=0;
    for(auto[i,k]:vp){
      Int s=(k*n+i)%d;
      // s + d t < lim
      // -> s + d t <= lim - 1
      if(s>=lim) continue;
      assert(s<d);
      Int t=(lim-1-s)/d;
      res+=t+1; // [0, t]
      // cerr<<s<<' '<<lim<<' '<<d<<' '<<t<<endl;
    }
    // cerr<<lim<<' '<<res<<':'<<lim-res<<':'<<k<<endl;
    return (lim-res)>=k;
  };

  Int L=0,R=2e18;
  // check(L) = false
  // check(R) = true
  while(L+1<R){
    Int M=(L+R)>>1;
    if(check(M)) R=M;
    else L=M;
  }
  cout<<R<<newl;
  return 0;
}