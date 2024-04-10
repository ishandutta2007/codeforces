#include <bits/stdc++.h>

using namespace std;


long long n,a,b,sum,i;
vector <long long> m;


int main()
{
cin>>n>>a>>b;
sum=a+b;
long long cur=0;
for (i=0; i<n; i++)
  {
  char sy;
  cin>>sy;
  if (sy=='.')
    cur++;
  else
    {
    m.push_back(cur);
    cur=0;
    }
  }
m.push_back(cur);
n=m.size();



for (i=0; i<n; i++)
  {
  long long v=m[i];
  if (a>=b)
    {
    a=max((long long)0, a-(v+1)/2);
    b=max((long long)0, b-v/2);
    }
  else
    {
    b=max((long long)0, b-(v+1)/2);
    a=max((long long)0, a-v/2);
    }
  }

cout<<sum-a-b;
    return 0;
}