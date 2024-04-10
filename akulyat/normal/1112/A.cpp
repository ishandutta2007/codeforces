#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

const ll kk=1000;
const ll ml=kk*kk;
const ll mod=ml*kk+7;
const ll inf=ml*ml*ml+7;

vector <ll> m;
vector <pll> sc[kk];
ll i,j,u,n,s,k;
bool viv=false;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>s>>k;
for (ll i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
for (ll i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  sc[a].push_back({m[i], i});
  }
vector <ll> p(n, -1);

for (ll i=0; i<s; i++)
  {
  sort(sc[i].rbegin(), sc[i].rend());
  for (ll j=0; j<sc[i].size(); j++)
    p[sc[i][j].S]=j;
  }
ll ans=0;
for (ll i=0; i<k; i++)
  {
  ll a;
  cin>>a;
  a--;
//  cout<<a<<' '<<p[a]<<endl;
  if (p[a]!=0)
    ans++;
  }
cout<<ans<<endl;















    return 0;
}