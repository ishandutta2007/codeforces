#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long long K=2*kk+5;

struct mine
{
  ll x, y, l, r;
};

ll n,i,j,a,b,x,y,m;
vector <mine> st;
vector <ll> v[K];
vector <bool> good[K];
ll lp[K][K];
ll rp[K][K];
ll pos[K][K];
bool viv=false;

void build()
{
for (ll i=0; i<n; i++)
  for (ll j=0; j<m; j++)
    lp[i][j]=mod,
    rp[i][j]=mod,
    pos[i][j]=mod,
    good[i].push_back(false);
}

void add(ll x, ll y, ll l, ll r)
{
if (x<0||y<0)
  return;
if (x>=n||y>=m)
  return;
if (lp[x][y]<=l)
  return;
if (pos[x][y]<=l)
  return;
pos[x][y]=l;
st.push_back({x, y, l, r});
}

void go(mine km)
{
ll x=km.x;
ll y=km.y;
ll l=km.l;
ll r=km.r;

//cout<<x<<' '<<y<<' '<<l<<' '<<r<<endl;
if (x<0||y<0)
  return;
if (x>=n||y>=m)
  return;
if (!v[x][y])
  return;
if (l>a||r>b)
  return;
if (lp[x][y]<=l)
  return;

good[x][y]=true;
lp[x][y]=l;
add(x-1, y, l, r);
add(x+1, y, l, r);
add(x, y-1, l+1, r);
add(x, y+1, l, r+1);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
cin>>x>>y;
x--; y--;
cin>>a>>b;
for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  for (j=0; j<m; j++)
    {
    if (s[j]=='.')
      v[i].push_back(1);
    else
      v[i].push_back(0);
    }
  }
build();
st.push_back({x, y, 0, 0});
ll s=0;
while (s!=st.size())
  go(st[s]), s++;


ll ans=0;
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    {
//    cout<<good[i][j];
    if (good[i][j])
      ans++;
    }
//  cout<<endl;
  }
cout<<ans;




    return 0;
}