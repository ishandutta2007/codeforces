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

template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}

template<typename T>
map<T, Int> dict(const vector<T> &v){
  map<T, Int> res;
  for(Int i=0;i<(Int)v.size();i++)
    res[v[i]]=i;
  return res;
}


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

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> xs(n),ys(n);
  for(Int i=0;i<n;i++) cin>>xs[i]>>ys[i];

  vector<Int> vx(xs),vy(ys);
  vx.emplace_back(0);
  vx.emplace_back(2e9);
  vy.emplace_back(0);
  vy.emplace_back(2e9);

  vx=compress(vx);
  vy=compress(vy);

  auto dx=dict(vx);
  auto dy=dict(vy);

  for(Int i=0;i<n;i++){
    xs[i]=dx[xs[i]];
    ys[i]=dy[ys[i]];
  }

  auto calc=[&](Int w){return (w+1)*w/2;};

  vector<vector<Int>> G(vy.size());
  for(Int i=0;i<n;i++)
    G[ys[i]].emplace_back(xs[i]);

  reverse(G.begin(),G.end());

  Int sz=vx.size()+10;
  BIT<Int> bit(sz,0);
  vector<Int> used(vx.size(),0);

  Int ans=0;
  for(auto &vs:G){
    if(vs.empty()) continue;
    sort(vs.begin(),vs.end());

    Int m=vs.size();
    for(Int i=0;i+1<m;i++){
      Int l=vs[i]+1;
      Int r=vs[i+1];
      ans-=calc(bit.query0(l,r));
    }

    {
      Int l=0;
      Int r=vs.front();
      ans-=calc(bit.query0(l,r));
    }

    {
      Int l=vs.back()+1;
      Int r=sz;
      ans-=calc(bit.query0(l,r));
    }

    for(Int i=0;i<m;i++){
      if(used[vs[i]]) continue;
      used[vs[i]]=1;
      bit.add0(vs[i],1);
    }
    //cout<<bit.query0(0,sz)<<endl;
    ans+=calc(bit.query0(0,sz));
  }

  cout<<ans<<endl;
  return 0;
}