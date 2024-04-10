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
vector <ll> m;
bool viv=false;

bool bad(vector <ll> m)
{
n=m.size()/2;
ll ans=0;
while (m.size()>n)
  ans+=m.back(), m.pop_back();
while (m.size())
  ans-=m.back(), m.pop_back();
return (ans==0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<2*n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
sort(m.begin(), m.end());
if (bad(m))
  swap(m[0], m[2*n-1]);
if (bad(m))
  {
  cout<<-1;
  return 0;
  }
for (ll i=0; i<2*n; i++)
  cout<<m[i]<<' ';

    return 0;
}