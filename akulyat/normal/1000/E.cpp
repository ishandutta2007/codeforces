#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long mod=kk*kk*kk+7;
const long long gs=500*kk;
long long n,m,i,j;
vector <long long> reb[gs+10],zapr[gs+10],cr[gs+10];
vector <bool> can[gs+10];
vector <long long> st;
set <long long> ms[gs+10];
long long col[gs+10];
long long col2[gs+10];
long long col3[gs+10];
long long tc[gs+10];
long long l1[gs+10];
long long l2[gs+10];

void DFS(long long v, long long c, long long from)
{
col[v]=c;
long long l=reb[v].size();
if (from!=-1)
  zapr[from].push_back(v);
st.push_back(v);

for (long long i=0; i<l; i++)
  {
  long long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c+1, v);
    }
  }
}

void DFS2(long long v, long long c)
{
col2[v]=c;
long long l=reb[v].size();

for (long long i=0; i<l; i++)
  if (can[v][i])
    {
    long long s=reb[v][i];
    if (col2[s]==-1)
      {
      DFS2(s, c);
      }
    }
}

void DFS3(long long v, long long c)
{
col3[v]=c;
long long l=cr[v].size();

for (long long i=0; i<l; i++)
  {
  long long s=cr[v][i];
  if (col3[s]==-1)
    {
    DFS3(s, c+1);
    }
  }
}


void cou(long long v)
{
long long i;
long long l=cr[v].size();
for (i=0; i<l; i++)
  {
  long long s=cr[v][i];
  if (col3[s]>col3[v])
    {
    long long bb=l1[s]+1;
    if (bb>l1[v])
      {
      l2[v]=l1[v];
      l1[v]=bb;
      }
    else
      {
      if (bb>l2[v])
        l2[v]=bb;
      }
    }
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<m; i++)
  {
  long long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  can[a].push_back(true);
  reb[b].push_back(a);
  can[b].push_back(true);
  }
for (i=0; i<n; i++)
  col[i]=-1;
for (i=0; i<n; i++)
  col2[i]=-1;
for (i=0; i<n; i++)
  col3[i]=-1;

DFS(0, 0, -1);

for (i=0; i<n; i++)
  sort(reb[i].begin(), reb[i].end());
for (i=0; i<n; i++)
  sort(zapr[i].begin(), zapr[i].end());

for (i=0; i<n; i++)
  {
  long long p=0;
  long long l=zapr[i].size();
  for (j=0; j<l; j++)
    {
    long long v=zapr[i][j];
    while (reb[i][p]<v)
      p++;
    can[i][p]=false;
    }
  }


long long rc=0;
for (i=0; i<n; i++)
  {
  long long v=st[i];
  if (col2[v]==-1)
    {
    DFS2(v, rc);
    rc++;
    }
  }

/*
for (i=0; i<n; i++)
  cout<<col2[i]<<' ';
cout<<endl;
*/
// /////////////////////////////////////////
for (i=0; i<n; i++)
  {
  long long c1=col2[i];
  long long l=reb[i].size();
  for (j=0; j<l; j++)
    {
    long long s=reb[i][j];
    long long c2=col2[s];
    if (c1!=c2)
      {
      ms[c1].insert(c2);
      ms[c2].insert(c1);
      }
    }
  }


for (i=0; i<rc; i++)
  for (auto j:ms[i])
    cr[i].push_back(j);

/*
for (i=0; i<rc; i++)
  {
  for (auto j:cr[i])
    cout<<j<<' ';
  cout<<endl;
  }
*/
// ////////////////////////////////////////////
DFS3(0, 0);

vector < pair <long long, long long> > tos;
for (i=0; i<rc; i++)
  tos.push_back({col3[i], i});
sort(tos.begin(), tos.end());
reverse(tos.begin(), tos.end());

vector <long long> nv;
for (i=0; i<rc; i++)
  nv.push_back(tos[i].second);


for (i=0; i<rc; i++)
  {
  long long v=nv[i];
  cou(v);
  }

long long anss=0;
for (i=0; i<rc; i++)
  anss=max(anss, l2[i]+l1[i]+1);

cout<<anss-1;

    return 0;
}