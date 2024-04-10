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
long m[1000];
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll k;
  cin>>k;
  for (j=0; j<k; j++)
    {
    ll a;
    cin>>a;
    m[a]++;
    }
  }
ll ans=0;
for (i=1; i<=100; i++)
  if (m[i]==n)
    cout<<i<<' ';


    return 0;
}