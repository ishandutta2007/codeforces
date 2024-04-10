#include <bits/stdc++.h>

using namespace std;

long double ans;
long long n,k,i,j;
vector <long> m;
int main()
{
ans=-1;
cin>>n>>k;
for (i=0; i<n; i++)
  {
  long a; cin>>a; m.push_back(a);
  }
j=0;
for (i=0; i<n-2; i++)
  {
  while ((j<n-1)&&(m[j+1]-m[i]<=k))
    j++;
  if (j-i>=2)
    ans=max(ans, (long double)((long double)m[j]-m[i+1])/((long double)m[j]-m[i]));
  }
if (ans==-1)
  {
  cout<<-1;
  return 0;
  }

cout.precision(12);
cout<<fixed<<ans;

    return 0;
}