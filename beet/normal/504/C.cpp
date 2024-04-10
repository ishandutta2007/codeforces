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

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n;
  cin>>n;
  auto as=read(n);
  {
    auto rs(as);
    reverse(rs.begin(),rs.end());
    if(as==rs) drop(n*(n+1)/2);
  }

  Int is_even=(n%2==0);
  if(is_even) as.emplace(as.begin()+n/2,0);

  // check if exists
  {
    map<Int, Int> cnt;
    for(Int a:as) cnt[a]++;
    Int num=0;
    for(auto[_,v]:cnt)
      if(v&1) num++;
    if(num!=1) drop(0);
  }

  Int m=as.size();
  assert(m&1);
  Int c=m/2;

  Int ans=0;

  auto calc1=[&](auto vs){
    assert((Int)vs.size()==m);
    Int l=0,r=c-1;
    while(vs[l]==vs[m-1-l]) l++;
    while(vs[r]==vs[m-1-r]) r--;
    assert(l<r);
    return (l+1)*(c-r);
  };

  map<Int, Int> cnt;
  for(Int a:as) cnt[a]++;

  if(cnt[as[c]]&1){
    map<Int, Int> num;
    for(Int i=0;i<c;i++) num[as[i]]++;
    Int valid=1;
    for(Int i=0;i<c;i++)
      if(num[as[i]]*2>cnt[as[i]])
        valid=false;

    if(valid){
      for(Int t=0;t<2;t++){
        auto bs(as);
        if(t) reverse(bs.begin(),bs.end());
        ans+=calc1(bs);
      }
    }
  }
  // cout<<ans<<endl;

  Int r_lim=as.size();
  {
    map<Int, Int> num;
    while(1){
      Int v=as[r_lim-1];
      num[v]++;
      if(num[v]*2<=cnt[v]) r_lim--;
      else break;
    }
  }

  Int len=0;
  while(as[len]==as[m-1-len]) len++;

  // cout<<r_lim<<' '<<len<<endl;
  auto calc2=[&](Int i){
    Int m=as.size();
    Int c=m/2;
    auto check=[&](Int x){
      if(x<r_lim-1) return false;
      if(min(i,m-1-x)>len) return false;
      return true;
    };

    Int l=c-1+is_even,r=m;
    // check(l) = false
    // check(r) = true
    while(l+1<r){
      Int mid=(l+r)>>1;
      if(check(mid)) r=mid;
      else l=mid;
    }
    // cout<<i<<':'<<r<<endl;
    return m-r;
  };

  map<Int, Int> num;
  for(Int i=0;i<(n+1)/2;i++){
    ans+=calc2(i);
    num[as[i]]++;
    if(num[as[i]]*2>cnt[as[i]]) break;
  }
  cout<<ans<<newl;
  return 0;
}