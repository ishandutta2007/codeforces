#include <iostream>

using namespace std;

long n,kol,maxi,i;
long m[400000];

int main()
{
cin>>n;
for (i=0; i<2*n; i++)
  {
  long a; cin>>a;
  a--;
  m[a]++;
  if (m[a]==1)
    kol++;
  else
    kol--;
  maxi=max(maxi, kol);
  }
cout<<maxi;

    return 0;
}