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


ll n,i,j, l;
vector <ll> m, kol, ans;
vector <vector <pll>> p;
bool viv=false;

void prepare()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
kol.resize(n, 1);
for (ll i=1; i<n; i++)
  if (m[i]>m[i-1])
    kol[i]+=kol[i-1];
for (ll i=0; i<n; i++)
  {
  if (kol[i]==1)
    p.push_back({});
  p.back().push_back({m[i], i});
  }
l=p.size();
ans.resize(n, -1);

for (ll i=0; i<n-1; i++)
  if (m[i]==m[i+1])
    ans[i]=0, ans[i+1]=1;

ll low=mod;
ll high=-1;
for (ll v=0; v<l; v++)
  {
  if (viv)
    {
    for (auto i:p[v])
      cout<<i.F<<' '<<i.S<<"   ";
    cout<<endl;
    }
  if (p[v].size()==1)
    {
    if (ans[p[v][0].S]==-1)
      ans[p[v][0].S]=1,
      low=p[v].back().F;
    else
      high=p[v].back().F;
    }
  else
    {
    ll k=p[v].size();
    if (ans[p[v][0].S]!=-1)
      {
      if (ans[p[v][0].S]==0)
        ans[p[v][0].S]=0, high=p[v][0].F;
      else
        ans[p[v][0].S]=1, low=p[v][0].F;
      }
    else
      {
      if (p[v][0].F>high)
        ans[p[v][0].S]=0, high=p[v][0].F;
      else
        ans[p[v][0].S]=1, low=p[v][0].F;
      }

    for (ll i=1; i<k-1; i++)
      ans[p[v][i].S]=0, high=p[v][i].F;


    if (ans[p[v].back().S]!=-1)
      {
      if (ans[p[v].back().S]==1)
        ans[p[v].back().S]=1, low=p[v].back().F;
      else
        ans[p[v].back().S]=0, high=p[v].back().F;
      }
    else
      {
      if (p[v].back().F<low)
        ans[p[v].back().S]=1, low=p[v].back().F;
      else
        ans[p[v].back().S]=0, high=p[v].back().F;
      }
    }
  }

}


void bad()
{
cout<<"NO"<<endl;
if (!viv)
exit(0);
}

void check()
{
vector <ll> p[2];
for (ll i=0; i<n; i++)
  p[ans[i]].push_back(m[i]);
for (ll i=1; i<p[0].size(); i++)
  if (p[0][i-1]>=p[0][i])
    bad();
for (ll i=1; i<p[1].size(); i++)
  if (p[1][i-1]<=p[1][i])
    bad();
}

void write()
{
check();
cout<<"YES"<<endl;
for (auto i:ans)
  cout<<i<<' ';
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
prepare();
write();






    return 0;
}
/**
1 2 3 8   7 6 5   4 10 11 12 1

8
20 1 2 3 8 5 2 9

5
1 2 2 1 6

**/