#include <bits/stdc++.h>

using namespace std;


long long n,i,k;
vector <long long> m;
int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  }

long long ans=0;
while (m.size()>0&&m.back()<=k)
  {
  m.pop_back();
  ans++;
  }
long long j=0;
while (j<m.size()&&m[j]<=k)
  j++;

ans+=j;


cout<<ans;
    return 0;
}