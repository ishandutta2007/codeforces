#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j,k;
vector <pll> m;
vector <ll> t;
bool viv=false;


int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back({a, i});
  }
k=min(k, n);
sort(m.begin(), m.end());
ll ans=0;
for (i=0; i<k; i++)
  {
  ans+=m.back().F;
  t.push_back(m.back().S);
  m.pop_back();
  }
t.push_back(-1);
sort(t.begin(), t.end());
t.back()=n-1;
cout<<ans<<endl;
for (i=0; i<k; i++)
  cout<<t[i+1]-t[i]<<' ';






    return 0;
}