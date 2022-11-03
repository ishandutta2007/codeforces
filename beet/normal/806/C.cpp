#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}


template<typename V>
V compress(V vs){
  sort(vs.begin(),vs.end());
  vs.erase(unique(vs.begin(),vs.end()),vs.end());
  return vs;
}
template<typename T>
map<T, Int> dict(const vector<T> &vs){
  map<T, Int> res;
  for(Int i=0;i<(Int)vs.size();i++)
    res[vs[i]]=i;
  return res;
}
map<char, Int> dict(const string &s){
  return dict(vector<char>(s.begin(),s.end()));
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n;
  cin>>n;
  auto as=read(n);

  vector<Int> ps,qs;
  for(Int a:as){
    if(__builtin_popcountll(a)==1) ps.emplace_back(a);
    else qs.emplace_back(a);
  }

  const Int LOG = 50;
  vector<Int> vs;
  for(Int i=0;i<LOG;i++)
    vs.emplace_back(1LL<<i);

  // x == vs[idx(x)] if x is power of two
  // x <  vs[idx(x)] otherwise
  auto idx=[&](Int x){return lower_bound(vs.begin(),vs.end(),x)-vs.begin();};

  vector<Int> cnt(LOG,0);
  for(Int p:ps) cnt[idx(p)]++;

  vector<Int> num(LOG,0);
  for(Int q:qs) num[idx(q)-1]++;

  for(Int i=0;i+1<LOG;i++){
    while(cnt[i]<cnt[i+1]){
      num[i]++;
      cnt[i+1]--;
    }
  }

  vector<Int> ans;
  while(cnt[0]){

    Int res=0;
    for(Int i=LOG-2;i>=0;i--){
      res+=cnt[i]-cnt[i+1];
      res-=num[i];
      if(res<0) break;
    }

    const Int DEBUG = 0;
    if(DEBUG){
      cout<<cnt[0]<<':'<<res<<newl;
      for(Int i=5;i>=0;i--)
        cout<<cnt[i]<<' '<<num[i]<<endl;
      cout<<endl;
    }

    if(res>=0) ans.emplace_back(cnt[0]);

    for(Int i=0;i+1<LOG;i++){
      if(cnt[i]>cnt[i+1]){
        num[i>0?i-1:i]++;
        cnt[i]--;
        break;
      }
    }
  }

  ans=compress(ans);
  if(ans.empty()) drop(-1);
  for(Int i=0;i<(Int)ans.size();i++){
    if(i) cout<<' ';
    cout<<ans[i];
  }
  cout<<newl;
  return 0;
}