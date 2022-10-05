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

void solve(ll a, ll b)
{
ll ans=0;
  {
  ll l=a;
  ll r=b;
  if (!(l&1))
    l++;
  if (!(r&1))
    r--;
  if (l<=r)
    ans-=(l+r)*(r-l+2)/4;
  }
  {
  ll l=a;
  ll r=b;
  if (l&1==1)
    l++;
  if (r&1==1)
    r--;
  if (l<=r)
    ans+=(l+r)*(r-l+2)/4;
  }
cout<<ans<<endl;

}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a, b;
  cin>>a>>b;
  solve(a, b);
  }


    return 0;
}