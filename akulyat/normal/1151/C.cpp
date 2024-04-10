#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j, l, r, ans;
vector <ull> st;
vector <ull> from[2];
bool viv=false;


ll between(ll l, ll r)
{
//viv=true;
if (viv)
  cout<<"Summa "<<l<<' '<<r<<'=';
l%=(2*mod);
r%=(2*mod);
if (l>r)
  r+=2*mod;
if (viv)
  cout<<" :Get "<<l<<' '<<r<<": ";
ll kol=(r-l)/2+1;
ll sum=(ull)l*kol+(ull)((r-l)*(ull)kol)/2;
if (viv)
  cout<<sum<<' ';
sum%=mod;
if (viv)
  cout<<sum<<endl;
viv=false;
return sum;
}

void prepare()
{
ll cur=0;
ull b=1;
ll ty=1;
from[0].push_back(1);
from[1].push_back(1);
for (ll i=0; i<63; i++)
  {
  st.push_back(b);
  from[ty].push_back(from[ty].back()+b/2);
  ty^=1;
  b*=2;
  }
if (viv)
  {
  for (ll i=0; i<5; i++)
    cout<<from[0][i]<<' ';
  cout<<endl;
  for (ll i=0; i<5; i++)
    cout<<from[1][i]<<' ';
  cout<<endl;
  }
}

ll work(ll l, ll r)
{
ll ty=1;
ll counter=1;
ll ans=0;
for (ll i=0; i<st.size()-3; i++)
  {
//  viv=true;
  if (viv)
    cout<<"From "<<st[i]<<endl;
  if (l>=st[i]&&l<st[i+1]&&r>=st[i+1])
    {
    ll f=from[ty][counter];
    f+=(l-st[i])*2;
    ll las=from[ty][counter+1]-2;
    ans+=between(f, las);
    ans%=mod;
    }
  if (r>=st[i]&&r<st[i+1]&&l<st[i])
    {
    ll f=from[ty][counter];
    ll las=from[ty][counter+1];
    las-=2*(st[i+1]-r);
    ans+=between(f, las);
    ans%=mod;
    }
  if (l<st[i]&&r>=st[i+1])
    {
    ll f=from[ty][counter];
    ll las=from[ty][counter+1]-2;
    ans+=between(f, las);
    ans%=mod;
    }
  if (l>=st[i]&&r<st[i+1])
    {
    ll f=from[ty][counter];
    f+=(l-st[i])*2;
    ll las=from[ty][counter+1];
    las-=(st[i+1]-r)*2;
    ans+=between(f, las);
    ans%=mod;
    }
  ty^=1;
  if (i&1)
    counter++;
  }
return ans;
}

void checker()
{
vector <ll> ch[2];
for (ll i=1; i<50*ml; i+=2)
  ch[1].push_back(i);
for (ll i=2; i<50*ml; i+=2)
  ch[0].push_back(i);
reverse(ch[0].begin(), ch[0].end());
reverse(ch[1].begin(), ch[1].end());
ll b=1;
ll ty=1;
vector <ll> v;
for (ll i=0; i<22; i++)
  {
  for (ll j=0; j<b; j++)
    v.push_back(ch[ty].back()), ch[ty].pop_back();
  b*=2;
  ty^=1;
  }

ll con=2*ml;
for (ll i=1+con; i<200+con; i++)
  for (ll j=i+con; j<200+con; j++)
    {
    ll v1=work(i, j);
    ll v2=0;
    for (ll u=i; u<=j; u++)
      v2+=v[u-1];
    if (v1!=v2)
      cout<<i<<' '<<j<<' '<<v1<<' '<<v2<<endl;
    }




}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>l>>r;
prepare();
cout<<work(l, r)<<endl;
/*
cout<<work(inf-7, inf-7)<<endl;
cout<<work(inf-8, inf-7)<<endl;
cout<<work(inf-9, inf-7)<<endl;
cout<<work(inf-9, inf-8)<<endl;
cout<<work(inf-9, inf-9)<<endl;
*/

//checker();

if (viv)
  for (ll i=0; i<10; i++)
    for (ll j=i; j<10; j++)
      {
      cout<<i+1<<' '<<j+1<<": ";
      cout<<work(i+1, j+1);
      cout<<endl;
      }







    return 0;
}
/**




**/