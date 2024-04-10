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
set <ll> s;
ll ans;
vector <vector <ll> > kol;

bool check(ll a, ll b)
{
if (a<0||b<0||a>=n||b>=n)
  return false;

if (kol[a].empty())
  return true;
if (kol[b].empty())
  return true;

ll p1=kol[a][0];
ll p2=kol[b].back();

//cout<<a<<' '<<b<<' '<<p1<<' '<<p2<<endl;
if (p1>p2)
  return true;
return false;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (ll i=0; i<n; i++)
  s.insert(i);
kol.resize(n);
for (i=0; i<k; i++)
  {
  ll a;
  cin>>a;
  a--;
  m.push_back(a);
  s.erase(a);
  kol[a].push_back(i);
  }
ans=s.size();
for (ll i=0; i<n; i++)
  if (check(i, i+1))
    ans++;
for (ll i=0; i<n; i++)
  if (check(i, i-1))
    ans++;

cout<<ans<<endl;



    return 0;
}