#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const ll K=20;

ll n,i,j, q;
vector <ll> m;
vector <vector <ll>> dp;
bool viv=false;

vector <bool> split(ll val)
{
vector <bool> res;
for (ll i=0; i<K; i++)
  res.push_back(val&1), val>>=1;
return res;
}

void prepare()
{
vector <ll> near(K, -1);
dp.resize(n);
for (auto &v:dp)
  v.resize(K, n);
for (ll i=n-1; i>=0; i--)
  {
  if (viv)
    cout<<"Work "<<i<<endl;
  ll val=m[i];
  auto b=split(val);
  for (j=0; j<K; j++)
    if (b[j]&&near[j]!=-1)
      {
      dp[i][j]=near[j];
      for (ll u=0; u<K; u++)
        dp[i][u]=min(dp[i][u], dp[near[j]][u]);
      }
  for (ll j=0; j<K; j++)
    if (b[j])
      near[j]=i;
  }
if (viv)
  cout<<"That's all"<<endl;
}

void print()
{
if (!viv)
  return;
for (ll i=0; i<n; i++)
  {
  cout<<i<<" that's "<<m[i]<<": ";
  for (ll j=0; j<2; j++)
    cout<<dp[i][j]<<' ';
  cout<<endl;
  }
}

bool solve()
{
ll l, r;
cin>>l>>r;
l--, r--;
auto b=split(m[r]);
for (ll j=0; j<K; j++)
  if (b[j]&&dp[l][j]<=r)
    return true;
return false;
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>q;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
prepare();
print();
vector <ll> ans;
while (q)
  ans.push_back(solve()), q--;

for (auto i:ans)
  if (i)
    cout<<"Shi\n";
  else
    cout<<"Fou\n";


    return 0;
}