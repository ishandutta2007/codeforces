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
vector <long> kids[gs+10];
vector <ll> p;
long long col[gs+10];
long long tc[gs+10];
bool viv=false;

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
cin>>n;
m=n-1;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
for (i=0; i<n; i++)
  col[i]=-1;

for (i=0; i<n; i++)
  tc[i]=-1;

DFS(0, 0);

/*
for (i=0; i<n; i++)
  cout<<col[i]<<' ';
cout<<endl;
*/




for (i=0; i<n; i++)
  p.push_back(0);

for (i=0; i<n; i++)
  for (auto s:reb[i])
    if (col[s]<col[i])
      p[i]=s;
    else
      kids[i].push_back(s);




vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort (tos.begin(), tos.end());
vector <ll> por;
for (auto i:tos)
  por.push_back(i.S);
reverse(por.begin(), por.end());

for (auto s:reb[0])
  tc[s]=1;

ll ans=0;
for (auto i:por)
  {
  bool work=true;
  if (tc[i]==1)
    work=false;
  for (auto s:reb[i])
    if (tc[s]==1)
      work=false;
  if (work)
    if (tc[p[i]]!=1)
      {
      ans++;
      tc[p[i]]=1;
      }
  }

cout<<ans;






    return 0;
}