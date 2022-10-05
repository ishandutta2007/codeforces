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
ll n,m;
cin>>n>>m;

cout<<max(n-2*m, 0ll)<<' ';
for (i=0; i<=n; i++)
  {
  if (i*(i-1)/2>=m)
    cout<<n-i<<' ', i=n;
  }

















    return 0;
}