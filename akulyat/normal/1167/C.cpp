#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

//ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long long gs=500*kk;

long n,m,i,j;
vector <long> reb[gs+10];
vector <vector <ll>> in, gr;
vector <bool> used;
vector <ll> col,tc, sz;
bool viv=false;

void DFS(long v, long c)
{
col[v]=c;
sz.back()++;
if (viv)
  cout<<"In "<<v<<endl;
for (ll i=0; i<in[v].size(); i++)
  if (!used[in[v][i]])
    {
    used[in[v][i]]=true;
    for (auto sos:gr[in[v][i]])
      if (col[sos]==-1)
        DFS(sos, c);
    }
}



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>n>>m;
in.resize(n);
gr.resize(m);
used.resize(m, false);
for (i=0; i<m; i++)
  {
  ll k;
  cin>>k;
  for (ll j=0; j<k; j++)
    {
    ll v;
    cin>>v;
    v--;
    in[v].push_back(i);
    gr[i].push_back(v);
    }
  }
col.assign(n, -1);
ll tc=0;
for (ll i=0; i<n; i++)
  if (col[i]==-1)
    sz.push_back(0), DFS(i, tc), tc++;
if (viv)
  {
  for (auto i:col)
    cout<<i<<' ';
  cout<<endl;
  for (auto i:sz)
    cout<<i<<' ';
  cout<<endl;
  }
for (auto &i:col)
  i=sz[i];

for (auto i:col)
  cout<<i<<' ';





    return 0;
}