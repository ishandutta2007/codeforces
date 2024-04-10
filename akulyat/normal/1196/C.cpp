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
const long long inf=100*kk;


struct robot
{
  ll x, y;
  bool f1, f2, f3, f4;
};


ll n,i,j;
vector <robot> m;
bool viv=false;

void read_r()
{
ll a, b, c, d, e, f;
cin>>a>>b>>c>>d>>e>>f;
m.push_back({a, b, c, d, e, f});
}

void solve()
{
cin>>n;
m.clear();
for (ll i=0; i<n; i++)
  read_r();
ll xl=-inf, xr=inf;
ll yd=-inf, yu=inf;
for (ll i=0; i<n; i++)
  {
  if (!m[i].f1)
    xl=max(xl, m[i].x);
  if (!m[i].f3)
    xr=min(xr, m[i].x);
  if (!m[i].f4)
    yd=max(yd, m[i].y);
  if (!m[i].f2)
    yu=min(yu, m[i].y);
  }
if (xl>xr||yd>yu)
  {
  cout<<0<<'\n';
  return;
  }
cout<<1<<' '<<xl<<' '<<yd<<'\n';
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t--)
  solve();

    return 0;
}