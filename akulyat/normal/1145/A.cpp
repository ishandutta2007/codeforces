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
vector <ll> m, kol;
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
  kol.push_back(1);
  }
for (ll i=1; i<n; i++)
  if (m[i]>=m[i-1])
    kol[i]+=kol[i-1];
ll ans=1;
for (ll i=0; i<n; i++)
  {
  ll num=i+1;
  if (!(num&(num-1)))
    {
    for (ll i=0; i<n; i+=num)
      if (kol[i+num-1]>=num)
        ans=num;
    }
  }
cout<<ans<<endl;



    return 0;
}