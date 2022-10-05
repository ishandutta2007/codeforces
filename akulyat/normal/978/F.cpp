#include <bits/stdc++.h>

using namespace std;

long long n,q,i,j;
vector <long> m,m2,ans;


int main()
{
cin>>n>>q;
for (i=0; i<n; i++)
  {long a; cin>>a; m.push_back(a); m2.push_back(a);}

sort(m2.begin(), m2.end());
for (i=0; i<n; i++)
  {
  long e=m[i];
  long z=lower_bound(m2.begin(), m2.end(), e)-m2.begin();
  ans.push_back(z);
  }

for (long u=0; u<q; u++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  if (m[a]>m[b])
    ans[a]--;
  if (m[a]<m[b])
    ans[b]--;
  }

for (i=0; i<n; i++)
  cout<<ans[i]<<' ';



    return 0;
}