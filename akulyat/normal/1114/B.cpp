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


ll n,i,j,l,k;
vector <pll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>l>>k;
ll kol=l*k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back({a, i});
  }
sort(m.rbegin(), m.rend());
vector <ll> v;
ll ans=0;
for (ll i=0; i<kol; i++)
  v.push_back(m[i].S), ans+=m[i].F;
sort(v.begin(), v.end());
cout<<ans<<endl;
for (ll i=l-1; i<kol-1; i+=l)
  cout<<v[i]+1<<' ';
cout<<endl;



    return 0;
}