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


ll n,i,j,a,b;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>a>>b;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }

for (i=0; i<n/2; i++)
  if (m[i]+m[n-1-i]==1)
    {
    cout<<-1;
    return 0;
    }

ll ans=0;
for (j=0; j<n/2; j++)
  {
  i=j;
  if (m[i]==2)
    {
    if (m[n-1-i]==0)
      ans+=a;
    if (m[n-1-i]==1)
      ans+=b;
    if (m[n-1-i]==2)
      ans+=min(a, b);
    }
  i=n-1-j;
  if (m[i]==2)
    {
    if (m[n-1-i]==0)
      ans+=a;
    if (m[n-1-i]==1)
      ans+=b;
    if (m[n-1-i]==2)
      ans+=min(a, b);
    }
  }
if (n&1)
  if (m[n/2]==2)
    ans+=min(a, b);


cout<<ans;






    return 0;
}