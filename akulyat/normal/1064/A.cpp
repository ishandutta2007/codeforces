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
const long long mod=998244353;
const long long inf=ml*ml*ml+7;


ll n,i,j;
vector <pll> t;
set <ll> s;
map <ll, ll> kol;
bool viv=false;
ll pm,tmi,tma,m,ans;  

void solve()
{
ll tor=0;
srand(time(0));
for(ll j=0; j<10; j++)
  {
  tor*=10;
  tor+=rand()%10;
  }
srand(tor);
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll len=8*60;
ll l=1;
ll r=mod;
while(l+1<r)
  {
  ll k=l+r>>1;
  ld kol=0;
  ll bad=0;
  for (ll i=0; i<len; i++)
    {
    ll add=rand()%(pm+1);
    add=4;
    kol+=add;
    ll t=(rand()%(tma-tmi+1))+tmi;
    t=9;
    ld dt=((ld)kol*t)/k;
    if (dt>m)
      bad++;
    kol-=(ld)k/t;
    }
  if (bad<=len/20)
    r=k;
  else
    l=k;
  }
ans=max(ans, r);
}

int main()
{
vector <ll> m(3, 0);
for (i=0; i<3; i++)
  cin>>m[i];
sort(m.begin(), m.end());
cout<<max(0ll, m[2]-m[1]-m[0]+1);




    return 0;
}