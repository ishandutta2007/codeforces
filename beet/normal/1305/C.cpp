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


template<typename V>
V compress(V v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}
template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i=0;i<(int)v.size();i++)
    res[v[i]]=i;
  return res;
}
map<char, int> dict(const string &v){
  return dict(vector<char>(v.begin(),v.end()));
}


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  using ll = long long;

  ll n,m;
  cin>>n>>m;

  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  {
    vector<ll> bs(as);
    for(int i=0;i<n;i++) bs[i]%=m;
    auto cs=compress(bs);
    if((int)cs.size()!=n) drop(0);
  }

  ll ans=1;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      ans*=abs(as[i]-as[j])%m;
      ans%=m;
    }
  }

  cout<<ans<<endl;
  return 0;
}