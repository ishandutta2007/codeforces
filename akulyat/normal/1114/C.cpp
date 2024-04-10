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


ll n,k,i,j;
vector <pll> m;
bool viv=false;

vector <pll> parse(ll n)
{
vector <pll> r;
for (ll i=2; i<ml+10; i++)
  if (!(n%i))
    {
    r.push_back({i, 0});
    ll kol=0;
    while (!(n%i))
      r.back().S++, n/=i;
    }
if (n-1)
  r.push_back({n, 1});
return r;
}

ll work(ll ch, ll kol)
{
ll lans=0;
ll N=n;
while (N)
  {
  lans+=N/ch;
  N/=ch;
  }
lans/=kol;
//cout<<ch<<' '<<kol<<' '<<lans<<endl;
return lans;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
m=parse(k);
ll ans=inf;
for (auto i:m)
  ans=min(ans, work(i.F, i.S));
cout<<ans<<endl;

    return 0;
}