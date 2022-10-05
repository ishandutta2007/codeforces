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
const ld eps=1e-12;


ll n,i,j;
vector <ll> m1, m2;
bool viv=false;


bool cmp(pll a, pll b)
{
if ((a.F*b.S<=b.F*a.S)^(b.S<0)^(a.S<0))
  return true;
return false;
}

bool same(pll a, pll b)
{
if (a.F*b.S==b.F*a.S)
  return true;
return false;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m1.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m2.push_back(a);
  }
ll ans=0;
vector <pll> v;
for (ll i=0; i<n; i++)
  {
  if (m1[i]==0&&m2[i]==0)
    ans++;
  if (m1[i]!=0)
    v.push_back({m2[i], m1[i]});
  }
sort(v.begin(), v.end(), cmp);
vector <ll> len;
if (v.size())
  len.push_back(1);
for (ll i=1; i<v.size(); i++)
  {
  len.push_back(1);
  if (same(v[i], v[i-1]))
    len[i]+=len[i-1];
  }
if (len.size())
  ans+=*max_element(len.begin(), len.end());
cout<<ans<<endl;



    return 0;
}