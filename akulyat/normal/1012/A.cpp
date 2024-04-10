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
cin>>n;
for (i=0; i<2*n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
sort(m.begin(), m.end());

ll ans=4*inf;
ans=min(ans, (m[n-1]-m[0])*(m[2*n-1]-m[n]));
for (i=1; i<n; i++)
  {
  ans=min(ans, (m[n-1+i]-m[i])*(m[2*n-1]-m[0]));
  }
cout<<ans;

    return 0;
}