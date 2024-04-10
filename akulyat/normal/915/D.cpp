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
vector <ll> cycle,st;
set <pll> rej;
long long col[gs+10];
long long tc[gs+10];
bool good;
bool viv=false;

vector <ll> norm(vector <ll> m)
{
reverse(m.begin(), m.end());
while  (m[0]!=m.back())
  m.pop_back();
m.pop_back();
reverse(m.begin(), m.end());
return m;
}

void DFS1(long v, long c)
{
col[v]=1;
st.push_back(v);
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
    {
    if (col[s]==1&&cycle.empty())
      {
      st.push_back(s);
      cycle=norm(st);
 /*
      cout<<"I have:";
      for (auto i:st)
        cout<<i<<' ';
      cout<<endl;
// */
      }
    if (col[s]==-1)
      {
      DFS1(s, c+1);
      }
    }
  }
st.pop_back();
col[v]=2;
}

void DFS(long v, long c)
{
col[v]=1;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (rej.find({v, s})==rej.end())
    {
    if (col[s]==1)
      good=false;
    if (col[s]==-1)
      DFS(s, c+1);
    }
  }
col[v]=2;
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
//  reb[b].push_back(a);
  }
for (i=0; i<n; i++)
  col[i]=-1;

for (i=0; i<n; i++)
  DFS1(i, 1);

vector <pll> pos;
for (i=0; i<cycle.size(); i++)
  pos.push_back({cycle[i], cycle[(i+1)%cycle.size()]});

for (auto j:pos)
  {
  rej.clear();
  rej.insert(j);
  for (i=0; i<n; i++)
    col[i]=-1;
  good=true;
  for (i=0; i<n; i++)
    if (col[i]==-1)
      DFS(i, 1);
  if (good)
    {
    puts("YES");
    return 0;
    }
  }
if (cycle.empty())
  {
  puts("YES");
  return 0;
  }
puts("NO");
 /*
for (auto i:cycle)
  cout<<i<<' ';
cout<<endl;
// */
    return 0;
}