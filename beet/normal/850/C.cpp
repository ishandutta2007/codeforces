#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> dp;
int dfs(int b){
  if(b==0) return 0;
  if(dp.count(b)) return dp[b];
  set<int> s;
  for(int i=1;i<32;i++){
    int mk=(1<<(i-1))-1;
    int nb=b&mk;
    nb|=(b>>i);
    if(nb==b) continue;
    s.insert(dfs(nb));
  }
  int res=0;
  while(s.count(res)) res++;
  return dp[b]=res;
}
signed main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  map<int,int> m;
  for(int i=0;i<n;i++){
    int t=a[i];
    for(int j=2;j<100000;j++){
      if(t%j) continue;
      int k=-1;
      while(t%j==0) t/=j,k++;
      m[j]|=(1LL<<k);
    }
    if(t!=1) m[t]|=1;
  }
  int grundy=0;
  for(auto p:m){
    grundy^=dfs(p.second);
    //cout<<p.first<<" "<<p.second<<endl;
  }
  cout<<(grundy?"Mojtaba":"Arpa")<<endl;
  return 0;
}