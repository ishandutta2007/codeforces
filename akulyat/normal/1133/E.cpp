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

ll n,i,j, ans, k;
ll dp[5*kk+10][5*kk+10];
vector <ll> m;
  bool viv=false;

void solve(ll num, ll kol)
{
ll v=m[num];
auto z=lower_bound(m.begin(), m.end(), v-5)-m.begin();
dp[num+1][kol]=dp[num][kol];
dp[num+1][kol]=max(dp[num+1][kol], dp[z][kol-1]+(num-z+1));
ans=max(ans, dp[num+1][kol]);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
sort(m.begin(), m.end());
for (ll i=0; i<n; i++)
  for (ll j=1; j<=k; j++)
    solve(i, j);
cout<<ans<<endl;





    return 0;
}