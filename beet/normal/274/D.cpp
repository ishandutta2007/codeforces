#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 414514
set<int> G[MAX];
int indeg[MAX];
bool V[MAX];
vector<int> p;
void bfs(int s,int m){
  queue<int> q;
  q.push(s);
  V[s]=1;
  while(!q.empty()){
    int u=q.front();q.pop();
    if(u<m) p.push_back(u);
    for(int v:G[u]){
      indeg[v]--;
      if(indeg[v]==0&&!V[v]){
	V[v]=1;
	q.push(v);
      }
    }
  }
}
void tsort(int n,int m){
  memset(V,0,sizeof(V));
  memset(indeg,0,sizeof(indeg));
  for(int u=0;u<n;u++)
    for(int v:G[u])
      indeg[v]++;
  for(int u=0;u<n;u++)
    if(indeg[u]==0&&!V[u]) bfs(u,m);

  if((int)p.size()!=m){
    cout<<-1<<endl;
    return;
  }
  for(int i=0;i<m;i++)
    cout<<p[i]+1<<" \n"[i==n-1];
}
signed main(){
  int n,m;
  cin>>n>>m;
  int a[n][m];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>a[i][j];

  int x=m;
  
  if(m<=500){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	if(a[i][j]<0) continue;
	for(int k=0;k<m;k++){
	  if(j==k||a[i][k]<0) continue;
	  if(a[i][j]<a[i][k]) G[j].insert(k);
	}
      }
    }
  }else{
    for(int i=0;i<n;i++){
      vector<int> v;
      map<int,vector<int> > mv;
      for(int j=0;j<m;j++){
	if(~a[i][j]){
	  mv[a[i][j]].push_back(j);
	  v.push_back(a[i][j]);
	}
      }
      sort(v.begin(),v.end());
      v.erase(unique(v.begin(),v.end()),v.end());
      map<int,int> r;
      for(int j=0;j<(int)v.size();j++) r[v[j]]=j;
      for(int j=0;j<(int)v.size()-1;j++){
	for(int k=0;k<(int)mv[v[j]].size();k++)
	  G[mv[v[j]][k]].insert(x);
	for(int k=0;k<(int)mv[v[j+1]].size();k++)
	  G[x].insert(mv[v[j+1]][k]);
	x++;
      }
    }
  }
  tsort(x,m);
  
  return 0;
}