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


ll n,i,j,m;
vector <vector <ll>> a,b;
vector <ll> r,c;
bool viv=false;

void bad()
{
cout<<"No";
exit(0);
}
void good()
{
cout<<"Yes";
exit(0);
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
r.resize(n);
c.resize(m);
for (i=0; i<n; i++)
  for (ll j=0; j<m; j++)
    {
    ll v;
    cin>>v;
    r[i]^=v;
    c[j]^=v;
    }
for (i=0; i<n; i++)
  for (ll j=0; j<m; j++)
    {
    ll v;
    cin>>v;
    r[i]^=v;
    c[j]^=v;
    }
for (auto i:r)
  if (i)
    bad();
for (auto i:c)
  if (i)
    bad();
good();




    return 0;
}