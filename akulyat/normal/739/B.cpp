#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*kk+7;
ifstream in;
ofstream out;

ll n,i,j;
vector <ll> reb[ml];
vector <ll> m,add;
bool viv=false;
ll r[ml/4][kk/30];
ll len[ml/4][kk/30];
ll col[ml];

ll work(ll v, ll ost)
{
if (len[v][0]>ost)
  {
  add[v]--;
  return 0;
  }
ll j=0;
while (len[v][j+1]<=ost)
  j++;
return (1ll<<j)+work(r[v][j], ost-len[v][j]);
}

void DFS(ll v, ll c)
{
col[v]=c;
ll l=reb[v].size();
for (ll i=0; i<l; i++)
  {
  ll s=reb[v][i];
  DFS(s, c+1);
  }
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
for (i=1; i<n; i++)
  {
  ll pr, v;
  cin>>pr>>v;
  pr--;
  r[i][0]=pr;
  len[i][0]=v;
  reb[pr].push_back(i);
  }
for (j=0; j<30; j++)
  {
  r[0][j]=0;
  len[0][j]=inf;
  }
for (j=1; j<30; j++)
  {
  for (i=1; i<n; i++)
    {
    ll s=r[i][j-1];
    r[i][j]=r[s][j-1];
    len[i][j]=len[i][j-1]+len[s][j-1];
    }
  }

for (i=0; i<n; i++)
  add.push_back(1);
// /*
for (i=0; i<n; i++)
  work(i, m[i]);
// */

  /*
for (i=0; i<n; i++)
  cout<<work(i, m[i])<<' ';
cout<<endl;
for (auto i:add)
  cout<<i<<' ';
cout<<endl;
// */
DFS(0, 0);
vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());

vector <ll> ans(n);
for (auto i:tos)
  {
  ll v=i.S;
  ll l=reb[v].size();
  ll lans=0;
  for (j=0; j<l; j++)
    lans+=add[reb[v][j]];
  ans[v]=lans;
  add[v]+=lans;
  }
for (auto i:ans)
  cout<<i<<' ';

    return 0;
}