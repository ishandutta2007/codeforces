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

void solve()
{
ll k;
cin>>k;
k*=2;
ll ans=-1;
for (ll i=360; i>2; i--)
  if (360%i==0)
    {
    ll u=360/i;
    if (k%u==0)
      if (k+2*u<=360)
        ans=i;
    }
cout<<ans<<endl;

}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
while (n)
  solve(), n--;

    return 0;
}