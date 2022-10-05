#include <bits/stdc++.h>

using namespace std;

long long n,k,l,i,j;
vector <long long> m;

int main()
{
cin>>n>>k>>l;
for (i=0; i<n*k; i++)
  {long long a; cin>>a; m.push_back(a);}
sort(m.begin(), m.end());
long long j=0;
while (j<n*k&&m[j]-m[0]<=l)
  j++;
j--;
if (j<n-1)
  {
  cout<<0;
  return 0;
  }

long long z=0;
long long ans=0;
while (z!=n)
  {
  if (k*n-j>=(z+1)*k)
    {
    ans+=m[j];
   // cout<<m[j]<<' '<<j<<endl;
    z++;
    }
  j--;
  }
cout<<ans;



    return 0;
}