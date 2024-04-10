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


ll n,i,j, k;
vector <ll> m;
bool viv=false;

void solve()
{
cin>>n>>k;
m.clear();
m.resize(n);
for (auto &i:m)
  cin>>i;

vector <ll> ans;
ll sum=0;
for (ll i=0; i<n; i++)
  {
  sum+=m[i];
  if (sum&1)
    ans.push_back(i+1), sum=0;
  }
if (ans.empty())
  {
  cout<<"NO\n";
  return;
  }
if (ans.back()!=n)
  ans.back()=n;
if (abs(ans.size()-k)&1||ans.size()<k)
  {
  cout<<"NO\n";
  return;
  }
cout<<"YES\n";
reverse(ans.begin(), ans.end());
while (ans.size()>k)
  ans.pop_back();
reverse(ans.begin(), ans.end());
for (auto i:ans)
  cout<<i<<' ';
cout<<'\n';
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t--)
  solve();

    return 0;
}