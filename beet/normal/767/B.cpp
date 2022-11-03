#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll ts,tf,t,n;
  cin>>ts>>tf>>t>>n;
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
  set<ll> s;
  for(ll i=0;i<n;i++) s.insert(a[i]);

  
  if(!n||ts<a[0]){
    cout<<ts<<endl;
    return 0;
  }
  
  ll ans=a[0]-1,len=ts-a[0]+1;
  queue<int> q;
  ll i=0,c=ts;
  while(c<tf&&i<n){
    while(i<n&&a[i]<=c){
      if(i==0||a[i-1]!=a[i]){
	if(!s.count(a[i]-1)){
	  if((int)q.size()*t+c+t<=tf){
	    if((int)q.size()*t+c-(a[i]-1)<len){
	      len=q.size()*t+c-(a[i]-1);
	      ans=a[i]-1;
	    }
	  }
	}
      }
      
      q.push(i);
      if(i+1>=n||a[i]!=a[i+1]){
	if((int)q.size()*t+c+t<=tf){
	  if((int)q.size()*t+c-a[i]<len){
	    len=q.size()*t+c-a[i];
	    ans=a[i];
	  }
	}
      }
      
      i++;
    }
    if(q.empty()&&c+t<=tf){
      cout<<c<<endl;
      return 0;
    }
    while(!q.empty()){
      q.pop();
      c+=t;
    }
  }
  if(i==n&&c+t<=tf){
    cout<<c<<endl;
    return 0;
  }
  /*
  if(len==ts-a[0]+1){
    time_t start=clock();
    while((double)(clock()-start)/CLOCKS_PER_SEC<1.0);
  }
  */
  //cout<<len<<endl;
  cout<<ans<<endl;
  return 0;
}