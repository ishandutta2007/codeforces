#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
vector<int> G[114514];
int v[114514];
P dfs(int u,int p=-1){
  P res=P(0,0);
  for(int i:G[u]){
    if(i==p) continue;
    P p=dfs(i,u);
    res.first =max(res.first ,p.first);
    res.second=max(res.second,p.second);
  }
  int tmp=res.first-res.second;
  if(v[u]>tmp) res.first +=v[u]-tmp;
  if(v[u]<tmp) res.second+=tmp-v[u]; 
  return res;
}
signed main(){
  int n;
  cin>>n;
  int a[n],b[n];
  for(int i=0;i<n-1;i++) cin>>a[i]>>b[i];
  for(int i=0;i<n;i++) cin>>v[i];
  for(int i=0;i<n-1;i++){
    a[i]--;b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  P p=dfs(0);
  cout<<p.first+p.second<<endl;
  return 0;
}