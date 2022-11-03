#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct UnionFind{
  int n;
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int sz):n(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
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

//INSERT ABOVE HERE
signed main(){
  int n,m;
  cin>>n>>m;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin>>s[i];
  UnionFind uf(n+m);
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(s[i][j]=='#') uf.unite(i,n+j);

  auto check=[&](int x){
    if(x){
      cout<<"No"<<endl;
      exit(0);
    }
  };

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      check((s[i][j]=='#')^uf.same(i,n+j));
  
  cout<<"Yes"<<endl;
  return 0;
}