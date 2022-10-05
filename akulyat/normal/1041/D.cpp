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


ll n,i,j,h;
vector <pll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>h;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  m.push_back({a, b});
  }
sort(m.begin(), m.end());

vector <ll> kol;
kol.push_back(0);

for (i=1; i<n; i++)
  kol.push_back(kol.back()+m[i].F-m[i-1].S);

ll ans=-inf;
for (i=0; i<n; i++)
  {
  ll a=i;
  ll b=n;
  while (a+1!=b)
    {
    ll mi=a+b>>1;
    if (kol[mi]-kol[i]<h)
      a=mi;
    else
      b=mi;
    }
  ll lans=m[a].S-m[i].F+(h-kol[a]+kol[i]);
  ans=max(lans, ans);
//  cout<<i<<' '<<a<<' '<<lans<<endl;
  }

cout<<ans<<endl;









    return 0;
}