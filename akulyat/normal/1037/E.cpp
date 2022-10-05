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

long n,m,i,j,k;
set <long> reb[gs+10];
vector <pll> sp;
long long col[gs+10];
long long tc[gs+10];
bool viv=false;

/*
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
*/

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>k;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].insert(b);
  reb[b].insert(a);
  sp.push_back({a, b});
  }
reverse(sp.begin(), sp.end());
vector <ll> st;
for (i=0; i<n; i++)
  if (reb[i].size()<k)
    st.push_back(i);
ll s=0;
while (s!=st.size())
  {
  ll v=st[s];
  for (auto s:reb[v])
    {
    reb[s].erase(v);
    if (reb[s].size()==k-1)
      st.push_back(s);
    }
  reb[v].clear();
  s++;
  }
vector <ll> ans;
ans.push_back(n-st.size());
for (auto r:sp)
  {
  ll a=r.F;
  ll b=r.S;
  if (reb[a].find(b)!=reb[a].end())
    {
    reb[a].erase(b);
    reb[b].erase(a);
    if (reb[a].size()==k-1)
      st.push_back(a);
    if (reb[b].size()==k-1)
      st.push_back(b);
    while (s!=st.size())
      {
      ll v=st[s];
      for (auto s:reb[v])
        {
        reb[s].erase(v);
        if (reb[s].size()==k-1)
          st.push_back(s);
        }
      reb[v].clear();
      s++;
      }
    }
  ans.push_back(n-st.size());
  }
ans.pop_back();
reverse(ans.begin(), ans.end());
for (auto i:ans)
  cout<<i<<'\n';

    return 0;
}

/*
4 4 2
2 3
1 2
1 3
1 4

5 8 2
2 1
4 2
5 4
5 2
4 3
5 1
4 1
3 2

5 7 2
1 5
3 2
2 5
3 4
1 2
5 3
1 3

*/