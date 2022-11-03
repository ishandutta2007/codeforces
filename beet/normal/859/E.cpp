#include<bits/stdc++.h>
using namespace std;
using Int = long long;


struct SCC{
  int V;
  vector<vector<int> > G,rG,T,C;
  vector<int> vs,used,cmp;
  SCC(){}
  SCC(int V):V(V){init();}
  void init(){
    for(int i=0;i<(int)G.size();i++) G[i].clear();
    for(int i=0;i<(int)rG.size();i++) rG[i].clear();
    for(int i=0;i<(int)T.size();i++) T[i].clear();
    G.clear();
    rG.clear();
    vs.clear();
    used.clear();
    cmp.clear();
    T.clear();
    
    G.resize(V);
    rG.resize(V);
    used.resize(V);
    cmp.resize(V);
  }
  void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
  }
  void dfs(int v){
    used[v]=1;
    for(int i=0;i<(int)G[v].size();i++){
      if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
  }
  void rdfs(int v,int k){
    used[v]=1;
    cmp[v]=k;
    C[k].push_back(v);
    for(int i=0;i<(int)rG[v].size();i++){
      if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }
  }
  
  int build(){
    fill(used.begin(),used.end(),0);
    vs.clear();
    for(int v=0;v<V;v++){
      if(!used[v]) dfs(v);
    }
    fill(used.begin(),used.end(),0);
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
      if(!used[vs[i]]){
	T.push_back(vector<int>());
	C.push_back(vector<int>());
	rdfs(vs[i],k++);
      }
    }
    for(int i=0;i<V;i++)
      for(int u:rG[i])
	if(cmp[i]!=cmp[u])
	  T[cmp[i]].push_back(cmp[u]);
    for(int i=0;i<k;i++){
      sort(T[i].begin(),T[i].end());
      T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
    }
    return k;
  }
};



#define MOD 1000000007

Int mod_pow(Int x,Int n,Int mod){
  Int res=1;
  while(n>0){
    if(n&1) (res*=x)%=mod;
    (x*=x)%=mod;
    n>>=1;
  }
  return res;
}

Int mod_inverse(Int a,Int m){
  return mod_pow(a,m-2,m);
}

int used[1000001],loop[1000001];

signed main(){
  int n;
  scanf("%d",&n);
  SCC bg(2*n);
  for(int i=0;i<n;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--;B--;
    if(A!=B) bg.add_edge(A,B);
    else loop[A]=1;
  }
  int V=bg.build();
  Int ans=1;
  vector<vector<int> > &T=bg.T,&C=bg.C;
  
  function<Int(int)> dfs=[&](int v){
    assert(C[v].size()==1);
    int res=1;
    for(int u:T[v]) res+=dfs(u);
    return res;
  };

  /*//
    cout<<V<<" "<<T.size()<<endl;
    for(int i=0;i<V;i++){
    cout<<i<<" "<<T[i].size()<<":"<<endl;
    for(int u:T[i]) cout<<u<<" ";cout<<endl;
    }
  //*/

  memset(used,0,sizeof(used));
  for(int i=0;i<V;i++)
    for(int u:T[i])
      used[u]=1;
    
  for(int i=0;i<V;i++){
    if(used[i]) continue;
    if(C[i].size()==1){
      if(!loop[C[i][0]]) ans*=dfs(i);
    }
    else ans*=2LL;
    ans%=MOD;
  }
  printf("%lld\n",ans);
  return 0;
}