#include<bits/stdc++.h>
using namespace std;
using Int = long long;
bool isprime(int x){
  for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
  return 1;
}
const int MAX=500;
signed main(){
  //for(int i=2;i<100;i++) if(!isprime(i)) cout<<i<<endl;
  int dp[MAX],used[MAX];
  memset(used,0,sizeof(used));
  function<int(int)> dfs=[&](int x){
    //cout<<x<<" "<<dp[x]<<endl;
    if(x==0) return 0;
    if(used[x]) return dp[x];
    used[x]=1;
    int res=-1;
    for(int i=2;i<=x;i++){
      if(!isprime(i)&&dfs(x-i)>=0){
	res=max(res,dfs(x-i)+1);
      }
    }
    //cout<<x<<" "<<res<<endl;
    return dp[x]=res;
  };
  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    if(n<MAX) cout<<dfs(n)<<endl;
    else cout<<(n/4)-(n&1)<<endl;
  }
  return 0;
}