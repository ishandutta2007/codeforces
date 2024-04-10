#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  if (n%3==0)
  {
    cout<<1<<" "<<1<<" "<<n-2<<endl;
  }
  if (n%3==1)
  {
    cout<<1<<" "<<2<<" "<<n-3<<endl;
  }
  if (n%3==2)
  {
    cout<<2<<" "<<2<<" "<<n-4<<endl;
  }
}