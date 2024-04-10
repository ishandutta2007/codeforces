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


ll n,i,j,k;
vector <pll> m;
vector <ll> p;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  p.push_back(a);
  m.push_back({a, i});
  }
sort(m.begin(), m.end());
vector <ll> ans;
ans.assign(n, 0);
for (ll i=0; i<n; i++)
  {
  ans[m[i].S]=i%k;
  }

for (ll i=0; i<n; i++)
  for (ll j=i+1; j<n; j++)
    if (p[i]==p[j]&&ans[i]==ans[j])
      {
      cout<<"NO";
      return 0;
      }
cout<<"YES"<<endl;
for (auto i:ans)
  cout<<i+1<<' ';




    return 0;
}