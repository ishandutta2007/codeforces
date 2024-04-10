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


ll n,i,j;
vector <ll> m;
bool viv=false;

void solve()
{
ll b, w;
bool rev=false;
cin>>b>>w;
if (b<w)
  swap(b, w), rev=true;
if (3*w+1<b||b+1<w)
  {
  cout<<"NO\n";
  return;
  }

vector <pll> ans;
ll x0=ml;
ll y0=ml;

ll x1=ml-1;
ll y1=ml;
ll c1=0;

ll x2=ml+1;
ll y2=ml;
ll c2=0;

ll x3=ml;
ll y3=ml+1;
ll c3=0;
while (w)
  {
  ans.push_back({x0, y0});
  w--;
  y0+=2;
  }
while (y3<y0&&b)
  {
  ans.push_back({x3, y3});
  b--;
  y3+=2;
  }
while (y2<y0&&b)
  {
  ans.push_back({x2, y2});
  b--;
  y2+=2;
  }
while (y1<y0&&b)
  {
  ans.push_back({x1, y1});
  b--;
  y1+=2;
  }
if (b)
  ans.push_back({ml, ml-1});


if (rev)
  for (auto &p:ans)
    p.S++;
cout<<"YES\n";
for (auto p:ans)
  cout<<p.F<<' '<<p.S<<'\n';
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