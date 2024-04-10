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
vector <vector <ll>> reb;
vector <ll> col,tc;
vector <ll> t[2];
ll num[2];
bool viv=false;

void DFS(long v, long c)
{
col[v]=c;
t[c].push_back(v);
num[c]++;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c^1);
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

void solve()
{
cin>>n>>m;
reb.clear();
reb.resize(n);
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
col.clear();
tc.clear();
col.assign(n, -1);
tc.assign(n, -1);
t[0].clear();
t[1].clear();
num[0]=0;
num[1]=0;
DFS(0, 0);
if (t[0].size()<=t[1].size())
  {
  cout<<t[0].size()<<'\n';
  for (auto i:t[0])
    cout<<i+1<<' ';
  cout<<'\n';
  return;
  }
cout<<t[1].size()<<'\n';
for (auto i:t[1])
  cout<<i+1<<' ';
cout<<'\n';
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t)
  solve(), t--;








    return 0;
}