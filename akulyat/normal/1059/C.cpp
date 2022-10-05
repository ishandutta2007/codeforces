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
ll k=1;
while (n)
  {
  if (n==3)
    {
    cout<<k<<' ';
    cout<<k<<' ';
    cout<<k*3<<' ';
    n=0;
    return 0;
    }
  ll l=n/2;
  for (i=0; i<n-l; i++)
    cout<<k<<' ';
  n=l;
  k*=2;
  }









    return 0;
}