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
n=6;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }

ll sp=0;
for (auto i:m)
  sp+=i;
for (i=0; i<64; i++)
  {
  ll j=i;
  ll sum=0;
  vector <ll> b;
  for (ll u=0; u<6; u++)
    {
    sum+=(j&1);
    b.push_back(j&1);
    j/=2;
    }
  ll p=0;
  for (ll u=0; u<6; u++)
    if (b[u])
      p+=m[u];
  if (sum==3&&p*2==sp)
    {
    cout<<"YES"<<endl;
    return 0;
    }
  }

cout<<"NO"<<endl;


    return 0;
}