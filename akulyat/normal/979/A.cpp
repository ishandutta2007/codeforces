#include <iostream>

using namespace std;

int main()
{
long long n;
cin>>n;

if (n==0)
  {
  cout<<0;
  return 0;
  }
n++;
if (n%2==0)
  n/=2;
cout<<n;


    return 0;
}