#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long mod=kk*kk*kk+7;
const long long gs=300*kk;
long n,r,i,j,k;
vector <long long> m;
vector <long> reb[gs+10];
long long col[gs+10];
long long tc[gs+10];

void DFS(long v, long c)
{
m.push_back(v);
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c+1);
    m.push_back(v);
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
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>r>>k;
for (i=0; i<r; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
for (i=0; i<n; i++)
  col[i]=-1;

DFS(0, 0);

long long l=m.size();
for (i=1; i<l; i++)
  m.push_back(m[i]);
for (i=1; i<l; i++)
  m.push_back(m[i]);
for (i=1; i<l; i++)
  m.push_back(m[i]);
for (i=1; i<l; i++)
  m.push_back(m[i]);
for (i=1; i<l; i++)
  m.push_back(m[i]);
for (i=1; i<l; i++)
  m.push_back(m[i]);


long long z=(2*n+k-1)/k;
if (n==1)
    z=1;
for (i=0; i<k; i++)
  {
  cout<<z<<' ';
  for (j=0; j<z; j++)
    cout<<m[i*z+j]+1<<' ';
  cout<<'\n';
  }








    return 0;
}