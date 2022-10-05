#include <bits/stdc++.h>

using namespace std;

const long long s=500;
long long n,i,u,j;
vector <long long> m;
vector <long long> m1[1000];



int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  a=min(a, (long long)n);
  m.push_back(a);
  }

long long ans=0;
long long j=-1;
for (i=0; i<n; i++)
  {
  long long v=m[i];
  long long r=min(v, i);
  for (u=0; u<=j; u++)
    if ((u+1)*s<=r)
      {
      long long z=lower_bound(m1[u].begin(), m1[u].end(), i+1)-m1[u].begin();
      z=(m1[u].size()-z);
      ans+=z;
      }
    else
      {
      for (long long q=u*s; q<r; q++)
        if (m[q]>=i+1)
          {
          ans++;
//          cout<<i<<' '<<r<<' '<<endl;
          }
      u=j+1;
      }
  j=i/s;
  m1[j].push_back(v);
  long long p=m1[j].size()-1;
  while (p>0&&m1[j][p-1]>m1[j][p])
    {
    swap(m1[j][p], m1[j][p-1]);
    p--;
    }
  }

cout<<ans;


    return 0;
}