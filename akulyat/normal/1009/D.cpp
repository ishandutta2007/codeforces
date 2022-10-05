#include <bits/stdc++.h>

using namespace std;

vector <long long> ans;
long long n,m,i;

long long GCD(long long a, long long b)
{
while (a!=0&&b!=0)
  {
  if (a>=b)
      a%=b;
  else
    b%=a;
  }
return a+b;
}

int main()
{
cin>>n>>m;
if (m<n-1)
  {
  cout<<"Impossible";
  return 0;
  }
long long i=1;
long long j=2;
while (m&&i<n)
  {
  if (GCD(i, j)==1)
    {
    ans.push_back(i);
    ans.push_back(j);
    m--;
    }
  j++;
  if (j>n)
    {
    i++;
    j=i+1;
    }
  }
if (m==0)
  {
  cout<<"Possible"<<endl;
  for (i=0; i<ans.size(); i+=2)
    {
    cout<<ans[i]<<' ';
    cout<<ans[i+1]<<endl;
    }
  return 0;
  }
cout<<"Impossible"<<endl;



    return 0;
}