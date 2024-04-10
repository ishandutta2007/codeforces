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


ll n,i,j, q, ma;
vector <ll> m;
vector <pll> gt;
vector <ll> ost;
bool viv=false;

void prepare()
{
ll t=1;
ll cur=0;
for (ll i=0; i<ml; i++)
  {
  ll v1=m[cur];
  ll v2=m[t];
  gt.push_back({v1, v2});
  m.push_back(min(v1, v2));
  if (max(v1, v2)==ma)
    {
    for (ll j=t+1; j<t+n; j++)
      ost.push_back(m[j]);
    return;
    }
  if (v2>v1)
    cur=t;
  t++;
  }
}

pll solve()
{
ll num;
cin>>num;
num--;
if (num<gt.size())
  return gt[num];
num-=gt.size();
ll v1=ma;
num%=ost.size();
ll v2=ost[num];
return {v1, v2};
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>q;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
ma=*max_element(m.begin(), m.end());
prepare();
while (q)
  {
  auto p=solve();
  q--;
  cout<<p.F<<' '<<p.S<<'\n';
  }
if (viv)
  {
  for (auto i:gt)
    cout<<i.F<<' '<<i.S<<"; ";
  cout<<endl;
  for (auto i:ost)
    cout<<i<<' ';
  cout<<endl;
  }

    return 0;
}