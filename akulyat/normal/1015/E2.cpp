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
ll lm[kk][kk];
ll rm[kk][kk];
ll um[kk][kk];
ll dm[kk][kk];
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
best=min(min(lm[i][j], rm[i][j]), min(um[i][j], dm[i][j]));
if (best!=0)
  {
  create(i, j, best);
  ans.push_back({i, j, best});
  }
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
  {
  lm[i][0]=p[i][0];
//  um[i][0]=p[i][0];
  }
for (j=0; j<m; j++)
  {
//  lm[0][j]=p[0][j];
  um[0][j]=p[0][j];
  }
for (i=0; i<n; i++)
  {
  rm[i][m-1]=p[i][m-1];
//  dm[i][m-1]=p[i][m-1];
  }
for (j=0; j<m; j++)
  {
//  rm[n-1][j]=p[n-1][j];
  dm[n-1][j]=p[n-1][j];
  }

for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    {
    if (j>0)
      {
      lm[i][j]=p[i][j];
      if (lm[i][j])
        lm[i][j]+=lm[i][j-1];
      }
    if (i>0)
      {
      um[i][j]=p[i][j];
      if (um[i][j])
        um[i][j]+=um[i-1][j];
      }
    }
  }
for (i=n-1; i>=0; i--)
  {
  for (j=m-1; j>=0; j--)
    {
    if (j<m-1)
      {
      rm[i][j]=p[i][j];
      if (rm[i][j])
        rm[i][j]+=rm[i][j+1];
      }
    if (i<n-1)
      {
      dm[i][j]=p[i][j];
      if (dm[i][j])
        dm[i][j]+=dm[i+1][j];
      }
    }
  }
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    if (p[i][j])
      {
      lm[i][j]--;
      rm[i][j]--;
      um[i][j]--;
      dm[i][j]--;
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
 /*
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    cout<<lm[i][j];
  cout<<endl;
  }
// */
 /*
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    cout<<rm[i][j];
  cout<<endl;
  }
// */
cout<<ans.size()<<endl;

for (i=0; i<ans.size(); i++)
  {
  cout<<ans[i].a+1<<' ';
  cout<<ans[i].b+1<<' ';
  cout<<ans[i].l<<endl;
  }


    return 0;
}