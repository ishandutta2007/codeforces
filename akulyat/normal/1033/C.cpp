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
vector <ll> m,p,ans;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
p.resize(n);
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  m.push_back(a);
  p[a]=i;
  }

for (i=0; i<n; i++)
  ans.push_back(-1);
for (i=n-1; i>=0; i--)
  {
  ll pl=p[i]-i-1;
  while (pl>=0)
    {
    if (ans[m[pl]]==1)
      ans[i]=0;
    pl-=(i+1);
    }
  pl=p[i]+i+1;
  while (pl<n)
    {
    if (ans[m[pl]]==1)
      ans[i]=0;
    pl+=(i+1);
    }
  if (ans[i]==-1)
    ans[i]=1;
  }
vector <ll> rans(n, 0);
for (i=0; i<n; i++)
  if (ans[i]==1)
    rans[p[i]]=1;

for (auto i:rans)
  cout<<char('A'+i);

    return 0;
}