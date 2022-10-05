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


ll n,i,j,x,y;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>x>>y;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }

if (x>y)
  {
  cout<<n<<endl;
  return 0;
  }
ll kol=0;
for (ll i=0; i<n; i++)
  if (m[i]<=x)
    kol++;
kol=(kol+1)/2;
cout<<kol<<endl;



















    return 0;
}