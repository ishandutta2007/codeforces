#include <bits/stdc++.h>

using namespace std;

long long n,k,i,j;
vector <long long> m;
long long beru[63];


bool corr(long long c)
{
long long t=1;
for (long long i=0; i<60; i++)
  {
  if (beru[i]==1)
    {
    long long c1=c/t;
    if (c1%2==0)
      return false;
    }
  t*=2;
  }
return true;
}

void need (long long by)
{
beru[by]=1;
long long can[63][63];
for (long long i=0; i<63; i++)
  for (long long j=0; j<63; j++)
    can[i][j]=0;
can[0][0]=1;

for (long long i=0; i<60; i++)
  {
  long long sum=0;
  for (long long j=i; j>=0; j--)
    {
    sum+=m[j];
    if (corr(sum))
      {
      for (long long u=1; u<60; u++)
        if (can[j][u-1]==1)
          can[i+1][u]=1;
      }
    }
  }
beru[by]=can[n][k];
}

int main()
{
cin>>n>>k;
for (i=0; i<60; i++)
  beru[i]=false;

for (i=0; i<n; i++)
  {long long a; cin>>a; m.push_back(a);}

for (long long u=59; u>=0; u--)
  need(u);

long long otv=0;
long long t=1;
for (i=0; i<60; i++)
  {
  if (beru[i]==1)
    otv+=t;
  t*=2;
  }
cout<<otv;

    return 0;
}