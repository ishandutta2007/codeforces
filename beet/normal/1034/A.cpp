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

//INSERT ABOVE HERE
const int MAX = 1.5e7+10;
int dp[MAX]={};
int cnt[MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  for(int i=2;i<MAX;i++){
    if(dp[i]) continue;
    for(int j=i;j<MAX;j+=i) dp[j]=i;
  }

  int n;
  cin>>n;
  auto as=read(n);

  int g=as[0];
  for(int a:as) g=gcd(g,a);

  if(as==vector<int>(n,g)) drop(-1);

  for(int &a:as) a/=g;
  for(int a:as){
    while(a!=1){
      int k=dp[a];
      cnt[k]++;
      while(a%k==0) a/=k;
    }
  }

  int ans=*max_element(cnt+2,cnt+MAX);
  cout<<n-ans<<newl;
  return 0;
}