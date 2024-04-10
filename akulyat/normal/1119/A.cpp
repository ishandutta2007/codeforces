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
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
ll l=0;
ll r=n-1;
if (m[l]!=m[r])
  {
  cout<<n-1;
  return 0;
  }
while (m[l]==m[l+1])
  l++;
while (m[r]==m[r-1])
  r--;
ll ans=max(r, n-1-l);
ans--;
cout<<ans<<endl;







    return 0;
}