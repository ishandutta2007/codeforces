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
long long r[gs+10];
long long rea[gs+10];
long long siz[gs+10];
bool viv=false;
ll d=0;


void DFS(long v, long c)
{
d++;
col[v]=d;
tc[v]=c;
long l=reb[v].size();
ll kol=0;
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c+1);
    kol+=siz[s];
    }
  }
siz[v]=kol+1;
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
cin>>n>>m;
for (i=1; i<n; i++)
  {
  long a;
  cin>>a;
  a--;
  reb[a].push_back(i);
  r[i]=a;
  }
for (i=0; i<n; i++)
  col[i]=-1;

d=-1;
DFS(0, 0);
for (i=0; i<n; i++)
  rea[col[i]]=i;



for (i=0; i<m; i++)
  {
  ll v,p;
  cin>>v>>p;
  v--;
  p--;
  if (siz[v]-1<p)
    cout<<-1<<endl;
  else
    cout<<rea[col[v]+p]+1<<endl;
  }
if (viv)
  {
  for (i=0; i<n; i++)
    cout<<rea[i]<<' ';
  cout<<endl;
  for (i=0; i<n; i++)
    cout<<col[i]<<' ';
  cout<<endl;
  }





    return 0;
}