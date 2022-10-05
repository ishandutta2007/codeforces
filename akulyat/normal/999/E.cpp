#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long mod=kk*kk*kk+7;
const long long gs=500*kk;
long long n,m,i,j,s;
vector <long long> reb[gs+10], rreb[gs+10], creb[gs+10], rcreb[gs+10];
long long col[gs+10];
long long tc[gs+10];
long long z[gs+10];
long long lc[gs+10];
long long trc[gs+10];
vector <long long> st;
vector <long long> css[5000];

void DFS(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c+1);
    }
  }
st.push_back(v);
}

void DFS2(long v, long c)
{
css[c].push_back(v);
tc[v]=c;
long l=rreb[v].size();
for (long i=0; i<l; i++)
  {
  long s=rreb[v][i];
  if (tc[s]==-1)
    {
    DFS2(s, c);
    }
  }
}

void DFS3(long v, long c)
{
trc[v]=c;
long l=creb[v].size();
for (long i=0; i<l; i++)
  {
  long s=creb[v][i];
  if (trc[s]==-1)
    {
    DFS3(s, c);
    }
  }
}

void DFS4(long v, long c)
{
lc[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (lc[s]==-1)
    {
    DFS4(s, c);
    }
  }
}

void BFS(long v)
{
vector <long> st;
st.push_back(v);
long s=0;
tc[v]=0;

while (s<st.size())
  {
  long e=st[s];
  long l=reb[e].size();
  for (long i=0; i<l; i++)
    {
    long s=reb[e][i];
    if (tc[s]==-1)
      {
      st.push_back(s);
      tc[s]=tc[e]+1;
      }
    }
  s++;
  }

}


int main()
{
cin>>n>>m>>s;
s--;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  rreb[b].push_back(a);
  }
for (i=0; i<n; i++)
  col[i]=-1;
for (i=0; i<n; i++)
  tc[i]=-1;

for (i=0; i<n; i++)
  if (col[i]==-1)
    DFS(i, 0);

reverse(st.begin(), st.end());

long long cc=0;
for (i=0; i<n; i++)
  {
  long long v=st[i];
  if (tc[v]==-1)
    {
    DFS2(v, cc);
    cc++;
    }
  }


for (i=0; i<n; i++)
  {
  long long a=tc[i];
  for (j=0; j<reb[i].size(); j++)
    {
    long long b=tc[reb[i][j]];
    if (a!=b)
      {
      creb[a].push_back(b);
      rcreb[b].push_back(a);
      }
    }
  }


for (i=0; i<cc; i++)
  trc[i]=-1;
long long comps=0;
for (i=0; i<cc; i++)
  if (trc[i]==-1)
    {
    DFS3(i, comps);
    comps++;
    }



long long ans=0;
for (i=0; i<n; i++)
  lc[i]=-1;
DFS4(s, 0);
for (i=0; i<n; i++)
  if (lc[i]==-1)
    if (tc[i]!=tc[s])
      if (rcreb[tc[i]].size()==0)
        z[tc[i]]=1;

/*
for (i=0; i<n; i++)
  cout<<lc[i]<<' ';
cout<<endl;
for (i=0; i<n; i++)
  cout<<tc[i]<<' ';
cout<<endl;
*/
for (i=0; i<cc; i++)
  {
//  cout<<z[i]<<' ';
  ans+=z[i];
  }


cout<<ans<<endl;



    return 0;
}