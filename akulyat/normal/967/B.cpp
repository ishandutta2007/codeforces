#include <bits/stdc++.h>

using namespace std;

long long n,i,j,ma,a,b,sum;
vector <long long> m;


int main()
{
cin>>n>>a>>b;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  sum+=a;
  if (i!=0)
    m.push_back(a);
  else
    ma=a;
  }

sort(m.begin(), m.end());

long double have=(ma*a)/(long double)sum;
long long ans=0;
while (have<b)
  {
  sum-=m.back();
  m.pop_back();
  have=(ma*a)/(long double)sum;
  ans++;
  }

cout<<ans;


    return 0;
}