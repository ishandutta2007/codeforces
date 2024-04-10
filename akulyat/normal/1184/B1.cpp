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


ll n,i,j, b;
vector <pll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>b;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back({a, i});
  }
sort(m.begin(), m.end());

vector <pll> tos;
for (ll i=0; i<b; i++)
  {
  ll x, y;
  cin>>x>>y;
  tos.push_back({x, y});
  }
sort(tos.begin(), tos.end());
vector <ll> sum(1, 0);
for (auto i:tos)
  sum.push_back(sum.back()+i.S);

vector <ll> ans(n, 0);
for (auto pr:m)
  {
  ll num=pr.S;
  ll z=upper_bound(tos.begin(), tos.end(), make_pair(pr.F, inf))-tos.begin();
  ans[num]=sum[z];

  }

for (auto i:ans)
  cout<<i<<' ';








    return 0;
}