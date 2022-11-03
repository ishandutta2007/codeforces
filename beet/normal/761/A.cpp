#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a,b;
  cin>>a>>b;
  if(a==0&&b==0) cout<<"NO"<<endl;
  else cout<<(abs(a-b)<=1?"YES":"NO")<<endl;
  return 0;
}