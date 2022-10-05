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
const long long inf=ml*ml*ml+7;


ll n,i,j, ans;
vector <vector <pll>> reb;
vector <ll> col, tc;
string s;
bool viv=false;
bool nor;

void DFS(ll v, ll c)
{
if (col[v]!=-1&&col[v]!=c)
  {
  nor=false;
  return;
  }
col[v]=c;
for (ll i=0; i<reb[v].size(); i++)
  {
  ll s=reb[v][i].F;
  ll nc=c^(reb[v][i].S);
  if (viv)
    cout<<"Ogo "<<s<<' '<<nc<<endl;
  if (col[s]!=nc)
    DFS(s, nc);
  }
}

void go(ll v, ll c)
{
if (tc[v]!=-1&&tc[v]!=c)
  {
  nor=false;
  return;
  }
tc[v]=c;
for (ll i=0; i<reb[v].size(); i++)
  {
  ll s=reb[v][i].F;
  ll nc=c^(reb[v][i].S);
  if (tc[s]!=nc)
    go(s, nc);
  }
}

void solve(ll k)
{
if (viv)
  cout<<"Check "<<k<<endl;
vector <ll> v1, v2;
reb.clear();
reb.resize((n+1)/2+(k+1)/2);
for (ll i=0; i<k; i++)
  if (s[i]!='?')
    {
    ll a=min(i, n-1-i);
    ll b=min(i, k-1-i);
    b+=(n+1)/2;
    if (viv)
      cout<<"Add "<<a<<' '<<b<<' '<<(s[i]-'0')<<' '<<reb.size()<<endl;
    reb[a].push_back({b, s[i]-'0'});
    reb[b].push_back({a, s[i]-'0'});
    }
col.clear();
col.resize((n+1)/2+(k+1)/2, -1);
col[0]=1;
col[(n+1)/2]=1;
for (ll i=k; i<n; i++)
  if (s[i]!='?')
    {
    ll a=min(i, n-1-i);
    ll ty=s[i]-'0';
    if (viv)
      cout<<"  Know that "<<a<<" is "<<ty<<endl;
    if (col[a]!=ty&&col[a]!=-1)
      return;
    col[a]=ty;
    }
if (viv)
  cout<<"Work "<<k<<endl;
nor=true;
if (viv)
  {
  cout<<"               ";
  for (auto i:col)
    cout<<i<<' ';
  cout<<endl;
  }
for (ll i=0; i<col.size(); i++)
  if (col[i]!=-1)
    DFS(i, col[i]);
tc.clear();
tc.resize(col.size(), -1);
for (ll i=0; i<tc.size(); i++)
  if (col[i]!=-1)
    tc[i]=1;
ll lans=1;
for (ll i=0; i<tc.size(); i++)
  if (tc[i]==-1)
    {
    if (viv)
      cout<<"check "<<i<<endl;
    go(i, 0), lans*=2, lans%=mod;
    }

if (viv)
  cout<<k<<" Add for me "<<lans<<endl;
if (!nor)
  lans=0;
if (viv)
  cout<<k<<" Add for me "<<lans<<endl;
ans+=lans;
ans%=mod;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;

cin>>s;
n=s.size();
reverse(s.begin(), s.end());
for (ll i=1; i<=n; i++)
  solve(i);
cout<<ans<<endl;






    return 0;
}