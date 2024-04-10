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


ll n,i,j,q;
vector <ll> m;
vector <ll> ins[100*kk];
vector <ll> er[100*kk];
long long have[100*kk];
long long have2[100*kk];
bool was[100*kk];
bool viv=false;


int main()
{
cin>>n>>q;
for (i=0; i<=n; i++)
  was[i]=false;
for (i=0; i<q; i++)
  {
  ll a,b,v;
  cin>>a>>b>>v;
  a--; b--;
  ins[a].push_back(v);
  er[b+1].push_back(v);
  }


have[0]=1;
for (i=0; i<n; i++)
  {
  for (ll u=0; u<=n; u++)
    have2[u]=have[u];
  for (auto j:er[i])
    for (ll u=j; u<=n; u++)
      {
      have[u]-=have[u-j];
      have[u]+=mod;
      have[u]%=mod;
      }
  for (auto j:ins[i])
    for (ll u=n; u>=j; u--)
      {
      have[u]+=have[u-j];
      have[u]%=mod;
      if (have[u]!=0)
        was[u]=true;
      }
  }

ll kol=0;
for (i=1; i<=n; i++)
  if (was[i])
    kol++;
cout<<kol<<endl;
for (i=1; i<=n; i++)
  if (was[i])
    cout<<i<<' ';
cout<<endl;



    return 0;
}