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


ll n,i,j, was, good;
vector <ll> m;
set <ll> s;
bool viv=false;

vector <long long> erat(long long last)
{
vector <bool> bad;
vector <long long> r;
for (long long i=0; i<last+10; i++)
  bad.push_back(true);
for (long long i=2; i<=last; i++)
  if (bad[i])
    {
    long long j=2;
    while (j*i<=last)
      {
      bad[j*i]=false;
      j++;
      }
    r.push_back(i);
    }
return r;
}

void solve(ll n)
{
vector <pll> ans;
for (ll i=0; i<n-1; i++)
  ans.push_back({i, i+1});
ans.push_back({n-1, 0});
if (!s.count(ans.size()))
  {
  for (ll i=0; i<n/2; i++)
    {
    ans.push_back({i, i+n/2});
    if (s.count(ans.size()))
      i=ml;
    }
  }
cout<<ans.size()<<endl;
for (auto i:ans)
  cout<<i.F+1<<' '<<i.S+1<<endl;
was+=1;
if (s.count(ans.size()))
  good++;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
auto p=erat(10*kk);
for (auto i:p)
  s.insert(i);
solve(n);
return 0;

for (ll i=3; i<=1000; i++)
  solve(i);
if (viv)
  cout<<was<<' '<<good<<endl;


    return 0;
}