#include <bits/stdc++.h>

using namespace std;

long long n,k,i,j;
vector <long long> m,f;
long long a[701][7001];
long long kol[200000],love[200000];

void zap()
{
long long i,j,u;
long long p=600;
long long full=6000;
for (i=0; i<p; i++)
  for (j=0; j<=full; j++)
    for (u=0; u<=k; u++)
      a[i+1][j+u]=max(a[i+1][j+u], a[i][j]+m[u]);
}

int main()
{
cin>>n>>k;
for (i=0; i<n*k; i++)
  {
  long long a;
  cin>>a;
  kol[a]++;
  }

for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  love[a]++;
  }
m.push_back(0);
for (i=0; i<k; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  }

zap();
long long ans=0;
for (i=0; i<=100000; i++)
  {
  long long v=a[love[i]][kol[i]];
  if (v!=0)
//    cout<<i<<' '<<v<<' '<<endl;
  ans+=v;
  }
cout<<ans<<endl;




    return 0;
}