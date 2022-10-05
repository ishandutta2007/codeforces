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

bool can(ll val)
{
ll need=0;
for (ll i=n/2; i<n; i++)
  need+=max(0ll, val-m[i]);
return (need<=k);
}

void solve()
{
ll l=m[n/2];
ll r=l+mod;
while (l+1<r)
  {
  ll mi=l+r>>1;
  if (can(mi))
    l=mi;
  else
    r=mi;
  }
cout<<l<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
sort(m.begin(), m.end());
solve();

    return 0;
}