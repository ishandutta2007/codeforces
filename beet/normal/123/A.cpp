#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct QuickFind{
  int n;
  vector<int> r,p;
  vector<vector<int> > v;
  QuickFind(){}
  QuickFind(int sz):n(sz),r(sz),p(sz),v(sz){
    for(int i=0;i<n;i++){
      r[i]=1,p[i]=i;
      v[i].resize(1,i);
    }
  }
  bool same(int x,int y){
    return p[x]==p[y];
  }
  void unite(int x,int y){
    x=p[x];y=p[y];
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    for(int i=0;i<(int)v[y].size();i++){
      p[v[y][i]]=x;
      v[x].push_back(v[y][i]);
    }
    v[y].clear();
  }
};

signed main(){
  string s;
  cin>>s;
  int n=s.size();
  QuickFind uf(n);
  for(int i=2;i<=n;i++)
    for(int j=i;j<=n;j+=i)
      uf.unite(i-1,j-1);

  using P = pair<int,int>;
  vector<P> v;
  for(int i=0;i<n;i++)
    if(uf.p[i]==i) v.push_back(P(i,uf.r[i]));
 
  //for(auto p:v) cout<<p.first+1<<":"<<p.second<<endl;
  
  vector<int> c(26,0);
  for(int i=0;i<n;i++) c[s[i]-'a']++;

  sort(v.begin(),v.end(),[](P a,P b){return a.second>b.second;});

  
  for(int i=0;i<(int)v.size();i++){
    bool f=1;
    for(int j=0;j<26;j++){
      if(c[j]<v[i].second) continue;
      //cout<<i<<" "<<j<<endl;
      //cout<<c[j]<<":"<<v[i].second<<endl;
      c[j]-=v[i].second;
      f=0;
      for(int x:uf.v[v[i].first]) s[x]=char('a'+j);
      break;
    }
    if(f){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  cout<<s<<endl;
  return 0;
}