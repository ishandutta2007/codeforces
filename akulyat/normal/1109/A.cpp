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
vector <ll> m,pr;
bool viv=false;
map <pll, ll> mp;



void build()
{
pr.push_back(0);
for (auto i:m)
  pr.push_back(pr.back()^i);
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
build();
for (ll i=0; i<pr.size(); i++)
  mp[{pr[i], i&1}]++;
ll ans=0;
for (auto i:mp)
  ans+=(i.S*(i.S-1))/2;
cout<<ans<<endl;





    return 0;
}