#include <bits/stdc++.h>

using namespace std;

long long n,i,j,u,ans,a,b,a1,b1,a2,b2,k;
vector <long long> v={1, 5, 10, 50};
vector <long long> tr, my;
long long s[102][10000];


int main()
{
cin>>k;
n=30;
tr.push_back(0);
for (i=1; i<=n+1; i++)
  tr.push_back(tr.back()+i);

my.push_back(1);
for (i=1; i<=n; i++)
  my.push_back(my.back()+tr[i+1]);

s[0][0]=1;
for (i=0; i<n; i++)
  {
  for (j=0; j<100*n; j++)
    if (s[i][j]==1)
      {
      for (auto u:v)
        s[i+1][j+u]=1;
      }
  }
long long osn=0;
for (i=0; i<=n; i++)
  {
  long long z=0;
  for (j=0; j<100*n; j++)
    z+=s[i][j];
//  cout<<i<<' '<<z<<' '<<my[i]<<' '<<my[i]-z<<endl;
  if (i==n)
    osn=z;
  if (i==k)
    {
    cout<<z;
    return 0;
    }
  }

cout<<osn+49*(k-n);

    return 0;
}