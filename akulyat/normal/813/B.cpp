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


ll n,i,j,x,y,l,r;
vector <ll> m;
bool viv=false;

ll power(ll a, ll b)
{
ll v=1;
for (ll i=0; i<b; i++)
  v*=a;
return v;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>x>>y>>l>>r;
m.push_back(l-1);
m.push_back(r+1);
for (i=0; i<=60; i++)
  for (j=0; j<60; j++)
    {
    ld z=pow(x, i)+pow(y, j);
    if (z<inf)
      {
      ll z=power(x, i)+power(y, j);
      if (l<=z&&z<=r)
        m.push_back(z);
      }
    }
sort(m.begin(), m.end());
ll ans=0;
for (i=1; i<m.size(); i++)
  ans=max(ans, m[i]-m[i-1]-1);
cout<<ans;

    return 0;
}