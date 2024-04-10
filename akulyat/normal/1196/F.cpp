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

long n,m,i,j, k;
vector <pll> reb[gs+10];
vector <pair <ll, pll>> rebs;
vector <ll> col,tc;
vector <ll> paths;
bool viv=false;

void read()
{
cin>>n>>m>>k;
for (i=0; i<m; i++)
  {
  long a,b;
  ll c;
  cin>>a>>b>>c;
  a--; b--;
  rebs.push_back({c, {a, b}});
  }
col.assign(n, -1);
tc.assign(n, mod*kk);
}

void prepare()
{
sort(rebs.begin(), rebs.end());
while (rebs.size()>k)
  rebs.pop_back();
for (auto t:rebs)
  {
  ll a=t.S.F;
  ll b=t.S.S;
  ll c=t.F;
  reb[a].push_back({b, c});
  reb[b].push_back({a, c});
  }
}

void work(ll v)
{
if (viv)
  cout<<"Start "<<v<<endl;
set <pll> st;
st.insert({0, v});
col[v]=v;
tc[v]=0;
while (st.size())
  {
  auto p=*st.begin();
  st.erase(st.begin());
  ll d=p.F;
  ll cv=p.S;
  if (d)
//    cout<<"Add "<<d<<" from "<<v<<" to "<<cv<<endl,
  paths.push_back(d);
  for (auto pr:reb[cv])
    {
    ll s=pr.F;
    ll w=pr.S;
    if (col[s]!=v)
      {
      col[s]=v;
      tc[s]=d+w;
      st.insert({tc[s], s});
      }
    else
      if (d+w<tc[s])
        {
        st.erase({tc[s], s});
        tc[s]=d+w;
        st.insert({tc[s], s});
        }
    }
  }
if (viv)
  cout<<"End "<<v<<endl;
}

void solve()
{
for (ll i=0; i<n; i++)
  work(i);
}

void write()
{
sort(paths.begin(), paths.end());
if (viv)
  {
  for (ll i=0; i<n; i++)
    cout<<reb[i].size()<<' ';
  cout<<endl;
  cout<<paths.size()<<endl;
  for (auto i:paths)
    cout<<i<<' ';
  cout<<endl;
  }
cout<<paths[2*k-1]<<endl;
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
read();
prepare();
solve();
write();






    return 0;
}