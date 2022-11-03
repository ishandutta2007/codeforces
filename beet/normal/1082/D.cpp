#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  Int sum=0;
  vector<Int> vs,ws;
  for(Int i=0;i<n;i++){
    sum+=a[i];
    if(a[i]>=2) vs.emplace_back(i);
    else ws.emplace_back(i);
  }
  if(sum<2*(n-1)){
    cout<<"NO"<<endl;
    return 0;    
  }
  
  if((Int)ws.size()<=2){
    cout<<"YES "<<n-1<<"\n";
    cout<<n-1<<"\n";
    if(!ws.empty()){
      cout<<ws.back()+1<<" "<<vs[0]+1<<"\n";
      ws.pop_back();
    }
    
    for(Int i=0;i+1<(Int)vs.size();i++)
      cout<<vs[i]+1<<" "<<vs[i+1]+1<<"\n";
    
    if(!ws.empty()){
      cout<<ws.back()+1<<" "<<vs.back()+1<<"\n";
      ws.pop_back();
    }
    cout<<flush;
    return 0;
  }
  
  cout<<"YES "<<vs.size()+1<<"\n";
  cout<<n-1<<"\n";
  
  if(!ws.empty()){
    cout<<ws.back()+1<<" "<<vs[0]+1<<"\n";
    a[vs[0]]--;
    ws.pop_back();
  }
  for(Int i=0;i+1<(Int)vs.size();i++){
    cout<<vs[i]+1<<" "<<vs[i+1]+1<<"\n";
    a[vs[i]]--;
    a[vs[i+1]]--;
  }
  if(!ws.empty()){
    cout<<ws.back()+1<<" "<<vs.back()+1<<"\n";
    a[vs.back()]--;
    ws.pop_back();
  }
  
  queue<Int> q;
  for(Int x:vs) if(a[x]>0) q.emplace(x);
  while(!ws.empty()){
    Int x=q.front();q.pop();
    Int y=ws.back();ws.pop_back();
    cout<<x+1<<" "<<y+1<<"\n";
    a[x]--;
    if(a[x]>0) q.emplace(x);
  }  
  cout<<flush;  
  return 0;
}