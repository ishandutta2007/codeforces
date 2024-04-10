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


ll n,i,j, m;
vector <ll> b, g;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  b.push_back(a);
  }
sort(b.begin(), b.end());
for (i=0; i<m; i++)
  {
  ll a;
  cin>>a;
  g.push_back(a);
  }
sort(g.begin(), g.end());

if (b.back()>g[0])
  {
  cout<<-1;
  exit(0);
  }
for (auto &i:g)
  i-=b.back();
ll ans=0;
for (auto i:b)
  ans+=i*m;
for (auto i:g)
  ans+=i;
if (g[0]!=0)
  ans+=(b[n-1]-b[n-2]);
cout<<ans<<endl;






    return 0;
}
/**
111
000

00
11
11

11
22
11

**/