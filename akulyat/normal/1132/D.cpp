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


ll n,i,j, l;
vector <ll> st,d;
bool viv=false;

bool can(ll p)
{
ll kol=0;
vector <ll> need(l);
for (ll i=0; i<n; i++)
  {
  ll t=0;
  ll val=st[i];
  while (t<l-1)
    {
    ll spend=(val)/d[i];
    val-=spend*d[i];
    if (viv)
      cout<<"from "<<t<<" to "<<t+spend<<endl;
    t+=spend;
    if (t<l-1)
      {
      kol++;
      if (kol>l)
        return false;
      val+=p;
      need[t]++;
      }
    }
  }
for (ll i=1; i<l; i++)
  need[i]+=need[i-1];
for (ll i=0; i<l; i++)
  if (need[i]>i+1)
    return false;
return true;
}


ll solve()
{
ll l=-1;
ll r=1;
ll con=inf;
while (!can(r)&&r<con)
  r<<=1;
if (viv)
  cout<<l<<' '<<r<<endl;
if (r>=con)
  return -1;
while (l+1<r)
  {
  ll mi=l+r>>1;
  if (can(mi))
    r=mi;
  else
    l=mi;
  if (viv)
    cout<<l<<' '<<r<<endl;
  }
return r;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>l;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  st.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  d.push_back(a);
  }
cout<<solve();



    return 0;
}