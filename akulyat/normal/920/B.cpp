#include <iostream>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long t,u,n,i,time=1;
long ans[20000];
cin>>t;
for (u=0; u<t; u++)
  {
  cin>>n;
  time=1;
  for (i=0; i<n; i++)
    {
    long a,b;
    cin>>a>>b;
    if (time<=b)
      {
      ans[i]=max(time, a);
      time=ans[i]+1;
      } else
      ans[i]=0;
    }
  for (i=0; i<n; i++)
    cout<<ans[i]<<' ';
  cout<<endl;
  }
   return 0;
}