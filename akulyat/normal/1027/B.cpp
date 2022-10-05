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


ll n,i,j,q;
vector <ll> m;
bool viv=false;


void solve(ll x, ll y)
{
if (!((x+y)&1))
  {
  ll ans=0;
  ans+=x*n;
  ans+=y;
  ans/=2;
  ans++;
  cout<<ans<<'\n';
//  cout<<ans<<endl;
  }
else
  {
  y--;
  ll ans=0;
  ans+=x*n;
  ans+=y;
  ans/=2;
  ans++;
  ans+=((n*n)/2);
  if (!(n&1))
    if (x&1)
      ans++;
  if (n&1)
    ans++;
  cout<<ans<<'\n';
//  cout<<ans<<endl;
  }

}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>q;
for (i=0; i<q; i++)
  {
  ll a,b;
  cin>>a>>b;
  a--; b--;
  solve(a, b);
  }


    return 0;
}