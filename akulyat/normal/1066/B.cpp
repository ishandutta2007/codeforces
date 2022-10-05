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


ll n,i,j,r;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>r;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  if (a)
    m.push_back(i+r-1);
  }
r=2*r-1;
if (m.empty()||m[0]>=r||m.back()<n-1)
  {
  cout<<-1;
  return 0;
  }
ll l=m.size();
vector <ll> ans(l, inf);
ll otv=inf;
for (i=0; i<l; i++)
  if (m[i]<=r-1)
    {
    ans[i]=1;
    if (m[i]>=n-1)
      otv=min(otv, ans[i]);
    }
for (i=0; i<l; i++)
  for (j=0; j<i; j++)
    if (m[i]-m[j]<=r)
      {
      ans[i]=min(ans[i], ans[j]+1);
      if (m[i]>=n-1)
        otv=min(otv, ans[i]);
      }
if (otv==inf)
  otv=-1;
cout<<otv<<endl;









    return 0;
}