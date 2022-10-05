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
vector <ll> m1,m2;
vector <pll> m;
bool viv=false;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
//  b++;
  m.push_back({a, b});
  m1.push_back(a);
  m2.push_back(b);
  }
sort(m1.begin(), m1.end());
sort(m2.begin(), m2.end());

ll ans=0;
for (auto i:m)
  {
  ll l=m1.back();
  ll r=m2[0];
  if (i.F==l)
    l=m1[n-2];
  if (i.S==r)
    r=m2[1];
  ans=max(ans, r-l);
  }

cout<<ans;








    return 0;
}