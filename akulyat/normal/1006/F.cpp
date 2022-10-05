#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,m,r,i,j;
ll p[100][100];
map <ll, ll> mpd[30][30];
map <ll, ll> mpu[30][30];
set <ll> sd[30][30];
set <ll> su[30][30];
map <ll, ll> mp;
bool viv=false;


int main()
{
mp[0]=10;
mp[10]=6;
mp[239]=69;

cin>>n>>m>>r;
for (i=0; i<n; i++)
  for (j=0; j<m; j++)
    {
    ll a;
    cin>>a;
    p[i][j]=a;
    }

mpu[0][0][p[0][0]]=1;
su[0][0].insert(p[0][0]);
for (i=0; i<n; i++)
  for (j=0; j<m; j++)
    if (i+j<=n-1)
      {
      if (j>0)
        for (auto u:su[i][j-1])
          {
          mpu[i][j][u^p[i][j]]+=mpu[i][j-1][u];
          su[i][j].insert(u^p[i][j]);
          }
      if (i>0)
        for (auto u:su[i-1][j])
          {
          mpu[i][j][u^p[i][j]]+=mpu[i-1][j][u];
          su[i][j].insert(u^p[i][j]);
          }
      }
mpd[n-1][m-1][p[n-1][m-1]]=1;
sd[n-1][m-1].insert(p[n-1][m-1]);
for (i=n-1; i>=0; i--)
  for (j=m-1; j>=0; j--)
    if (i+j>=n-1)
      {
      for (auto u:sd[i][j+1])
        {
        mpd[i][j][u^p[i][j]]+=mpd[i][j+1][u];
        sd[i][j].insert(u^p[i][j]);
        }
      for (auto u:sd[i+1][j])
        {
        mpd[i][j][u^p[i][j]]+=mpd[i+1][j][u];
        sd[i][j].insert(u^p[i][j]);
        }
      }

ll ans=0;
for (i=0; i<n; i++)
  {
  j=n-1-i;
  for (auto u:su[i][j])
    {
    ll need=u^r;
    need^=p[i][j];
  //  cout<<u<<' '<<need<<endl;
    mpd[i][j][need]+=0;
    ans+=mpu[i][j][u]*mpd[i][j][need];
    }
  }
cout<<ans<<endl;
/*
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    {
    cout<<'{';
    for (auto u:su[i][j])
      cout<<u<<' ';
    cout<<'}';
    }
  cout<<endl;
  }
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    {
    cout<<'{';
    for (auto u:sd[i][j])
      cout<<u<<' ';
    cout<<'}';
    }
  cout<<endl;
  }
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    {
    cout<<'{';
    for (auto u:su[i][j])
      cout<<mpu[i][j][u]<<' ';
    cout<<'}';
    }
  cout<<endl;
  }
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    {
    cout<<'{';
    for (auto u:sd[i][j])
      cout<<mpd[i][j][u]<<' ';
    cout<<'}';
    }
  cout<<endl;
  }
*/

    return 0;
}

/*
3 3 11
2 1 5
7 10 0
12 6 4

*/