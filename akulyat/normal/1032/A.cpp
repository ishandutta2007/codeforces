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
map <ll, ll> mp;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll k;
cin>>n>>k;
ll z=0;
ll kol=0;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  mp[a]++;
  z=max(z, mp[a]);
  if (mp[a]==1)
    kol++;
  }
if (z%k)
  z/=k, z++, z*=k;
kol*=z;
cout<<kol-n;


    return 0;
}