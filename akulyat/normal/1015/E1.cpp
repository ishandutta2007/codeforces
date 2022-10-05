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

struct mine
{
  ll a,b,l;
};

ll n,i,j,m;
vector <mine> ans;
vector <ll> p[kk];
bool can[kk][kk];
bool viv=false;

void create(ll i, ll j, ll l)
{
for (ll u=0; u<=l; u++)
  {
  can[i+u][j]=true;
  can[i-u][j]=true;
  can[i][j-u]=true;
  can[i][j+u]=true;
  }
}

void work(ll i, ll j)
{
if (p[i][j]==0)
  return;
ll best=0;
for (ll l=1; l<max(n, m); l++)
  {
  ll kol=0;
  if (i-l>=0)
    if (p[i-l][j]==1)
      kol++;
  if (i+l<n)
    if (p[i+l][j]==1)
      kol++;
  if (j-l>=0)
    if (p[i][j-l]==1)
      kol++;
  if (j+l<m)
    if (p[i][j+l]==1)
      kol++;
  if (kol==4)
    if (best+1==l)
      best++;
  }
if (best!=0)
  {
  create(i, j, best);
  ans.push_back({i, j, best});
  }
}


int main()
{
cin>>n>>m;
for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  for (j=0; j<m; j++)
    {
    if (s[j]=='*')
      p[i].push_back(1);
    else
      p[i].push_back(0);
    }
  }

for (i=0; i<n; i++)
  for (j=0; j<m; j++)
    work(i, j);


for (i=0; i<n; i++)
  for (j=0; j<m; j++)
    if (p[i][j]==1)
      if (!can[i][j])
        {
        cout<<-1<<endl;
        return 0;
        }
/*
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    cout<<can[i][j];
  cout<<endl;
  }
*/
cout<<ans.size()<<endl;

for (i=0; i<ans.size(); i++)
  {
  cout<<ans[i].a+1<<' ';
  cout<<ans[i].b+1<<' ';
  cout<<ans[i].l<<endl;
  }


    return 0;
}