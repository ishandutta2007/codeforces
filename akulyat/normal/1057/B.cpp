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
vector <ll> pr;
pr.push_back(0);
for (i=0; i<n; i++)
  pr.push_back(pr.back()+m[i]);
ll ans=0;
for (i=0; i<n+1; i++)
  for (j=0; j<i; j++)
    if (100*(i-j)<pr[i]-pr[j])
      ans=max(ans, i-j);
cout<<ans;

    return 0;
}