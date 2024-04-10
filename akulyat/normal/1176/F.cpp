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
//const long long inf=999;


ll n,i,j;
vector <vector <ll>> m, dp, ma;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
m.resize(n);
ma.resize(n);
for (i=0; i<n; i++)
  {
  ll k;
  cin>>k;
  vector <ll> f[3];
  for (ll j=0; j<k; j++)
    {
    ll p, v;
    cin>>p>>v;
    p--;
    f[p].push_back(v);
    }
  for (ll j=0; j<3; j++)
    for (ll u=0; u<3; u++)
      f[j].push_back(-inf/10);
  for (ll j=0; j<3; j++)
    sort(f[j].rbegin(), f[j].rend());

  ll can[3]={-inf/10, -inf/10, -inf/10};
  can[0]=max(can[0], f[2][0]);
  can[0]=max(can[0], f[1][0]);
  can[0]=max(can[0], f[0][0]);
      ma[i].push_back(can[0]);

  can[1]=max(can[1], f[0][0]+f[1][0]);
  can[1]=max(can[1], f[0][0]+f[0][1]);
      ma[i].push_back(max(f[0][0], f[1][0]));

  can[2]=max(can[2], f[0][0]+f[0][1]+f[0][2]);
      ma[i].push_back(f[0][0]);

  for (ll j=0; j<3; j++)
    m[i].push_back(max(can[j], (ll)-1));
  }

dp.resize(n+1);
for (auto &v:dp)
  v.resize(10, -1);
dp[0][0]=0;
for (ll i=0; i<n; i++)
  {
  for (ll was=0; was<10; was++)
    if (dp[i][was]!=-1)
      {
      ll val=dp[i][was];
      dp[i+1][was]=max(dp[i+1][was], val);
      for (ll j=0; j<3; j++)
        {
        ll ost=(was+j+1)%10;
        ll nval=val+m[i][j];
        if (m[i][j]!=-1)
          {
          if (was<=9&&was>=6&&ost>=0&&ost<=3)
            nval+=ma[i][j];
          dp[i+1][ost]=max(dp[i+1][ost], nval);
          }
        }
      }
  }

if (viv)
  for (ll i=0; i<n+1; i++)
    {
    for (ll j=0; j<10; j++)
      cout<<dp[i][j]<<' ';
    cout<<endl;
    }

ll ans=0;
for (auto i:dp[n])
  ans=max(ans, i);
cout<<ans<<endl;



    return 0;
}
/**
9
2
2 1
2 2
2
2 1
2 2
2
2 1
2 2
2
2 1
2 2
2
2 1
2 2
2
2 1
2 2
2
2 1
2 2
2
2 1
2 2
1
1 100





**/