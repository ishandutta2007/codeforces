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


ll n,i,j,k,s;
vector <ll> m,ans;
bool viv=false;


int main()
{
cin>>n>>k;
ll kol=0;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  s+=a;
  m.push_back(s);
  ll now=s/k;
  ans.push_back(now-kol);
  kol=now;
  }

for (auto i:ans)
  cout<<i<<' ';





    return 0;
}