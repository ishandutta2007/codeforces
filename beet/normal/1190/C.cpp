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


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  Int n,k;
  cin>>n>>k;
  string s;
  cin>>s;

  vector<Int> sm(n+1,0);
  for(Int i=0;i<n;i++) sm[i+1]=sm[i]+(s[i]-'0');
  for(Int i=0;i+k<=n;i++){
    Int l=i,r=i+k;
    Int num=sm[n]-(sm[r]-sm[l]);
    if((num==0)||(num+k==n)) drop("tokitsukaze");
  }

  vector<Int> zs,os;
  for(Int i=0;i<n;i++){
    if(s[i]=='0') zs.emplace_back(i);
    else os.emplace_back(i);
  }
  assert(!zs.empty());
  assert(!os.empty());

  for(Int i=0;i+k<=n;i++){
    Int l=i,r=i+k;
    for(Int uku=0;uku<2;uku++){
      const auto &vs=(uku==0?zs:os);
      Int lose=0;
      {
        auto latte=lower_bound(vs.begin(),vs.end(),r);
        if(latte==vs.end()){
          auto malta=lower_bound(vs.begin(),vs.end(),l);
          assert(malta!=vs.begin());
          --malta;
          if(*malta-vs.front()+1<=k) lose=1;
        }
      }
      {
        auto latte=lower_bound(vs.begin(),vs.end(),l);
        if(latte==vs.begin()){
          auto malta=lower_bound(vs.begin(),vs.end(),r);
          assert(malta!=vs.end());
          if(vs.back()-*malta+1<=k) lose=1;
        }
      }
      if(!lose) drop("once again");
    }
  }

  drop("quailty");
  return 0;
}