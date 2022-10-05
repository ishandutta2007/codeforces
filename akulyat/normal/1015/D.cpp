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


ll n,i,j,k,s;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k>>s;
if (s<k)
  {
  cout<<"NO";
  return 0;
  }
if (s>(n-1)*k)
  {
  cout<<"NO";
  return 0;
  }
cout<<"YES"<<endl;
ll p=1;
for (i=0; i<k; i++)
  {
  ll z=n-1;
  z=min(z, s-(k-i-1) );
  if (p+z<=n)
    p+=z;
  else
    p-=z;
  s-=z;
  cout<<p<<' ';
  }





    return 0;
}