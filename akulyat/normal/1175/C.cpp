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


ll n,i,j, k;
vector <ll> m;
bool viv=false;

void solve()
{
cin>>n>>k;
k++;
m.clear();
m.resize(n);
for (auto &i:m)
  cin>>i;

ll l=-1;
ll r=mod;
while (l+1<r)
  {
  ll mi=l+r>>1;
  bool good=false;
  for (ll i=0; i<n-k+1; i++)
    if (m[i+k-1]-m[i]<=mi)
      good=true;
  if (good)
    r=mi;
  else
    l=mi;
  }
for (ll i=0; i<n-k+1; i++)
  {
  if (m[i+k-1]-m[i]<=r)
    {
    ll ans=m[i+k-1]+m[i]>>1;
    cout<<ans<<'\n';
    return;
    }
  }
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