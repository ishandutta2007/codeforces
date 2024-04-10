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
vector <ll> m[10];
bool viv=false;

ll f(ll x)
{
ll r=1;
while (x)
  {
  if (x%10)
    r*=(x%10);
  x/=10;
  }
return r;
}

ll g(ll x)
{
if (x<10)
  return x%9;
return g(f(x));
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
for (i=1; i<ml+1; i++)
  m[g(i)].push_back(i);
cin>>n;
for (i=0; i<n; i++)
  {
  ll l,r,k;
  cin>>l>>r>>k;
  k%=9;
  ll a=upper_bound(m[k].begin(), m[k].end(), r)-m[k].begin();
  ll b=lower_bound(m[k].begin(), m[k].end(), l)-m[k].begin();
  cout<<a-b<<endl;
  }






    return 0;
}