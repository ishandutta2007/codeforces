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


ll n,i,j,q,kol,l;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>q>>l;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
m.push_back(0);
for (i=0; i<n; i++)
  if (m[i]>l&&m[i+1]<=l)
    kol++;
while (q)
  {
  ll ty;
  cin>>ty;
  if (ty==1)
    {
    ll p,v;
    cin>>p>>v;
    p--;
    if (m[p]<=l&&m[p]+v>l)
      {
      if (p==0)
        {
        if (m[1]<=l)
          kol++;
        }
      else
        {
        if (m[p-1]<=l&&m[p+1]<=l)
          kol++;
        if (m[p-1]>l&&m[p+1]>l)
          kol--;
        }
      }
    m[p]+=v;
    }
  else
    cout<<kol<<'\n';
  q--;
  }




    return 0;
}