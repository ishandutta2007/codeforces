#include <iostream>

using namespace std;

int main()
{
long i,n;
long ans[3000];
cin>>n;
if (n<6)
  {
  cout<<0;
  return 0;
  }
ans[6]=1;
for (i=7; i<=n; i++)
  {
  ans[i]=ans[i-1];
  long i1=i;
  long j,u;
  for (j=1; j<=i; j++)
    {
    u=(j^i);
    if ((u<=j)&&(u+j>i))
      {
      ans[i]++;
      }
    }
  }
long otv=ans[n];
cout<<otv;

  return 0;
}