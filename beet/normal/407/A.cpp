#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int a,b;
  cin>>a>>b;
  if(a<b) swap(a,b);
  Int c=__gcd(a,b);
  vector<int> s,t,u,v;
  
  Int r=0;
  for(Int i=1;i<1001;i++){
    for(Int j=1;j<1001;j++){
      if(i*i+j*j==a*a) s.emplace_back(i),t.emplace_back(j);
      if(i*i+j*j==b*b) u.emplace_back(i),v.emplace_back(j);
    }
  }
  if(s.empty()||u.empty()){
    cout<<"NO"<<endl;
    return 0;
  }
  
  
  for(Int i=0;i<(int)s.size();i++){
    for(Int j=0;j<(int)u.size();j++){
      if(t[i]!=v[j]){
	//cout<<-s*u+t*v<<endl;
	if(-s[i]*u[j]+t[i]*v[j]==0){
	  //assert(r);
	  cout<<"YES"<<endl;
	  cout<<0<<" "<<0<<endl;
	  cout<<-s[i]<<" "<<t[i]<<endl;
	  cout<<u[j]<<" "<<v[j]<<endl;
	  return 0;
	}
      }
    }
  }
  assert(!r);
  cout<<"NO"<<endl;
  return 0;
}