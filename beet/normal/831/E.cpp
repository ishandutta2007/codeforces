#include<bits/stdc++.h>
using namespace std;
#define int long long
set<int> s[114514];

struct BIT{
  vector<int> bit;
  int n;
  //1-indexed
  BIT(){init(-1);}
  BIT(int n_){init(n_);}
  void init(int n_){
    n=n_;
    bit.clear();
    bit.resize(n+1,0);
  }
  int sum(int i){
    int s=0;
    while(i>0){
      s+=bit[i];
      i-=i&-i;
    }
    return s;
  }
  void add(int i,int x){
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }
  int sum0(int i){
    return sum(i+1);
  }
  void add0(int i,int x){
    add(i+1,x);
  }
};
signed main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  priority_queue<int,vector<int>,greater<int> > q;
  BIT bit(n*2+1);
  for(int i=0;i<n;i++){
    q.push(a[i]);
    s[a[i]].insert(i);
    s[a[i]].insert(i+n);
    bit.add0(i,1);
    bit.add0(i+n,1);
  }
  int p=0,ans=0;
  while(!q.empty()){
    int x=q.top();q.pop();
    int y=*s[x].lower_bound(p);
    ans+=bit.sum0(y)-bit.sum0(p-1);
    
    if(y>n) y-=n;
    s[x].erase(y);
    s[x].erase(y+n);
    bit.add0(y,-1);
    bit.add0(y+n,-1);
    
    p=y;
  }
  cout<<ans<<endl;
  return 0;
}