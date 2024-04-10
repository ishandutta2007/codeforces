#include <iostream>

using namespace std;

long long n,m,k;
int main()
{
cin>>n>>m;
cin>>k;
if (k<n)
  {
  cout<<k+1<<' '<<1;
  return 0;
  }

m--;
k-=n;
cout<<n-(k/m)<<' ';
k%=2*m;
if (k>m-1)
  k=2*m-1-k;
cout<<k+2;



    return 0;
}