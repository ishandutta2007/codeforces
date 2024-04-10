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


ll n,i,j, h;
vector <ll> m;
bool viv=false;

bool cant(ll kol)
{
kol++;
vector <ll> v;
for (ll i=0; i<kol; i++)
  v.push_back(m[i]);
sort(v.begin(), v.end());
ll n=v.size();
v.push_back(0);
ll ans=0;
for (ll i=0; i<n; i+=2)
  ans+=max(v[i], v[i+1]);
//cout<<ans<<endl;
v.pop_back();
if (n&1)
  {
  ll lans=v[0];
  for (ll i=1; i<n; i+=2)
    lans+=max(v[i], v[i+1]);
  ans=min(ans, lans);
  }
//cout<<kol<<' '<<ans<<endl;
return (ans>h);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>h;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
for (ll i=0; i<n; i++)
  if (cant(i))
    {
    cout<<i;
    return 0;
    }
cout<<n<<endl;


    return 0;
}