#include <bits/stdc++.h>

using namespace std;

long long n,k,i;
vector <long long> m;

int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {long long a; cin>>a; m.push_back(a); }
m.push_back(1000000000000);
n++;

sort(m.begin(), m.end());
/*
for (i=0; i<n; i++)
  cout<<m[i]<<' ';
cout<<endl;
*/

long long j=0;
long long ans=0;
while (j<n-1)
  {
//  cout<<j<<endl;
  while (j<n-1&&m[j+1]-m[j]<=k)
    j++;
  long long s=j;
  while (s>0&&m[s-1]==m[s])
    s--;
  ans+=(j-s+1);
  j++;
  }


cout<<ans;
    return 0;
}