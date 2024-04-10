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
const long long inf=mod;


ll n,i,j, ans, x;
vector <ll> m, lt, rt, lll, rrr;

bool viv=false;
ll good;

void prepare()
{
lt.resize(x, inf);
rt.resize(x, -1);
for (ll i=0; i<n; i++)
  {
  ll val=m[i];
  lt[val]=min(lt[val], i);
  rt[val]=max(rt[val], i);
  }

for (ll i=0; i<x; i++)
  lll.push_back(lt[i]);
good=inf;
for (ll i=x-1; i>=0; i--)
  {
  if (i!=x-1&&good==inf)
    if (rt[i]>lll[i+1])
      good=i+1;
  if (i!=x-1)
    lll[i]=min(lll[i], lll[i+1]);
  }
if (good==inf)
  good=0;
if (viv)
  cout<<"Our good="<<good<<endl;
for (ll i=0; i<x; i++)
  rrr.push_back(rt[i]);
for (ll i=1; i<x; i++)
  rrr[i]=max(rrr[i], rrr[i-1]);

if (viv)
  {
  for (auto i:lll)
    cout<<i<<' ';
  cout<<endl;
  for (auto i:rrr)
    cout<<i<<' ';
  cout<<endl;
  }
}

void write()
{
cout<<ans<<endl;
exit(0);
}

bool check(ll l, ll r)
{
if (r<good-1)
  return false;
if (viv)
  cout<<"Check "<<l<<' '<<r<<endl;
if (l==0||r==x-1||rrr[l-1]<=lll[r+1])
  return true;
if (viv)
  cout<<"Sorry, false"<<endl;
return false;

}

void solve(ll l)
{
if (l>1&&lt[l-1]<rrr[l-2])
  write();
ll lr=l-1;
ll rr=x;
while (lr+1<rr)
  {
  ll mr=lr+rr>>1;
  if (check(l, mr))
    rr=mr;
  else
    lr=mr;
  if (viv)
    cout<<"Ok "<<lr<<' '<<rr<<endl;
  }
if (viv)
  cout<<l<<" means "<<rr<<endl;
ans+=(x-rr);
}




int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>n>>x;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  m.push_back(a);
  }
prepare();
for (ll i=0; i<x; i++)
  solve(i);

write();






    return 0;
}