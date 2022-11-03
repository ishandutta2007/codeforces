#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> m[100];
int ans=0;
void dfs(int d,int x,int y,int z,int n,int k){
  if(z==0){
    if(k-d==0||(x+y<n-1&&k-d==1)) ans++;
    return;
  }
  //cout<<d<<" "<<x<<" "<<y<<" "<<z<<" "<<n<<" "<<k<<endl;
  if(x+y==n){
    ans+=m[z-1][k-d];
    ans+=m[z-1][k-d-1];
    return;
  }else if(n<=x+y/2){
    dfs(d,x,y/2,z-1,n,k);
  }else{
    ans+=m[z-1][k-d];
    dfs(d+1,x+y/2,y/2,z-1,n,k);
  }
}
signed main(){
  int n,t;
  cin>>n>>t;
  if(__builtin_popcountll(t)!=1){
    cout<<0<<endl;
    return 0;
  }
  int k=0;
  while(t>1) t>>=1,k++;
  //cout<<k<<endl;
  m[0][0]=1;m[0][1]=1;
  for(int i=0;i<99;i++){
    for(auto p:m[i]){
      m[i+1][p.first]+=p.second;
      m[i+1][p.first+1]+=p.second;
    }
  }
  int x=0,y=2,z=0;
  while(x+y<n){
    ans+=m[z][k];
    x=x+y;
    y*=2;
    z++;
  }
  dfs(0,x,y,z,n,k);
  cout<<ans<<endl;
  return 0;
}