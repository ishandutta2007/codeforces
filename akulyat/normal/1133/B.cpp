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


ll n,i,j, k;
vector <ll> m;
bool viv=false;
ll kol[kk];

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  kol[a%k]++;
  }
ll ans=0;
for (ll i=0; i<k; i++)
  if ((2*i)%k)
      if (i<k-i)
        ans+=min(kol[i], kol[k-i]);
for (ll i=0; i<k; i++)
  if (!((2*i)%k))
    ans+=kol[i]/2;
ans*=2;
cout<<ans<<endl;




    return 0;
}