#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
ifstream in;
ofstream out;

ll n,i,j;
vector <ll> m;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
ll ma=m[0];
ll mi=m[0];
ll ans=0;
for (auto i:m)
  {
  if (i>ma)
    ans++;
  if (i<mi)
    ans++;
  mi=min(mi, i);
  ma=max(ma, i);
  }
cout<<ans;


    return 0;
}