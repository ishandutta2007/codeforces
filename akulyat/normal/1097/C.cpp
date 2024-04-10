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


ll n,i,j,ans;
vector <pll> m;
map <ll, vector <ll> > mp;
bool viv=false;

pll work(string s)
{
ll now=0, mi=0;
for (auto i:s)
  {
  if (i=='(')
    now++;
  else
    now--;
  mi=min(mi, now);
  }
return {now, mi};
}

void zero()
{
ll i=0, j=(ll)mp[0].size()-1;
for (auto i:mp[0])
  if (i==0)
    ans++;
ans/=2;
}

void solve(ll v)
{
ll i=0;
ll lans=0;
for (auto i:mp[-v])
  if (i+v>=0)
    lans++;
lans=min(lans, (ll)mp[v].size());
ans+=lans;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  string a;
  cin>>a;
  m.push_back(work(a));
  if (m.back().S<m.back().F&&m.back().F<0||m.back().F>=0&&m.back().S<0)
    m.pop_back();
  }
for (auto p:m)
  {
  mp[p.F].push_back(p.S);
  }

for (ll i=-ml; i<ml; i++)
  if (mp[i].size())
    sort(mp[i].begin(), mp[i].end());
zero();
for (ll i=1; i<ml; i++)
  solve(i);
cout<<ans<<endl;




    return 0;
}