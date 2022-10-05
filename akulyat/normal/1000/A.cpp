#include <bits/stdc++.h>

using namespace std;

long long i,n;
long long m[10], m2[10];

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  string ss;
  cin>>ss;
  if (ss=="XXXS")
    m[0]++;
  if (ss=="XXS")
    m[1]++;
  if (ss=="XS")
    m[2]++;
  if (ss=="S")
    m[3]++;
  if (ss=="M")
    m[4]++;
  if (ss=="L")
    m[5]++;
  if (ss=="XL")
    m[6]++;
  if (ss=="XXL")
    m[7]++;
  if (ss=="XXXL")
    m[8]++;
  }
for (i=0; i<n; i++)
  {
  string ss;
  cin>>ss;
  if (ss=="XXXS")
    m2[0]++;
  if (ss=="XXS")
    m2[1]++;
  if (ss=="XS")
    m2[2]++;
  if (ss=="S")
    m2[3]++;
  if (ss=="M")
    m2[4]++;
  if (ss=="L")
    m2[5]++;
  if (ss=="XL")
    m2[6]++;
  if (ss=="XXL")
    m2[7]++;
  if (ss=="XXXL")
    m2[8]++;
  }

for (i=0; i<9; i++)
  {
  long long a=min(m[i], m2[i]);
  m2[i]-=a;
  m[i]-=a;
  }

long long ans=0;
for (i=0; i<9; i++)
  {
  ans+=(m[i]+m2[i]);
  }

ans/=2;

cout<<ans;



    return 0;
}