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


ll n,i,j, m, ans;
vector <vector <bool>> can, dp, dp2;
bool viv=false;

void counter()
{
dp.resize(n+2);
for (auto &v:dp)
  v.resize(m+2);
dp[1][1]=1;
for (ll i=1; i<n+1; i++)
  for (ll j=1; j<m+1; j++)
    if (can[i-1][j-1]&&!dp[i][j])
      {
      dp[i][j]=dp[i][j]|dp[i][j-1],
      dp[i][j]=dp[i][j]|dp[i-1][j];
      }

dp2.resize(n+2);
for (auto &v:dp2)
  v.resize(m+2);
dp2[n][m]=1;
for (ll i=n; i>0; i--)
  for (ll j=m; j>0; j--)
    if (can[i-1][j-1]&&!dp2[i][j])
      {
      dp2[i][j]=dp2[i][j]|dp2[i][j+1],
      dp2[i][j]=dp2[i][j]|dp2[i+1][j];
      }

vector <ll> sum(n+m+5, 0);
for (ll i=1; i<n+1; i++)
  for (ll j=1; j<m+1; j++)
    {
    if (dp[i][j]&&dp2[i][j])
      sum[i+j]++;
    }
for (ll i=3; i<n+m; i++)
  ans=min(ans, sum[i]);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<n; i++)
  {
  can.push_back({});
  string a;
  cin>>a;
  for (auto j:a)
    if (j=='.')
      can.back().push_back(1);
    else
      can.back().push_back(0);
  }
ans=ml;
counter();
cout<<ans<<endl;



    return 0;
}
/**
4 4
.#..
#.#.
....
.#..

4 4
....
..##
....
.#..

4 4
..ff
..##
ff..
f#..

4 4
..ff
..##
f...
f#..

4 4
...f
...#
f...
f...





**/