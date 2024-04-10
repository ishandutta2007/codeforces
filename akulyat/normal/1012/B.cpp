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

long n,m,q,i,j;
vector <long> reb[gs+10];
long long col[gs+10];
long long tc[gs+10];
bool viv=false;

void DFS(long v, long c)
{
//cout<<"In "<<v<<endl;
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
cin>>n>>m>>q;
for (i=0; i<q; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  b+=n;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
for (i=0; i<n+m; i++)
  col[i]=-1;

ll kol=0;
for (i=0; i<n+m; i++)
  if (col[i]==-1)
    {
    DFS(i, 0);
    kol++;
    }
cout<<kol-1;









    return 0;
}