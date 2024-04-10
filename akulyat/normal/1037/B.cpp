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


ll n,i,j,s;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>s;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
sort(m.begin(), m.end());
ll p=n/2;
ll ans=0;
if (m[p]<=s)
  {
  while (p<n)
    {
    ans+=max(s-m[p], 0ll);
    p++;
    }
  cout<<ans;
  return 0;
  }
while (p>=0)
  {
  ans+=max(m[p]-s, 0ll);
  p--;
  }
cout<<ans<<endl;




    return 0;
}