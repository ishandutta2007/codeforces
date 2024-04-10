#include <iostream>

using namespace std;



long i,j,n;
long m[5010];
short f[5010][5010];
long ans[5010][5010];
long best[5010][5010];


int main()
{
ios_base::sync_with_stdio(0);
/*
f[0][0]=1;
for (i=1; i<5010; i++)
  {
  f[i][0]=1;
  for (j=0; j<i-1; j++)
    f[i][j+1]=f[i-1][j]^f[i-1][j+1];
  f[i][i]=1;
  }
*/

cin>>n;
for (i=0; i<n; i++)
  cin>>m[i];

for (i=0; i<n; i++)
  ans[i][i]=m[i];
for (j=1; j<n; j++)
  {
  for (i=0; i<n-j; i++)
    ans[i][i+j]=ans[i][i+j-1]^ans[i+1][i+j];
  }

for (i=0; i<n; i++)
  best[i][i]=ans[i][i];
for (long u=1; u<n; u++)
  {
  for (long j=0; j<n-u; j++)
    {
    best[j][j+u]=max(best[j][j+u-1], best[j+1][j+u]);
    best[j][j+u]=max(best[j][j+u], ans[j][j+u]);
    }
  }
//for (i=0; i)
long q;
cin>>q;
for (long u=0; u<q; u++)
  {
  long l,r;
  cin>>l>>r;
  l--; r--;
  cout<<best[l][r]<<endl;
  }
    return 0;
}