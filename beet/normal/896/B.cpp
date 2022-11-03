#include<bits/stdc++.h>
using namespace std;
using Int = long long;
const Int debug=0;
Int ask(){
  Int k;
  cin>>k;
  return k;
}
signed main(){
  Int n,m,c;
  cin>>n>>m>>c;
  vector<Int> v(n,-1);
  for(Int i=0;i<m;i++){
    Int k=ask();
    if(k<=c/2){
      Int x=0;
      while(x<n-1&&v[x]!=-1&&v[x]<=k) x++;
      v[x]=k;
      cout<<x+1<<endl;
    }else{
      Int x=n-1;
      while(x>0&&v[x]!=-1&&v[x]>=k) x--;
      v[x]=k;
      cout<<x+1<<endl;
    }
    if(debug){
      for(Int j:v) cout<<" "<<j;
      cout<<endl;
    }
    if(*min_element(v.begin(),v.end())!=-1){
      bool f=1;
      for(Int j=0;j<n-1;j++)
	f&=v[j]<=v[j+1];
      if(f) exit(0);
    }
  }
  return 0;
}