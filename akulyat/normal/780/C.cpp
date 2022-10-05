#include <bits/stdc++.h>

using namespace std;

long n,i;
const long kk=100*1000;
long col[3*kk];
vector <long> reb[3*kk];


void DFS(long v, long lt, long ct)
{
long l=reb[v].size();
long tc=0;
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==0)
    {
    tc++;
    while (tc==lt||tc==ct)
      tc++;
    col[s]=tc;
    DFS(s, ct, tc);
    }
  }
}

int main()
{
cin>>n;
for (i=0; i<n-1; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }

col[0]=1;
DFS(0, -1, 1);

long maxcol=0;
for (i=0; i<n; i++)
  maxcol=max(maxcol, col[i]);
cout<<maxcol<<endl;;
for (i=0; i<n; i++)
  cout<<col[i]<<' ';


    return 0;
}