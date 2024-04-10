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

long long solve(ll x, ll y, ll n)
{
if (max(x, y)>n)
  return -1;
x%=2;
y%=2;
return n-abs(n%2-x)-abs(n%2-y);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b,c;
  cin>>a>>b>>c;
  cout<<solve(a, b, c)<<'\n';
  }


    return 0;
}