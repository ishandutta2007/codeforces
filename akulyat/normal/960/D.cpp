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


ll n,i,j,q;
vector <ll> m;
vector <ll> kol,st,r;
bool viv=false;

void sdvig(ll ur, ll sdv)
{
sdv%=kol[ur];
r[ur]+=sdv;
while (r[ur]>st[ur+1])
  r[ur]-=kol[ur];
}

void work(ll ur, ll pl)
{
ll z=r[ur]+pl;
while (z>=st[ur+1])
  z-=kol[ur];
cout<<z<<' ';
if (ur>0)
  work (ur-1, pl/2);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
kol.push_back(1);
for (i=1; i<=61; i++)
  kol.push_back(kol.back()*2);
for (auto i:kol)
  st.push_back(i);
for (auto i:kol)
  r.push_back(i);



cin>>q;
for (ll u=0; u<q; u++)
  {
  ll t;
  cin>>t;
  if (t==1)
    {
    ll v,sdv;
    cin>>v>>sdv;
    ll ur=0;
    while (st[ur+1]<=v)
      ur++;
    sdv%=kol[ur];
    if (sdv<0)
      sdv+=kol[ur];
    sdv=-sdv+kol[ur];
    sdvig(ur, sdv);
    }
  if (t==2)
    {
    ll v,sdv;
    cin>>v>>sdv;
    ll ur=0;
    while (st[ur+1]<=v)
      ur++;
    sdv%=kol[ur];
    if (sdv<0)
      sdv+=kol[ur];
    sdv=-sdv+kol[ur];
    while (ur<=60)
      sdvig(ur, sdv), sdv*=2, ur++;
    }
  if (t==3)
    {
    ll v;
    cin>>v;
    ll ur=0;
    while (st[ur+1]<=v)
      ur++;
    ll pl=v-st[ur];
    pl-=r[ur]-st[ur];
    if (pl<0)
      pl+=kol[ur];
    work(ur, pl);
    cout<<endl;
    }
/*
  cout<<"Real ";
  for (i=0; i<6; i++)
    cout<<r[i]<<' ';
  cout<<endl;
*/
  }
    return 0;
}