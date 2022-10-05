#include <iostream>

using namespace std;

long long k,n,p,s;

int main()
{
cin>>k>>n>>s>>p;
long long l=0;
while (l*s<n)
  l++;
k*=l;

long long ans=0;
while (ans*p<k)
  ans++;

cout<<ans;






    return 0;
}