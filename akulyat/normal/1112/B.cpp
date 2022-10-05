#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

const ll kk=1000;
const ll ml=kk*kk;
const ll mod=ml*kk+7;
const ll inf=ml*ml*ml+7;

vector <ll> m;
ll i,j,u,n,k, nex, was, ans;
bool viv=false;
vector <bool> nice;
set <pair <pll, ll> > s;

void check()
{
ll d=100*was;
ll wd=d;
d/=n;
if (2*(wd%n)>=n)
  d++;
for (auto p:s)
  {
  ll t=p.F.S-p.F.F+1;
  if (t==d)
    {
//    cout<<
    nice[p.S]=true;
    }
  }
}


void work()
{
set <pair <pll, ll> > s2;
for (auto p:s)
  {
  if (p.F.F-1)
    s2.insert({{p.F.F-1, p.F.S}, p.S});
  else
    was++;
  }
s=s2;
while (s.size()<k&&nex<n)
  {
  s.insert({{m[nex], m[nex]}, nex});
  nex++;
  }
check();
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
nice.resize(n, false);
for (ll i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
while (s.size()||nex<n)
  work();
ans=0;
for (auto i:nice)
  ans+=i;
cout<<ans<<endl;



    return 0;
}