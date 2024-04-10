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


ll n,i,j,k;
vector <ll> m;
bool viv=false;


int main()
{
cin>>n>>k;

ll a=3*k;
a=min(a, n);
a-=k;
if (k==0)
  a=0;

ll b=1;
if (k==n||k==0)
  b=0;


cout<<b<<' '<<a;





    return 0;
}