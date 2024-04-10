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


ll n,i,j, ans;
vector <ll> m;
bool viv=false;
multiset <ll> s;

void check(ll v)
{
ll lans=0;
for (ll i=0; i<6; i++)
  lans+=s.count(v+i);
ans=max(ans, lans);
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
sort(m.begin(), m.end());
ll i=0, j=0;
ll ans=0;
for (ll i=0; i<n; i++)
  {
  while (j<n&&m[j]-m[i]<=5)
    j++;
  ans=max(ans, j-i);
  }
cout<<ans<<endl;




    return 0;
}