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
vector <pll> p;

void use(ll k)
{
ll ans=0;
for (ll i=0; i<n; i++)
  {
  ll d=abs(k-m[i]);
  if (d)
    d--;
  ans+=d;
  }
p.push_back({ans, k});
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
for (ll i=1; i<=100; i++)
  use(i);
sort(p.begin(), p.end());
cout<<p[0].S<<' '<<p[0].F<<endl;






    return 0;
}