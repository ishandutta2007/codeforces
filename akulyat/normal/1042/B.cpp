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
vector <ll> best(8, inf);
for (i=0; i<n; i++)
  {
  ll a;
  string s;
  cin>>a>>s;
  ll t=0;
  if (s.find('A')!=4294967295)
    t+=4;
  if (s.find('B')!=4294967295)
    t+=2;
  if (s.find('C')!=4294967295)
    t+=1;
  best[t]=min(best[t], a);
  }

ll ans=inf;
for (i=1; i<8; i++)
  for (j=1; j<8; j++)
    for (ll u=1; u<8; u++)
      {
      ll kol=0;
      if ((i/1)&1||(j/1)&1||(u/1)&1)
        kol++;
      if ((i/2)&1||(j/2)&1||(u/2)&1)
        kol++;
      if ((i/4)&1||(j/4)&1||(u/4)&1)
        kol++;
      ll lans=0;
      lans+=best[i];
      if (j!=i)
        lans+=best[j];
      if (u!=i&&u!=j)
        lans+=best[u];
      if (kol==3)
        ans=min(ans, lans);
      }
if (ans>ml*10)
  ans=-1;

cout<<ans;




    return 0;
}