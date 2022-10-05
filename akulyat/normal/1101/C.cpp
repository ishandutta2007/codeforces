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
vector <pll> m,p;
bool viv=false;

void solve()
{
cin>>n;
m.clear();
p.clear();
for (ll i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  m.push_back({a, b});
  p.push_back({a, b});
  }
sort(m.begin(), m.end());
ll v=-1;
ll last=-1;
for (ll i=0; i<n; i++)
  {
  if (i&&m[i].F>last)
    v=last, i=n;
  last=max(last, m[i].S);
  }
if (v==-1)
  {
  cout<<-1<<endl;
  return;
  }
for (ll i=0; i<n; i++)
  if (p[i].S<=v)
    cout<<1<<' ';
  else
    cout<<2<<' ';
cout<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t)
  solve(), t--;

    return 0;
}