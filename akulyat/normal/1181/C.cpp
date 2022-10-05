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


ll n,i,j, m, ans;
bool viv=false;
vector <string> f;
vector <unordered_set <ll>> p;

ll h(ll a, ll b, ll s1, ll s2, ll s3)
{
s1-='a';
s2-='a';
s3-='a';
return (((((a*1000)+b)*100+s1)*100+s2)*100+s3);
}

void spliter()
{
for (ll lev=0; lev<m; lev++)
  {
  ll cur=1;
  vector <ll> have;
  for (ll i=1; i<n; i++)
    {
    if (f[i][lev]!=f[i-1][lev])
      have.push_back(cur), cur=0;
    cur++;
    }
  have.push_back(cur);
  if (viv)
    {
    cout<<"Kuski"<<endl;
    for (auto i:have)
      cout<<i<<' ';
    cout<<endl;
    }
  ll pref=have[0];
  unordered_set <ll> var;
  for (ll i=1; i<have.size()-1; i++)
    {
    if (have[i-1]>=have[i]&&have[i+1]>=have[i])
      var.insert(h(pref, pref+have[i], f[pref-1][lev], f[pref][lev], f[pref+have[i]][lev]));
    pref+=have[i];
    }
  p.push_back(var);
  }
if (viv)
  {
  for (ll i=0; i<m; i++)
    {
    for (auto j:p[i])
      cout<<j<<' ';
    cout<<endl;
    }
  }
}

void solve()
{
for (ll i=0; i<m; i++)
  {
  for (auto j:p[i])
    {
    ll las=i;
    while (las<m-1&&p[las+1].find(j)!=p[las+1].end())
      {
      las++;
      p[las].erase(j);
      }
    las-=i;
    las++;
    ans+=las*(las+1)/2;
    }
  }
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
bool need=false;
for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  if (need)
    s+='#';
  f.push_back(s);
  }
if (need)
  {
  string s;
  for (ll i=0; i<m+1; i++)
    s+='#';
  f.push_back(s);
  }
spliter();
solve();
cout<<ans<<endl;




    return 0;
}