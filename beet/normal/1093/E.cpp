#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T>
struct RangeCount{
  struct BIT{
    vector<T> dat;
    BIT(){}
    BIT(int n){dat.assign(++n,0);}
    T sum(int k){
      T res=0;
      for(;k;k-=k&-k) res+=dat[k];
      return res;
    }
    void add(int k,T v){
      for(++k;k<(int)dat.size();k+=k&-k) dat[k]+=v;
    }    
  };
  int n;
  vector<vector<int> > val;
  vector<BIT> dat;
  RangeCount(){}
  RangeCount(int n_){
    n=1;
    while(n<n_) n<<=1;
    val.assign(n<<1,vector<int>());
    dat.reserve(n<<1);    
  }
  void preupdate(int a,int x){
    a+=n;
    while(a){
      val[a].emplace_back(x);
      a>>=1;
    }
  }
  void build(){    
    for(int i=0;i<n*2;i++){
      auto &v=val[i];
      sort(v.begin(),v.end());
      v.erase(unique(v.begin(),v.end()),v.end());
      dat.emplace_back(v.size());
    }
  }
  void update(int a,int x,int z){
    a+=n;
    while(a){
      auto &v=val[a];
      int k=lower_bound(v.begin(),v.end(),x)-v.begin();
      dat[a].add(k,z);
      a>>=1;
    }    
  }
  T calc(int k,int x,int y){
    auto &v=val[k];
    int p=lower_bound(v.begin(),v.end(),x)-v.begin();
    int q=lower_bound(v.begin(),v.end(),y)-v.begin();
    return dat[k].sum(q)-dat[k].sum(p);
  }
  // [a, b) * [x, y)
  T query(int a,int b,int x,int y){
    T res=0;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
      if(l&1) res+=calc(l++,x,y);
      if(r&1) res+=calc(--r,x,y); 
    }
    return res;
  }
};


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin>>a[i],a[i]--;
  for(int i=0;i<n;i++) cin>>b[i],b[i]--;
    
  vector<int> t(m),la(m),ra(m),lb(m),rb(m),x(m),y(m);
  for(int i=0;i<m;i++){
    cin>>t[i];
    if(t[i]==1){
      cin>>la[i]>>ra[i]>>lb[i]>>rb[i];
      la[i]--;lb[i]--;
    }
    if(t[i]==2){
      cin>>x[i]>>y[i];
      x[i]--;y[i]--;
    }
  }

  vector<int> rev(n);
  for(int i=0;i<n;i++) rev[a[i]]=i;
  vector<int> c(n);
  for(int i=0;i<n;i++) c[i]=rev[b[i]];
  
  RangeCount<int> seg(n+10);
  for(int i=0;i<n;i++) seg.preupdate(i,c[i]);
  for(int i=0;i<m;i++){
    if(t[i]==2){
      swap(c[x[i]],c[y[i]]);
      seg.preupdate(x[i],c[x[i]]);
      seg.preupdate(y[i],c[y[i]]);
    }
  }

  seg.build();
  for(int i=0;i<n;i++) c[i]=rev[b[i]];
  for(int i=0;i<n;i++) seg.update(i,c[i],1);
  
  for(int i=0;i<m;i++){
    if(t[i]==1){
      int ans=seg.query(lb[i],rb[i],la[i],ra[i]);
      cout<<ans<<"\n";
    }
    if(t[i]==2){      
      seg.update(x[i],c[x[i]],-1);
      seg.update(y[i],c[y[i]],-1);
      swap(c[x[i]],c[y[i]]);
      seg.update(x[i],c[x[i]],1);
      seg.update(y[i],c[y[i]],1);
    }
  }
  cout<<flush;
  return 0;
}