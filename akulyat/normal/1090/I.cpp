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
long long mod;
const long long inf=4*(1e18)+1;


ll n,l,r,x,y,z,b1,b2;
bool viv=false;

vector <ull> buildb()
{
cin>>n>>l>>r>>x>>y>>z>>b1>>b2;
vector <ull> b;
b.push_back(b1);
b.push_back(b2);
for (ll i=2; i<n; i++)
  {
  ull v1=b[i-2]*x;
  ull v2=b[i-1]*y;
  ull v3=z;
  v1%=mod; v2%=mod; v3%=mod;
  ull v=v1+v2+v3;
  v%=mod;
  b.push_back(v);
  }
if (viv)
  {
  cout<<"B ";
  for (auto i:b)
    cout<<i<<' ';
  cout<<endl;
  }
return b;
}

vector <ll> builda()
{
vector <ull> b=buildb();
vector <ll> a;
for (auto i:b)
  {
  i%=(r-l+1);
  i+=l;
  a.push_back(i);
  }
if (viv)
  {
  cout<<"A ";
  for (auto i:a)
    cout<<i<<' ';
  cout<<endl;
  }
return a;
}

void write(ll ans)
{
if (ans==inf)
  {
  cout<<"IMPOSSIBLE"<<endl;
  return;
  }
cout<<ans<<endl;
}

ll find(vector <ll> a)
{
ll mi=inf;
ll r=inf;
for (auto i:a)
  {
  mi=min(i, mi);
  if (mi<i)
    r=min(r, mi*i);
  }
return r;
}

void solve()
{
vector <ll> a=builda();
ll was=false;
ll ans=inf;
ans=min(ans, find(a));
reverse(a.begin(), a.end());
for (auto &i:a)
  i*=-1;
ans=min(ans, find(a));
write(ans);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mod=1;
for (ll i=0; i<32; i++)
  mod<<=1;
ll t;
cin>>t;
while (t)
  {
  solve();
  t--;
  }

    return 0;
}