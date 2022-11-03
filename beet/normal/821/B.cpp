#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int m,b;
  cin>>m>>b;
  int ans=0;
  for(int i=0;i<=b;i++){
    int x=m*(b-i);
    int tmp=0;
    for(int j=0;j<=i;j++){
      tmp+=j*(x+1);
      tmp+=x*(x+1)/2;
    }
    ans=max(ans,tmp);
  }
  cout<<(int)ans<<endl;
  return 0;
}