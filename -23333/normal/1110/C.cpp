#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
int js(int x)
{
  int cnt=0;
  while (x)
  {
    cnt++; x/=2;
  }
  return cnt;
}
int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  rep(i,1,n)
  {
    int x;
    cin>>x;
    int y=js(x);
    int zz=(1<<y)-1;
    if (zz==x)
    {
      int k=sqrt(x);
      int tt=0;
      rep(j,2,k)
      {
        if(x%j==0)
        {
          cout<<x/j<<endl;
          tt=1;
          break;
        }
      } 
      if (!tt) cout<<1<<endl;
    } else
    {
      cout<<((1<<y)-1)<<endl;
    }
  }
  return 0; 
}