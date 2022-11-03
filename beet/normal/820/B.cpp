#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,a;
  cin>>n>>a;
  int x=-1,dif=1LL<<55LL;
  for(int i=2;i<n;i++){
    int d=180*(n-i);
    if(abs(d-a*n)<dif){
      x=i;
      dif=abs(d-a*n);
    }
  }
  cout<<1<<" "<<2<<" "<<x+1<<endl;
  return 0;
}