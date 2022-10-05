#include <bits/stdc++.h>

using namespace std;

long long p[2000][2000],u[2000][2000],l[2000][2000],r[2000][2000],d[2000][2000];
long long n,m,i,j;


int main()
{
cin>>n>>m;
for (i=0; i<n; i++)
  for (j=0; j<m; j++)
    cin>>p[i+1][j+1];

for (i=0; i<n; i++)
  for (j=0; j<m; j++)
    {
    u[i+1][j+1]=u[i][j+1];
    l[i+1][j+1]=l[i+1][j];
    if (p[i][j+1]==1)
      u[i+1][j+1]++;
    if (p[i+1][j]==1)
      l[i+1][j+1]++;
    }

for (i=n-1; i>=0; i--)
  for (j=m-1; j>=0; j--)
    {
    d[i+1][j+1]=d[i+2][j+1];
    r[i+1][j+1]=r[i+1][j+2];
    if (p[i+2][j+1]==1)
      d[i+1][j+1]++;
    if (p[i+1][j+2]==1)
      r[i+1][j+1]++;
    }

long kol=0;
for (i=0; i<n; i++)
  for (j=0; j<m; j++)
    if (p[i+1][j+1]==0)
      {
      if (u[i+1][j+1]!=0)
        kol++;
      if (d[i+1][j+1]!=0)
        kol++;
      if (l[i+1][j+1]!=0)
        kol++;
      if (r[i+1][j+1]!=0)
        kol++;
      }
cout<<kol;
    return 0;
}