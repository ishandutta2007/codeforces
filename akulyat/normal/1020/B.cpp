#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long long gs=500*kk;

long n,m,i,j;
vector <long> reb[gs+10];
long long col[gs+10];
long long tc[gs+10];
bool viv=false;

long long DFS(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]!=-1)
    return s;
  if (col[s]==-1)
    {
    return DFS(s, c+1);
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
cin>>n;
for (i=0; i<n; i++)
  {
  long a,b;
  a=i;
  cin>>b;
  b--;
  reb[a].push_back(b);
  }
for (i=0; i<n; i++)
  col[i]=-1;

for (i=0; i<n; i++)
  tc[i]=-1;

for (i=0; i<n; i++)
  {
  for (j=0; j<n; j++)
    col[j]=-1;
  cout<<DFS(i, 0)+1<<' ';
  }









    return 0;
}