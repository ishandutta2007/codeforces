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
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>l>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  m.push_back(a);
  }
ll ans=m.back()-m[0]+1;
vector <ll> v;
for (ll i=0; i<n-1; i++)
  v.push_back(m[i+1]-m[i]-1);
sort(v.rbegin(), v.rend());
k--;
for (ll i=0; i<k; i++)
  ans-=v[i];
cout<<ans<<endl;









    return 0;
}