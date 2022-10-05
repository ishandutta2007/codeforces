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
ll a,b,ka=0,kb=0;
cin>>n>>a>>b;
ll n1=n;
while (n1>=0&&n1%b)
  ka++, n1-=a;
kb=n1/b;
if (n1<0)
  {
  cout<<-1;
  return 0;
  }

j=0;
while (ka)
  {
  for (i=j; i<j+a-1; i++)
    m.push_back(i+1);
  m.push_back(j);
  ka--;
  j+=a;
  }
while (kb)
  {
  for (i=j; i<j+b-1; i++)
    m.push_back(i+1);
  m.push_back(j);
  kb--;
  j+=b;
  }
for (auto i:m)
  cout<<i+1<<' ';






    return 0;
}