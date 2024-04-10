#include <bits/stdc++.h>

using namespace std;

long long n,a,b,c,k,sum;

int main()
{
cin>>a>>b>>c>>n;


b-=c;
a-=c;
sum=a+b+c;

if (a<0||b<0||c<0)
  {
  cout<<-1;
  return 0;
  }

k=n-sum;

if (k<=0)
  {
  cout<<-1;
  return 0;
  }

cout<<k;




    return 0;
}