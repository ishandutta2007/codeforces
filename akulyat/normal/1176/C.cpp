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
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  if (a==4)
    a=0;
  else
    if (a==23)
      a=4;
  if (a==8)
    a=1;
  if (a==15)
    a=2;
  if (a==16)
    a=3;
  if (a==42)
    a=5;
  m.push_back(a);
  }
vector <ll> kol;
kol.resize(7);
kol[0]=ml;
for (ll i=0; i<n; i++)
  {
  if (kol[m[i]])
    kol[m[i]]--,
  kol[m[i]+1]++;
  }
cout<<n-kol[6]*6;







    return 0;
}