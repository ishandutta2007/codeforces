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


ll n,i,j,p;
vector <ll> m[4*kk];
bool viv=false;


int main()
{
cin>>n>>p;
for (i=0; i<n; i++)
  {
  ll a,v;
  cin>>a>>v;
  a--;
  m[a].push_back(v);
  }

for (i=0; i<p; i++)
  sort(m[i].begin(), m[i].end());

ll ans=inf;
for (ll u=max((ll)m[0].size(), 1ll); u<=n; u++)
  {
  ll add=u-m[0].size();
  ll lans=0;
  ll kol=0;
  vector <ll> var;
  for (i=1; i<p; i++)
    {
    ll zabr=0;
    zabr=max(0ll, m[i].size()-u+1);
    for (j=0; j<zabr; j++)
      lans+=m[i][j];
    for (j=zabr; j<m[i].size(); j++)
      var.push_back(m[i][j]);
    kol+=zabr;
    }
  sort(var.begin(), var.end());
  for (i=0; i<max(0ll, add-kol); i++)
    lans+=var[i];
  ans=min(ans, lans);
  }

cout<<ans;






    return 0;
}

/*
5 5
2 100
3 200
4 300
5 400
5 900




*/