#include<bits/stdc++.h>
using namespace std;
struct UnionFind{
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int size){init(size);}
  void init(int size){
    r.resize(size,0);
    p.resize(size,0);
    for(int i=0;i<size;i++) r[i]=1,p[i]=i;
  }
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }
};
int main(){
  int n;
  cin>>n;
  UnionFind u(n);
  for(int i=0;i<n;i++){
    int p;
    cin>>p;
    u.unite(i,p-1);
  }
  int ans=0;
  for(int i=0;i<n;i++) ans+=u.find(i)==i;
  cout<<ans<<endl;
  return 0;
}