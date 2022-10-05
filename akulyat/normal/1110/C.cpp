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

void work(ll a)
{
ll v=a;
vector <ll> m;
while (v)
  m.push_back(v&1), v>>=1;
ll kol=0;
for (auto i:m)
  kol+=(i==0);
if (kol)
  {
  for (auto &i:m)
    i=1;
  ll ans=0;
  for (auto i:m)
    ans<<=1, ans+=i;
  cout<<ans<<endl;
  return;
  }
for (ll i=2; i*i<=a; i++)
  if (a%i==0)
    {
    cout<<a/i<<endl;
    return;
    }
cout<<1<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
for (auto i:m)
  work(i);

    return 0;
}