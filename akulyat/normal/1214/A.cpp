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


ll n,i,j, d, e;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>d>>e;
ll ans=n;
for (ll se=0; se<min((100*ml)/30+10, 400ll); se+=5)
  {
  ll r=se*e;
  ll ost=n-r;
  if (ost>=0)
    {
    ost%=d;
    ans=min(ans, ost);
    }
  }
for (ll se=max(0ll, (n/e-1000)/5*5); se<(n/e+1000)/5*5; se+=5)
  {
  ll r=se*e;
  ll ost=n-r;
  if (ost>=0)
    {
    ost%=d;
    ans=min(ans, ost);
    }
  }
cout<<ans<<endl;



    return 0;
}