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

ll dp[5*kk+10][5*kk+10];
ll n,i,j;
vector <ll> m;
bool viv=false;

vector <ll> nice(vector <ll> v)
{
vector <ll> r;
r.push_back(m[0]);
for (ll i=1; i<v.size(); i++)
  if (v[i]!=v[i-1])
    r.push_back(v[i]);
return r;
}

void work(ll x, ll y)
{
ll lans=dp[x][y-1]+1;;
lans=min(lans, dp[x-1][y]+1);
if (m[x-1]==m[n-y])
  lans=min(lans, dp[x-1][y-1]+1);
dp[x][y]=lans;
}

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
m=nice(m);
n=m.size();
for (ll i=0; i<n; i++)
  dp[0][i]=i,
  dp[i][0]=i;
/*
for (ll i=0; i<n; i++)
  for (ll j=1; j<i; j++)
    work(j, i-j);
*/
for (ll i=1; i<n; i++)
  for (ll j=1; j<n; j++)
    work(i, j);

ll ans=inf;
for (ll i=0; i<=n-1; i++)
  ans=min(ans, dp[i][n-1-i]);
cout<<ans<<endl;
if (viv)
  for (ll i=0; i<n; i++)
    {
    for (ll j=0; j<=i; j++)
      cout<<dp[j][i-j]<<' ';
    cout<<endl;
    }


    return 0;
}