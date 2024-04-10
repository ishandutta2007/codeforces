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
vector <ll> m;
bool viv=false;


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
reverse(m.begin(), m.end());
for (ll i=1; i<n; i++)
  {
  m[i]=min(m[i], m[i-1]-1);
  if (m[i]<0)
    m[i]=0;
  }
ll ans=0;
for (auto i:m)
  ans+=i;
 cout<<ans<<endl;




    return 0;
}