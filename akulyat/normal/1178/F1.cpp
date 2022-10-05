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
const long long mod=998244353;
//const long long inf=ml*ml*ml+7;


ll n,i,j, m;
vector <ll> p;
vector <vector <ll>> ans;
vector <vector <ll>> spans;
bool viv=false;

ll count(deque <ll> &p, ll l, ll r);

ll split(deque <ll> &p, ll l, ll r)
{
if (p.size()<=1)
  return 1;
//if (spans[l][r]!=-1)
//  return spans[l][r];

bool bc=false;
if (p.back()<p[0])
  bc=true;

deque <ll> a;
deque <ll> b;
if (bc)
  {
  for (ll i=0; i<(ll)p.size()-1; i++)
    b.push_back(p[i]);
  r--;
  }
else
  {
  for (ll i=1; i<p.size(); i++)
    b.push_back(p[i]);
  l++;
  }


ll n=b.size();
long long lans=0;
lans+=1ll*count(b, l, r);
lans%=mod;


for (ll i=0; i<n; i++)
  {
  a.push_front(b.back());
  b.pop_back();
  lans+=(long long)count(a, r-i, r)*(ll)count(b, l, r-i-1);
  lans%=mod;
  }

return lans;
}

ll count(deque <ll> &p, ll l, ll r)
{
if (p.size()<=1)
  return 1;
if (ans[l][r]!=-1)
  return ans[l][r];
ll mi=min_element(p.begin(), p.end())-p.begin();
deque <ll> a, b;

for (ll i=0; i<=mi; i++)
  a.push_back(p[i]);
long long v1=split(a, l, l+mi);

for (ll i=mi; i<p.size(); i++)
  b.push_back(p[i]);
long long v2=split(b, l+mi, r);

long long lans=(v1*v2)%mod;
ans[l][r]=lans;
return lans;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
ans.resize(n+3);
spans.resize(n+3);
for (auto &v:ans)
  v.resize(n+3, -1);
for (auto &v:spans)
  v.resize(n+3, -1);
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  p.push_back(a);
  }

deque <ll> d;
for (auto i:p)
  d.push_back(i);

cout<<count(d, 0, n-1);





    return 0;
}