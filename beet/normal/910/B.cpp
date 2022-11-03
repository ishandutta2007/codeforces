#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  int n,a,b;
  cin>>n>>a>>b;
  vector<int> v({a,a,a,a,b,b});
  sort(v.begin(),v.end());
  int ans=6;
  do{
    int res=0;
    for(int i=0;i<6;i++){
      res++;
      int x=n-v[i];
      while(i+1<6&&x>=v[i+1]){
	i++;
	x-=v[i];
      }
    }
    ans=min(ans,res);
  }while(next_permutation(v.begin(),v.end()));
  cout<<ans<<endl;
  return 0;
}