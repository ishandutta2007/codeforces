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


ll n,i,j,a,b,k,h;
vector <ll> m;
bool viv=false;


int main()
{
cin>>n>>h>>a>>b>>k;
for (ll u=0; u<k; u++)
  {
  ll x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  if ((a<=y1&&y1<=b)||(a<=y2&&y2<=b)||(x1==x2))
    cout<<(abs(y1-y2)+abs(x1-x2))<<endl;
  else
    {
    if ((y1>b)^(y2>b))
      cout<<(abs(y1-y2)+abs(x1-x2))<<endl;
    else
      cout<<abs(x2-x1)+min(abs(y1-a)+abs(y2-a), abs(y1-b)+abs(y2-b))<<endl;
    }
  }






    return 0;
}