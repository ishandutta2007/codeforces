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


ll n,i,j, ans, k;
vector <ll> m;
vector <vector <ll>> can;
bool viv=false;

void work(ll val)
{
ll kol=0;
while (val)
  {
  can[val].push_back(kol);
  val/=2;
  kol++;
  }
}

void check(ll val)
{
sort(can[val].begin(), can[val].end());
if (can[val].size()>=k)
  {
  ll lans=0;
  for (ll i=0; i<k; i++)
    lans+=can[val][i];
  ans=min(ans, lans);
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
can.resize(300*kk);
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  work(a);
  m.push_back(a);
  }
ans=100*ml;
for (ll i=0; i<300*kk; i++)
  check(i);
cout<<ans<<endl;
    return 0;
}