#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j,k,p;
vector <ll> m,l,r;
map <ll, ll> mpl,mpr;

int main()
{
cin>>n>>k;
k--;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  if (a==k)
    p=i;
  m.push_back(a);
  }

r.push_back(0);
for (i=p+1; i<n; i++)
  {
  r.push_back(r.back());
  if (m[i]>k)
    r.back()++;
  else
    r.back()--;
  mpr[r.back()]=0;
  }
for (auto i:r)
  mpr[i]++;
l.push_back(0);
for (i=p-1; i>=0; i--)
  {
  l.push_back(l.back());
  if (m[i]>k)
    l.back()++;
  else
    l.back()--;
  mpl[l.back()]=0;
  }
for (auto i:l)
  mpl[i]++;

ll ans=0;
for (auto i:r)
  {
  ll v=i;
  if (mpl.find(-v)!=mpl.end())
    ans+=mpl[-v];
  v--;
  if (mpl.find(-v)!=mpl.end())
    ans+=mpl[-v];
  }

cout<<ans;


    return 0;
}