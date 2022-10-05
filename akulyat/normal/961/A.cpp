#include <bits/stdc++.h>

using namespace std;

long long n,i,m;
long long v[100000];
int main()
{
cin>>n>>m;
for (i=0; i<m; i++)
  {
  long a;
  cin>>a;
  a--;
  v[a]++;
  }

long long ans=10000;
for (i=0; i<n; i++)
  ans=min(ans, v[i]);

cout<<ans;
    return 0;
}