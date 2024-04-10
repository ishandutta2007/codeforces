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


ll n,i,j,mi,k;
vector <ll> m;
bool viv=false;
long long kol[300*kk];

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
mi=inf;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  kol[a]++;
  mi=min(mi, a);
  m.push_back(a);
  }

ll have=0;
ll num=0;
ll ans=0;
for (i=250*kk; i>mi; i--)
  {
  if (have+kol[i]+num<=k)
    have+=(kol[i]+num), num+=kol[i];
  else
    {
    ans++;
    have=num;
    have+=kol[i];
    num+=kol[i];
    }
  }
if (have)
  ans++;
cout<<ans;
















    return 0;
}