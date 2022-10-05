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
ll a,b;
cin>>a>>b;
ll l=-1;
ll r=mod;
while (l+1!=r)
  {
  ll m=l+r>>1;
  if (m*(m+1)/2<=a+b)
    l=m;
  else
    r=m;
  }
vector <ll> take;
for (i=0; i<l; i++)
  take.push_back(i+1);
reverse(take.begin(), take.end());
vector <ll> tof, tos;
for (auto i:take)
  {
  if (a>=i)
    tof.push_back(i), a-=i;
  else
    tos.push_back(i);
  }

cout<<tof.size()<<endl;
for (auto i:tof)
  cout<<i<<' ';
cout<<endl;
cout<<tos.size()<<endl;
for (auto i:tos)
  cout<<i<<' ';
cout<<endl;





    return 0;
}