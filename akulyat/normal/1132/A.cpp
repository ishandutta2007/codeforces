#include <bits/stdc++.h>

using namespace std;


#define F first
#define S second
typedef long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
//const long long inf=ml*ml*ml+7;


ll n,i,j, r;
vector <pll> m, v, mask;
bool viv=false;

void build()
{
mask.clear();
for (ll a=0; a*a<=r; a++)
  {
  ll b=r-a*a;
  ll z=round(sqrt(b));
  if (z*z==b)
    {
    mask.push_back({a, z});
    mask.push_back({a, -z});
    mask.push_back({-a, z});
    mask.push_back({-a, -z});
    }
  }
set <pll> s;
for (auto i:mask)
  s.insert(i);
mask.clear();
for (auto i:s)
  mask.push_back(i);
}

ll work(pll p)
{
ll lans=0;
for (auto del:mask)
  {
  pll point={p.F+del.F, p.S+del.S};
  auto z=lower_bound(v.begin(), v.end(), point);
  if (z!=v.end()&&(*z)==point)
    lans++;
  }
return lans;
}

void solve()
{
cin>>n>>r;
if (n==0&&r==0)
  exit(0);
m.clear();
v.clear();
build();
//viv=true;
if (viv)
  for (auto i:mask)
    cout<<i.F<<' '<<i.S<<endl;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  m.push_back({a, b});
  v.push_back({a, b});
  }
sort(v.begin(), v.end());
vector <ll> ans;
for (auto p:m)
  ans.push_back(work(p));

for (auto i:ans)
  cout<<i<<' ';
cout<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll a,b,c,d;
cin>>a>>b>>c>>d;
ll ans=1;
if (a!=d)
  ans=0;
if (!a&&c)
  ans=0;
cout<<ans;



    return 0;
}