#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin>>n;
  int v[2][10]={};
  memset(v[0],-1,sizeof(v[0]));
  while(n--){
    char c;
    int x;
    cin>>c>>x;
    for(int i=0;i<10;i++){
      if(c=='&'){
	if(((x>>i)&1)==0){
	  v[0][i]=0;
	  v[1][i]=0;
	}
      }
      if(c=='|'){
	if(((x>>i)&1)==1){
	  v[0][i]=1;
	  v[1][i]=0;
	}
      }
      if(c=='^'){
	if(((x>>i)&1)==1){
	  if(~v[0][i]) v[0][i]=!v[0][i];
	  else v[1][i]=!v[1][i];
	}
      }
    }
  }

  //for(int i=0;i<10;i++) cout<<i<<":"<<v[0][i]<<" "<<v[1][i]<<endl;
  
  cout<<3<<endl;
  {
    int x=(1<<10)-1;
    for(int i=0;i<10;i++)
      if(v[0][i]==0) x^=(1<<i);
    cout<<"& "<<x<<endl;
  }
  {
    int x=0;
    for(int i=0;i<10;i++)
      if(v[0][i]==1) x^=(1<<i);
    cout<<"| "<<x<<endl;
  }
  {
    int x=0;
    for(int i=0;i<10;i++)
      if(v[1][i]==1) x^=(1<<i);
    cout<<"^ "<<x<<endl;
  }

  
  return 0;
}