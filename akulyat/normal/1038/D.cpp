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
ll ans=0;
ll bz=0;
ll mz=0;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  if (a>0)
    bz++;
  if (a<0)
    mz++;
  ans+=abs(a);
  m.push_back(a);
  }

if (bz!=n&&mz!=n)
  {
  cout<<ans;
  return 0;
  }



if (n==1)
  {
  cout<<m[0];
  return 0;
  }

ll mi=inf;
for (auto i:m)
  mi=min(mi, abs(i));
ans-=2*mi;
cout<<ans;










    return 0;
}