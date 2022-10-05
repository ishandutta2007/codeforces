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


ll n,i,j,t;
vector <ll> m;
bool viv=false;

void work()
{
ll a;
ll b;
cin>>a>>b;
if (a-1!=b)
  {
  cout<<"NO"<<'\n';
  return;
  }
ll ost=2*b+1;
for (i=2; i<(ll)ceil(sqrt(ost))+3; i++)
  if (i<ost)
    if (ost%i==0)
      {
      cout<<"NO"<<'\n';
      return;
      }
cout<<"YES"<<'\n';
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>t;
while (t)
  {
  work();
  t--;
  }

    return 0;
}