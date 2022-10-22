#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
int main()
{
  int a,b,c,a1,b1,c1;
  cin>>a>>b>>c>>a1>>b1>>c1;
  if (a1>=a&&a1+b1>=a+b&&a1+b1+c1>=a+b+c) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0; 
}