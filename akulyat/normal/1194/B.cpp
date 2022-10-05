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

void solve()
{
ll n, m;
cin>>n>>m;
vector <string> s;
s.resize(n);
for (auto &i:s)
  cin>>i;
vector <ll> str(n);
vector <ll> col(m);
for (ll i=0; i<n; i++)
  for (ll j=0; j<m; j++)
    if (s[i][j]=='.')
      str[i]++,
      col[j]++;
ll ans=inf;
for (ll i=0; i<n; i++)
  for (ll j=0; j<m; j++)
    {
    ll lans=str[i]+col[j];
    if (s[i][j]=='.')
      lans--;
    ans=min(ans, lans);
    }
cout<<ans<<endl;
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