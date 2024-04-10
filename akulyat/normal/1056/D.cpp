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
vector <ll> col,tc;
bool viv=false;
vector <ll> st;

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
for (i=1; i<n; i++)
  {
  long a,b;
  cin>>a;
  a--;
  b=i;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
col.assign(n, -1);
tc.assign(n, 0);
DFS(0, 0);
vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());
for (auto i:tos)
  st.push_back(i.S);
for (auto i:st)
  {
  for (auto s:reb[i])
    if (col[s]>col[i])
      tc[i]+=tc[s];
  if (tc[i]==0)
    tc[i]=1;
//  cout<<i<<' '<<tc[i]<<endl;
  }
sort(tc.begin(), tc.end());
for (auto i:tc)
  cout<<i<<' ';
cout<<endl;

    return 0;
}