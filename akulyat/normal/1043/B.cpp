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
vector <ll> m,ans;
bool viv=false;

void work(ll k)
{
vector <ll> x(k, -inf);
for (i=1; i<=n; i++)
  {
  ll z=m[i]-m[i-1];
  ll p=(i-1+k)%k;
  if (x[p]==-inf)
    x[p]=z;
  if (x[p]!=z)
    return;
  }
ans.push_back(k);
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
m.push_back(0);
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }

for (ll i=1; i<=n; i++)
  work(i);
cout<<ans.size()<<endl;
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;

    return 0;
}