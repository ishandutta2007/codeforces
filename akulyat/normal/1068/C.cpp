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
vector <long> ans[gs+10];
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
cin>>n>>m;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
for (i=0; i<n; i++)
  ans[i].push_back(i);
j=n;
for (i=0; i<n; i++)
  for (auto s:reb[i])
    ans[i].push_back(j), ans[s].push_back(j), j++;

for (i=0; i<n; i++)
  {
  cout<<ans[i].size()<<endl;
  for (auto j:ans[i])
    cout<<j+1<<' '<<i+1<<endl;
  }






    return 0;
}