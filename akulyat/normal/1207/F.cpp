#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long    ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const ll con = 500;
const ll n = ml/2;

ll i,j, q;
vector <ll> m;
vector <vector <ll>> ost, o;
bool viv=false;

void prepare()
{
m.resize(n+1);
for (ll i=0; i<con; i++)
  {
  ost.push_back({});
  ost[i].resize(i+1);
  }
o.resize(con);
}

void work()
{
ll ty;
cin>>ty;
if (ty == 1)
  {
  ll pl, val;
  cin>>pl>>val;
  m[pl]+=val;
  for (ll i=1; i<con; i++)
    ost[i][pl%i]+=val;
  }
else
  {
  ll x, y;
  cin>>x>>y;
  ll ans=0;
  if (x>=con)
    {
    if (y==0)
      y=x;
    while (y<=n)
      ans+=m[y], y+=x;
    }
  else
    {
    ans=ost[x][y];
    }
  cout<<ans<<endl;
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>q;
prepare();
while (q--)
  work();


    return 0;
}