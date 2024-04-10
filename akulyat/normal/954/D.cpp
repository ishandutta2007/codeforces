#include <bits/stdc++.h>

using namespace std;

long col[2000];
vector <long> reb[2000];
long n,m,i,j,s,t,kol;
long mat[2000][2000],rast[2000][2000];

void DFS(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1||col[s]>c+1)
    DFS(s, c+1);
  }
}

int main()
{
cin>>n>>m>>s>>t; s--; t--;
for (i=0; i<m; i++)
  {
  long a,b; cin>>a>>b; a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
for (i=0; i<n; i++)
  {
  for (j=0; j<n; j++)
    col[j]=-1;
  DFS(i, 0);
  for (j=0; j<n; j++)
    rast[i][j]=col[j];
  }


for (i=0; i<n; i++)
  for (j=0; j<n; j++)
    mat[i][j]=0;

for (i=0; i<n; i++)
  for (j=0; j<reb[i].size(); j++)
    mat[i][reb[i][j]]=1;
for (i=0; i<n; i++)
  mat[i][i]=1;


long r=rast[s][t];
for (i=0; i<n; i++)
  for (j=0; j<n; j++)
    if (mat[i][j]==0)
      if (rast[i][s]+rast[j][t]>=r-1&&rast[i][t]+rast[j][s]>=r-1)
        {kol++; /*cout<<i<<j<<endl;*/}

cout<<kol/2;

    return 0;
}