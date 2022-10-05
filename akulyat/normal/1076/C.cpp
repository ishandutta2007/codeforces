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

pair <ld, ld> solve(ll d)
{
ll r=d*d-4*d;
if (r<0)
  return {-10, -10};
ld a=((ld)d+sqrt(r))/2.0;
return {a, (ld)d-a};
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
cout.precision(20);
while (t)
  {
  ll a;
  cin>>a;
  pair <ld, ld> d=solve(a);
  if (d.F<-1)
    {
    cout<<'N'<<'\n';
    }
  else
    cout<<'Y'<<' '<<fixed<<d.F<<' '<<d.S<<'\n';
  t--;
  }
    return 0;
}