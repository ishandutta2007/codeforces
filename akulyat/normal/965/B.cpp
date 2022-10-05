#include <bits/stdc++.h>

using namespace std;

long n,k,i,j,u;
string s[200];
vector <long> m[200];
long ans[200][200];

int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  cin>>s[i];

for (i=0; i<n; i++)
  for (j=0; j<n; j++)
    if (s[i][j]=='#')
      m[i].push_back(1);
    else
      m[i].push_back(0);

for (i=0; i<n-k+1; i++)
  {
  for (j=0; j<n; j++)
    {
    long a=i;
    long b=j;
    long sum=0;
    for (u=i; u<i+k; u++)
      sum+=m[u][j];
    if (sum==0)
      for (u=i; u<i+k; u++)
        ans[u][j]++;
    }
  }

for (i=0; i<n; i++)
  {
  for (j=0; j<n-k+1; j++)
    {
    long a=i;
    long b=j;
    long sum=0;
    for (u=j; u<j+k; u++)
      sum+=m[i][u];
    if (sum==0)
      for (u=j; u<j+k; u++)
        ans[i][u]++;
    }
  }

long la=0;
long lb=0;
for (i=0; i<n; i++)
  for (j=0; j<n; j++)
    if (ans[i][j]>ans[la][lb])
      {la=i; lb=j;}

cout<<++la<<' '<<++lb<<endl;

    return 0;
}