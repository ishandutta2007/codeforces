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
const long long mod=998244353;
const long long inf=ml*ml*ml+7;


ll n,i,j;
vector <ll> m, l;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a*=(i+1)*(n-i);
  m.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  l.push_back(a);
  }
sort(m.begin(), m.end());
sort(l.rbegin(), l.rend());
ll ans=0;
for (ll i=0; i<n; i++)
  ans+=((m[i]%mod)*l[i])%mod;
ans%=mod;
cout<<ans<<endl;

    return 0;
}