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


ll n,i,j,m;
vector <ll> p[2*kk];
vector <ll> mine[2*kk];
bool viv=false;
map <char, ll> mp;

void build(ll x, ll y)
{
ll i,j;
for (i=-1; i<=1; i++)
  for (j=-1; j<=1; j++)
    if (i||j)
      mine[x+i][y+j]=1;
}

void zap(ll x, ll y)
{
ll i,j;
ll kol=0;
for (i=-1; i<=1; i++)
  for (j=-1; j<=1; j++)
    if (i||j)
      if (p[x+i][y+j])
        kol++;
if (kol==8)
  build(x, y);
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
mp['.']=0;
mp['#']=1;
for (i=0; i<n; i++)
  {
  string a;
  cin>>a;
  for (j=0; j<m; j++)
    p[i].push_back(mp[a[j]]),
    mine[i].push_back(0);
  }

for (i=1; i<n-1; i++)
  for (j=1; j<m-1; j++)
    zap(i, j);

for (i=0; i<n; i++)
  for (j=0; j<m; j++)
    if (p[i][j]-mine[i][j])
      {
      cout<<"NO";
      return 0;
      }
cout<<"YES";

    return 0;
}