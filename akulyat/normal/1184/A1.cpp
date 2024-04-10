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


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (ll x=1; x<ml*2; x++)
  {
  ll r=n;
  r--;
  r-=x;
  r-=x*x;
  if (!(r%(2*x)))
    {
    r/=2*x;
    if (r>0)
      {
      cout<<x<<' '<<r;
      exit(0);
      }
    }
  }
cout<<"NO";

    return 0;
}