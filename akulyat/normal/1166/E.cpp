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


ll n, l, i,j;
vector <bitset <10000>> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>l;
m.resize(n);
for (i=0; i<n; i++)
  {
  ll l;
  cin>>l;
  for (ll j=0; j<l; j++)
    {
    ll a;
    cin>>a;
    a--;
    m[i][a]=1;
    }
  }
for (ll i=0; i<n; i++)
  for (ll j=0; j<n; j++)
    if ((m[i]&m[j])==0)
      {
      cout<<"impossible"<<endl;
      exit(0);
      }
cout<<"possible"<<endl;




    return 0;
}