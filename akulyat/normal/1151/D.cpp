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
vector <pair <ll, pll>> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll v1, v2;
  cin>>v1>>v2;
  m.push_back({v2-v1, {v1, v2}});
  }
sort(m.begin(), m.end());
ll ans=0;
for (ll i=0; i<n; i++)
  ans+=(i)*m[i].S.F, ans+=(n-i-1)*m[i].S.S;
cout<<ans<<endl;





    return 0;
}