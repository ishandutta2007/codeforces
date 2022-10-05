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


ll n,i,j,k;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>k>>n;
vector <ll> kol(k, 0);
ll now=0;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  kol[a]++;
  if (kol[a]==1)
    now++;
  if (now==k)
    {
    cout<<1;
    for (ll i=0; i<k; i++)
      {
      kol[i]--;
      if (kol[i]==0)
        now--;
      }
    }
  else
    cout<<0;
  }


    return 0;
}