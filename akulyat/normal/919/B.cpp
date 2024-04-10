#include <bits/stdc++.h>

using namespace std;


bool des(long i)
{
long i1=i,s=0;
while (i1>0)
  {
  s+=(i1%10);
  i1/=10;
  }
if (s==10)
  return true; else
    return false;
}


int main()
{
  //  cout << "Hello world!" << endl;
long n,kol=0;
cin>>n;
if (n<6000)
for (long i=0; i<30000000; i++)
  {
  if (des(i))
    kol++;
  if (kol==n)
    {
    cout<<i;
    return 0;
    }
  } else
{
  kol=10001;
for (long i=10800100; i>0; i--)
  {
  if (des(i))
    kol--;
  if (kol==n)
    {
    cout<<i;
    return 0;
    }
  }
}
return 0;
}