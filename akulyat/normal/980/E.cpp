#include <bits/stdc++.h>

using namespace std;

const long kk=1000;
long n,k,i,j;
vector <long> reb[kk*kk+10];
long col[kk*kk+10];
long nextv[kk*kk+10][23];
bool use[kk*kk+10];
long ost;
long ras[23];

void DFS(long v, long t)
{
col[v]=t;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, t+1);
    nextv[s][0]=v;
    }
  }
}

void add(long v)
{
double will=true;
long z=ost;
for (long j=0; j<23; j++)
  {
  ras[j]=z%2;
  z/=2;
  }
long v1=v;
for (long j=0; j<23; j++)
  if (ras[j]==1)
    {
    v1=nextv[v1][j];
    }
long v2=v;
if (use[v1])
  {
  while (!use[v2])
    {
    use[v2]=true;
    v2=nextv[v2][0];
    ost--;
    }
  }
}


int main()
{
ios::sync_with_stdio(0);cin.tie(0);


cin>>n>>k;
k=n-k;
ost=k;
for (i=0; i<n-1; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }

for (i=0; i<n; i++)
  col[i]=-1;
nextv[n-1][0]=n;
nextv[n][0]=n;
DFS(n-1, 0);
for (j=1; j<23; j++)
  {
  for (i=0; i<=n; i++)
    nextv[i][j]=nextv[nextv[i][j-1]][j-1];
  }

use[n]=true;
for (i=n-1; i>=0; i--)
  add(i);
    /*
for (i=0; i<n; i++)
  cout<<nextv[i][0]<<' ';
cout<<endl;
//   */

for (long i=0; i<n; i++)
  if (!use[i])
    cout<<i+1<<' ';
    return 0;
}