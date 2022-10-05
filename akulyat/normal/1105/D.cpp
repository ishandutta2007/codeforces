#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long    ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <ll, pll> ppll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,m,p,i,j;
char t[kk+10][kk+10];
bool viv=false;
vector <ll> s;
vector <ppll> h[10];

void write()
{
vector <ll> kol(p, 0);
for (ll i=0; i<n; i++)
  for (ll j=0; j<m; j++)
    if (t[i][j]>='0'&&t[i][j]<='8')
      kol[t[i][j]-'0']++;
for (auto i:kol)
  cout<<i<<' ';
cout<<endl;
exit(0);
}

void add(ll x, ll y, ll col, ll v)
{
if (x<0||y<0)
  return;
if (x>=n||y>=m)
  return;
if (t[x][y]!='.')
  return;
t[x][y]=char('0'+v);
h[v].push_back({col, {x, y}});
}

void check(ll x, ll y, ll col, ll v)
{
//cout<<"check "<<x<<' '<<y<<endl;
if (col==s[v])
  return;
add(x+1, y, col+1, v);
add(x-1, y, col+1, v);
add(x, y+1, col+1, v);
add(x, y-1, col+1, v);
}

void work(ll v)
{
for (ll i=0; i<h[v].size(); i++)
  check(h[v][i].S.F, h[v][i].S.S, h[v][i].F, v);
reverse(h[v].begin(), h[v].end());
while (h[v].size()&&h[v].back().F==0)
  h[v].pop_back();
reverse(h[v].begin(), h[v].end());
for (auto &i:h[v])
  i.F=0;
}





int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>p;
s.resize(p);
for (auto &i:s)
  cin>>i;
for (i=0; i<n; i++)
  for (ll j=0; j<m; j++)
    {
    cin>>t[i][j];
    if (t[i][j]>='1'&&t[i][j]<='9')
      t[i][j]--;
    if (t[i][j]>='0'&&t[i][j]<='8')
      h[t[i][j]-'0'].push_back({(ll)0, {i, j}});
    }
while (true)
  {
  ll sum=0;
  for (ll i=0; i<p; i++)
    sum+=h[i].size(), work(i);
//  cout<<sum<<endl;
  if (!sum)
    write();
  }






    return 0;
}