#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j;
vector <ll> m;
bool viv=false;

ll solve(ll n)
{
if (n<5)
  return n*(n-1)/2;
ll z=1;
ll kol=0;
while (2*n-1>=10*z-1)
  {
  z*=10;
  kol++;
  }
ll ans=0;
for (ll i=0; i<9; i++)
  {
  ll v=z*(i+1)-1;
  ans+=min(max(n-v/2, 0ll), v/2);
//  cout<<v<<' '<<ans<<endl;
  }
return ans;
}

int main()
{
cin>>n;
//for (ll i=0; i<=n; i++)
//  cout<<solve(i)<<' ';
cout<<solve(n);


    return 0;
}