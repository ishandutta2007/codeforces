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


ll n,i,j,P,t,T,m;
bool viv=false;

bool work(ll k)
{
ll len=480;
ld n=0;
ll bad=0;
for (ll i=0; i<len; i++)
  {
  n+=rand()%P;
  ll time=rand()%(T-t+1)+t;
  ld wait=((ld)n/k)*time;
  n-=(ld)k/time;
  n=max(n, (ld)0);
  if (wait>m)
    bad++;
  }
if (20*bad>len)
  return false;
return true;
}

void bins()
{
ll l=0;
ll r=ml;

while (l+1<r)
  {
  ll mi=l+r>>1;
  ll tries=ml/1000;
  bool norm=true;
  while (tries&&norm)
    norm=work(mi), tries--;
  if (norm)
    r=mi;
  else
    l=mi;
  }
cout<<"Binary search say: ";
cout<<r<<endl;
}

void some()
{
cout<<"For some:"<<endl;
for (ll j=7; j<=9; j++)
  {
  ll will=ml/10;
  ll tries=will;
  ll good=0;
  while (tries)
    good+=work(j), tries--;
  cout<<j<<" terminals "<<good<<" of "<<will<<" is "<<((ld)good/will)*100<<"%\n";
  }
}



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll a,b;
cin>>a>>b;
ll l=abs(a-b);
ll k=l/2;
ll ans=k*(k+1)/2;
ans+=(l-k)*(l-k+1)/2;
cout<<ans<<endl;








    return 0;
}