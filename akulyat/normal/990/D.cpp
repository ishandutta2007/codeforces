#include <bits/stdc++.h>

using namespace std;

long long n,a,b,k,i,j;
int main()
{
cin>>n>>a>>b;
if (n==1)
  {
  cout<<"YES"<<endl;
  cout<<0;
  return 0;
  }
if (b==1)
  {
  if (a==1&&n<=3)
    {
    cout<<"NO"<<endl;
    return 0;
    }
  cout<<"YES"<<endl;
  if (a==1)
    {
    for (i=0; i<n; i++)
      {
      for (j=0; j<n; j++)
      {
      if (abs(i-j)==1)
        cout<<1;
      else
        cout<<0;
      }
      cout<<endl;
      }
    return 0;
    }
  for (i=0; i<n; i++)
    {
    for (j=0; j<n; j++)
      {
      if (i==j)
        cout<<0;
      else
        {
        if (i>=a-1&&j>=a-1)
          cout<<1;
        else
          cout<<0;
        }
      }
    cout<<endl;
    }
  return 0;
  }
if (a!=1)
  {
  cout<<"NO"<<endl;
  return 0;
  }
if (b>n)
  {
  cout<<"NO"<<endl;
  return 0;
  }

cout<<"YES"<<endl;
k=b-1;
for (i=0; i<n; i++)
  {
  for (j=0; j<n; j++)
    {
    if (i==j)
      cout<<0;
    else
      {
      if (i<k||j<k)
        cout<<1;
      else
        cout<<0;
      }
    }
  cout<<endl;
  }

    return 0;
}