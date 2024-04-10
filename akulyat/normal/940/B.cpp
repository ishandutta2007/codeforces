#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j,k,a,b;
vector <ll> m;

int main()
{
cin>>n>>k>>a>>b;
long long ans=0;
if (k==1)
  {
  cout<<(n-1)*a;
  return 0;
  }
while (n!=1)
  {
  if (n%k==0)
    {
    ll raz=n-(n/k);
    n/=k;
    ans+=min(b, raz*a);
    }
  else
    {
    ll raz=n%k;
    n-=raz;
    ans+=a*raz;
    if (n==0)
      {
      n++;
      ans-=a;
      }
    }
  }

cout<<ans;

    return 0;
}