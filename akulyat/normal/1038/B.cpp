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
if (n<=2)
  {
  cout<<"No";
  return 0;
  }
if (n>=3)
  {
  cout<<"Yes"<<endl;
  if (n&1)
    {
    ll z=n;
    cout<<1<<' '<<z<<endl;
    cout<<n-1<<' ';
    for (i=1; i<=n; i++)
      if (i!=z)
        cout<<i<<' ';
    }
  else
    {
    ll z=n;
    cout<<2<<' '<<1<<' '<<z<<endl;
    cout<<n-2<<' ';
    for (i=2; i<=n; i++)
      if (i!=z)
        cout<<i<<' ';
    }
  }








    return 0;
}