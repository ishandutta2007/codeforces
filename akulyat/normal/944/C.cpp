#include <bits/stdc++.h>

using namespace std;

long col[200000];
long howm[200000];
long n;
vector <long> reb[200000];


void DFS(long v, long tc)
{
tc++;
col[v]=tc;
for (long i=0; i<reb[v].size(); i++)
  if (col[reb[v][i] ]==0)
  {
  DFS(reb[v][i], tc);
  }
tc--;
}


int main()
{
cin>>n;
col[0]=0;
long i;
for (i=1; i<n; i++)
  {
  col[i]=0;
  long a;
  cin>>a; a--;
  reb[a].push_back(i);
  reb[i].push_back(a);
  }

DFS(0, 0);

for (i=0; i<n; i++)
  howm[col[i] ]++;

long ans=0;
for (i=0; i<n+1; i++)
  if (howm[i]%2==1)
    ans++;
cout<<ans;


    return 0;
}