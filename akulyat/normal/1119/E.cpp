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
ll ans=0;
ll have=0;
for (ll i=0; i<n; i++)
  {
  while (have<i&&m[i]>1)
    {
    if (m[have]&&m[i]>1)
      {
      m[have]--;
      m[i]-=2;
      ans++;
      }
    if (m[have]==0)
      have++;
    }

  ans+=m[i]/3;
  m[i]%=3;
  while (m[i]>1&&have<i)
    {
    if (m[have])
      {
      m[i]-=2;
      m[have]--;
      ans++;
      }
    if (m[have]==0)
      have++;
    }
  }
cout<<ans<<endl;




    return 0;
}