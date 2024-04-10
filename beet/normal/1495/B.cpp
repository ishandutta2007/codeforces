#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}


template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;

  SegmentTree(F f,T ti):f(f),ti(ti){}

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }

  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  void set_val(int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }

  T query(int a,int b){
    if(a>=b) return ti;
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int max_right(int s,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,dat[k]);
      return check(acc)?-1:k-n;
    }
    int m=(l+r)>>1;
    if(m<=s) return max_right(s,check,acc,(k<<1)|1,m,r);
    if(s<=l and check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=max_right(s,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return max_right(s,check,acc,(k<<1)|1,m,r);
  }

  // max t s.t. check(query(s,t))
  // O(\log N)
  template<typename C>
  int max_right(int s,C &check){
    assert(s<n and check(ti) and not check(query(s,n)));
    T acc=ti;
    return max_right(s,check,acc,1,0,n);
  }
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto ps=read(n);

  vector<int> decL(n,0),decR(n,0);
  vector<int> incL(n,0),incR(n,0);

  for(int i=1;i<n;i++){
    if(ps[i-1]<ps[i]) decL[i]=decL[i-1]+1;
    if(ps[i-1]>ps[i]) incL[i]=incL[i-1]+1;
  }

  for(int i=n-2;i>=0;i--){
    if(ps[i+1]<ps[i]) decR[i]=decR[i+1]+1;
    if(ps[i+1]>ps[i]) incR[i]=incR[i+1]+1;
  }

  auto f=[&](int a,int b){return max(a,b);};
  SegmentTree<int> segL(f,-1),segR(f,-1);
  segL.build(incL);
  segR.build(incR);

  int ans=0;
  for(int i=0;i<n;i++){
    if(decL[i]==0 or decR[i]==0) continue;
    // > p_{i - decL[i]} ... < p_{i-1} < p_i > p_{i+1} > ... > p_{i+decR[i]} <
    int ig=0;
    chmax(ig,segL.query(0,i-decL[i]+1));
    chmax(ig,segR.query(0,i-decL[i]));

    chmax(ig,segR.query(i+decR[i],n));
    chmax(ig,segL.query(i+decR[i]+1,n));

    const int DEBUG = (i == 2) * 0;
    if(DEBUG) cout<<decL[i]<<' '<<decR[i]<<' '<<ig<<endl;

    // Daniel can always move ig turns regardless of Qingshan's first move
    if(max(decL[i],decR[i])<=ig) continue;


    // y x
    {
      int len=decL[i];
      if(len%2==0) len--; // if even length, Qingshan comes to Daniel
      if(decR[i]<=len) continue;
    }
    // x y
    {
      int len=decR[i];
      if(len%2==0) len--;  // if even length, Qingshan comes to Daniel
      if(decL[i]<=len) continue;
    }

    assert(decL[i]==decR[i]);
    assert(decL[i]%2==0);
    ans++;
  }

  cout<<ans<<newl;
  return 0;
}