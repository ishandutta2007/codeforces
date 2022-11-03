#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(int y,vector<int>& x){
  int res=0;
  for(int i=0;i<(int)x.size();i++) res+=abs(x[i]-y);
  return res;
}
signed main(){
  int n,m;
  cin>>n>>m;
  vector<int> v(m);
  for(int i=0;i<m;i++) cin>>v[i];
  v.erase(unique(v.begin(),v.end()),v.end());
  int h=v.size();
  int sum=0;
  for(int i=0;i<h-1;i++) sum+=abs(v[i]-v[i+1]);

  if(h==1){
    cout<<0<<endl;
    return 0;
  }
  map<int,vector<int> > mv;
  
  mv[v[0]].push_back(v[1]);
  for(int i=1;i<h-1;i++){
    mv[v[i]].push_back(v[i-1]);
    mv[v[i]].push_back(v[i+1]);
  }
  mv[v[h-1]].push_back(v[h-2]);

  int ans=sum;
  set<int> si;
  for(int i=0;i<h;i++){
    if(si.count(v[i])) continue;
    si.insert(v[i]);
    vector<int> x=mv[v[i]];
    int sub=check(v[i],x);
    int res=sub;
    int l=0,r=n;
    res=min(res,check(l,x));
    res=min(res,check(r,x));
    while(l+2<r){
      int m1=l+(r-l)/3,m2=l+(r-l)*2/3;
      int r1=check(m1,x),r2=check(m2,x);
      res=min(res,r1);
      res=min(res,r2);
      if(r1<r2) r=m2;
      else l=m1;
    }
    ans=min(ans,sum-sub+res);
  }
  
  cout<<ans<<endl;
  return 0;
}