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


ll n,i,j,s2,s1;
vector <ll> m;
bool viv=false;


int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  s1+=a;
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  s2+=a;
  }
if (s1>=s2)
  cout<<"Yes";
else
  cout<<"No";

    return 0;
}