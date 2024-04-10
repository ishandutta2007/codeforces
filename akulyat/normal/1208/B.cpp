#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j, big, ans;
vector <ll> m;
unordered_map <ll, ll> kol;
bool viv=false;

void from(ll l)
{
ll ost=big;
auto lkol=kol;
if (!ost)
  {
  ans=0;
  return;
  }
for (ll r=l; r<n; r++)
  {
  lkol[m[r]]--;
  if (lkol[m[r]]==1)
    ost--;
  if (!ost)
    {
    ans=min(ans, r-l+1);
    return;
    }
  }
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
  kol[a]++;
  if (kol[a]==2)
    big++;
  }
ans=n;
for (ll i=0; i<n; i++)
  from(i);
cout<<ans<<endl;

    return 0;
}