#include <bits/stdc++.h>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long n,i,maxi=-1000001;
cin>>n;
for (i=0; i<n; i++)
  {
  long b,a;
  cin>>b;
  {
  if (b>=0)
    a=sqrt(b);
  if ((a*a!=b)||(b<0))
    {
    if (b>maxi)
      maxi=b;
    }
  }
  }
cout<<maxi;





    return 0;
}