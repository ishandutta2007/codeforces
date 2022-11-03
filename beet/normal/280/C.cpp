#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> G[114514];
double dfs(int v,int d,int p){
  double res=1.0/d;
  for(int u:G[v])
    if(u!=p) res+=dfs(u,d+1,v);
  return res;
}
signed main(){
  int n;
  cin>>n;
  int a[n-1],b[n-1];
  for(int i=0;i<n-1;i++) cin>>a[i]>>b[i];
  for(int i=0;i<n-1;i++){
    a[i]--;b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  printf("%.12f\n",dfs(0,1,-1));
  return 0;
}