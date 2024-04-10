#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX_V 1000050
vector<int> G[MAX_V];
int root=0,sum;
int t[MAX_V];
int s[MAX_V];
int dfs(int v,int p=-1){
  int res=t[v];
  for(int u:G[v]) if(u!=p) res+=dfs(u,v);
  //cout<<v<<" "<<res<<endl;
  return s[v]=res;
}
int dfs2(int v,int p=-1){
  int an[2],i=0;
  for(int u:G[v]){
    if(u!=p){
      int k=dfs2(u,v);
      if(~k) an[i++]=k;
      if(i>1) break;
    }
  }
  if(i>1){
    cout<<an[0]+1<<" "<<an[1]+1<<endl;
    assert(s[an[0]]*3==sum);
    assert(s[an[1]]*3==sum);
    exit(0);
  }
  if(i&&v!=root){
    if(s[v]*3==sum*2){
      an[1]=v;
      cout<<an[0]+1<<" "<<an[1]+1<<endl;
      assert(s[an[0]]*3==sum);
      assert(s[an[1]]*3==sum*2);
      exit(0);
    }
    return an[0];
  }
  bool f=s[v]*3==sum;
  //cout<<v<<" "<<i<<" "<<(f?v:-1)<<endl;
  return f?v:-1;
}
signed main(){
  int n;
  scanf("%lld",&n);
  for(int i=0;i<n;i++){
    int a;
    scanf("%lld %lld",&a,t+i);
    a--;
    if(~a){
      G[i].push_back(a);
      G[a].push_back(i);
    }else root=i;
  }
  dfs(root);
  sum=s[root];
  dfs2(root);
  //time_t start=clock();
  //while((double)(clock()-start)/CLOCKS_PER_SEC<1.0);
  cout<<-1<<endl;
  return 0;
}