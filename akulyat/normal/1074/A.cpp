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


ll n,i,j,ans,m;
vector <ll> v;
vector <ll > g;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
if (m==0)
  {
  cout<<0;
  return 0;
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  v.push_back(a);
  }
sort(v.begin(), v.end());
v.push_back(ml*kk);
for (i=0; i<m; i++)
  {
  ll a,b,c;
  cin>>a>>b>>c;
  a--;
  if (a==0&&b==ml*kk)
    ans++;
  else
    if (a==0)
      g.push_back(b);
  }
if (n==0)
  {
  cout<<ans<<endl;
  return 0;
  }
sort(g.begin(), g.end());
ll j=0;
ll add=inf;
for (i=0; i<v.size(); i++)
  {
  ll p=v[i];
  while (j<g.size()&&g[j]<p)
    j++;
  add=min(add, g.size()-j+i);
  }
cout<<ans+add<<endl;







    return 0;
}