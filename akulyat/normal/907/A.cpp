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
ll a,b,c,d;
cin>>a>>b>>c>>d;
n=400;
for (i=1; i<n; i++)
  for (j=1; j<i; j++)
    for (ll u=1; u<j; u++)
      {
      bool good=true;
      if (a>i||b>j||c>u)
        good=false;
      if (2*a<i||2*b<j||2*c<u)
        good=false;
      if (d>i||d>j||d>u)
        good=false;
      if (2*d>=i||2*d>=j||2*d<u)
        good=false;
      if (good)
        {
        cout<<i<<'\n'<<j<<'\n'<<u<<endl;
        return 0;
        }

      }
cout<<-1;

    return 0;
}