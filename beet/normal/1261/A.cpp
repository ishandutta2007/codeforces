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

//INSERT ABOVE HERE
signed solve(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  k--;
  int op=n/2-k;
  string t=string(op,'(')+string(op,')');
  for(int i=0;i<k;i++) t+="()";
  //cout<<t<<endl;

  using P = pair<int, int>;
  vector<P> ans;
  auto flip=
    [&](int l,int r){ // flip [l, r)
      ans.emplace_back(l+1,r);
      string x=s.substr(0,l);
      string y=s.substr(l,r-l);
      string z=s.substr(r);
      reverse(y.begin(),y.end());
      s=x+y+z;
    };

  for(int i=0;i<n;i++){
    if(s[i]==t[i]) continue;
    for(int j=i+1;j<n;j++){
      if(t[i]==s[j]){
        flip(i,j+1);
        break;
      }
    }
  }

  assert(s==t);
  cout<<ans.size()<<endl;
  for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
  return 0;
}

signed main(){
  int T;
  cin>>T;
  while(T--) solve();
  return 0;
}