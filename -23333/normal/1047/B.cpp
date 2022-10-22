#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  int ans=0; 
  for(int i=1;i<=n;i++)
  {
    int x,y;
    cin>>x>>y;
    ans=max(ans,x+y);
  }
  cout<<ans<<endl;
}