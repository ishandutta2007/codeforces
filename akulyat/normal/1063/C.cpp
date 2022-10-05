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

ll ask(ll x)
{
ll y=0;
cout<<x<<' '<<y<<endl;
string s;
cin>>s;
if (s[0]=='b')
  return 0;
else
  return 1;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
ll l=0;
ll r=mod-7;
ll t=ask(l);
n--;
if (!n)
  {
  cout<<1<<' '<<1<<' '<<1<<' '<<2<<endl;
  return 0;
  }


while (n)
  {
  ll mi=l+r>>1;
  ll nt=ask(mi);
  if (nt==t)
    l=mi;
  else
    r=mi;
  n--;
  }

cout<<l+2<<' '<<3<<' '<<l+1<<' '<<1<<endl;





























    return 0;
}