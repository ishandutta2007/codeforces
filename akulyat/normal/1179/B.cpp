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


ll n,i,j, m;
vector <pll> ans;
bool viv=false;

void pr(ll l1)
{
ll l2=n-1-l1;
for (ll i=0; i<m; i++)
  {
  ans.push_back({l1, i});
  ans.push_back({l2, m-1-i});
  }
}

void line(ll l1)
{
vector <ll> all, rall;
for (ll i=0; i<m; i++)
  all.push_back(i);
for (ll i=0; i<m; i++)
  rall.push_back(m-1-i);
for (ll i=0; i<m; i++)
  if (i&1)
    ans.push_back({l1, all.back()}), all.pop_back();
  else
    ans.push_back({l1, rall.back()}), rall.pop_back();
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (ll i=0; i<n; i++)
  {
  if (2*i+1==n)
    line(i);
  if (2*i+1<n)
    pr(i);
  }
for (auto p:ans)
  cout<<p.F+1<<' '<<p.S+1<<'\n';


    return 0;
}