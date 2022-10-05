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
const long long con=15*ml;
const long long scon=5*kk;

ll n,k,l,r,i,j,ans,kol;
vector <ll> m;
bool viv=false;

void work(ll x)
{
if (x<0||x>n)
  return;
ll lk=k;
lk%=(n+x);
if (lk==0)
  lk=n+x;
if (lk<kol)
  return;
if (lk>kol*2)
  return;
if (lk==kol*2)
  lk--;
ll slad=(n-kol)+(lk-kol+1);
if (slad>=x)
  ans=max(ans, x);
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>l>>r>>k;
kol=(r+n+1-l)%n;
if (kol==0)
  kol=n;

ans=-1;
for (i=0; i<con; i++)
  work(n-i);
if (ans!=-1)
  {cout<<ans; return 0;}
for (i=0; i<con; i++)
  work(i);


for (i=0; i<ml/10; i++)
  {
  ll x;
 /*
  ll lk=k-((n+x)*i);
  lk=kol+(x-n+kol);
  2*kol+x-n=k-i*n-i*x;
  x*(i+1)=k-i*n-2*kol+n;
// */
  x=(n+k-i*n-2*kol)/(i+1);
  for (ll j=-10; j<10; j++)
    work(x+j);
  }




cout<<ans;

    return 0;
}