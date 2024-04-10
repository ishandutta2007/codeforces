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


ll n,i,j,x;
vector <ll> m;
bool viv=false;
map <ll, ll> mp,mp2;

int main()
{
cin>>n>>x;
for (i=0; i<100000; i++)
  mp[i]=0;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  mp[a]++;
  if (mp[a]==2)
    {
    cout<<0;
    exit(0);
    }
  }
bool have=false;
for (i=0; i<=100000; i++)
  if (mp[i]!=0)
    if ((i&x)!=i)
    {
    if (mp[i&x]!=0)
      {
//      cout<<i<<' '<<(i&x)<<endl;
      cout<<1;
      exit(0);
      }
    else
      {
      mp2[i&x]++;
      if (mp2[i&x]!=1)
        have=true;
      }
    }
if (have)
  {
  cout<<2;
  return 0;
  }
cout<<-1;
    return 0;
}