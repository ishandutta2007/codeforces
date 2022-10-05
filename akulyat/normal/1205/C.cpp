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
vector <vector <ll>> f;
vector <ll> d;
vector <ll> ch;
bool viv=false;

void show()
{
cout<<"!"<<endl;
for (ll i=0; i<n; i++)
  {
  for (ll j=0; j<n; j++)
    cout<<ch[f[i][j]];
  cout<<endl;
  }
exit(0);
}

bool ask(ll a, ll b, ll c, ll d)
{
if (a>c||b>d)
  swap(a, c), swap(b, d);
cout<<"? ";
cout<<a+1<<' ';
cout<<b+1<<' ';
cout<<c+1<<' ';
cout<<d+1<<' ';
cout<<endl;
ll res;
cin>>res;
return res;
}

void cmp(ll x, ll y, ll wx, ll wy)
{
wx+=x;
wy+=y;
f[x][y]=f[wx][wy];
if (!ask(x, y, wx, wy))
  f[x][y]^=1;
}

void cmp2(ll a, ll b, ll a1, ll b1)
{
if (viv)
  cout<<"CMP2: "<<a<<' '<<b<<' '<<a1<<' '<<b1<<endl;
ll r=f[a][b];
ll r1=f[a1][b1];
if (r>r1)
  swap(r, r1);

ch[r1]=r;
if (!ask(a, b, a1, b1))
  ch[r1]^=1;
ch[r1^1]=ch[r1]^1;
show();
}

void cross(ll x, ll y)
{
ll x1=x-1, y1=y+1;
if (f[x][y]!=f[x1][y1])
  {
  if (viv)
    cout<<"Cross "<<x<<' '<<y<<' '<<x1<<' '<<y1<<endl;
  ll a=min(x1, x);
  ll b=min(y1, y);
  ll a1=a+1;
  ll b1=b+1;
  if (a1==n-1&&b1==n-1)
    {
    if (a)
      a--;
    else
      b--;
    }
  else
    {
    if (a1<n-1)
      a1++;
    else
      b1++;
    }
  cmp2(a, b, a1, b1);
  }
}

bool exist(ll x, ll y)
{
if (x<0||y<0)
  return false;
if (x>=n||y>=n)
  return false;
return true;
}

void ko(ll dg)
{
ll r=d[dg];
ll r1=d[dg+3];
if (r>r1)
  swap(r, r1);

ll x=0;
ll y=dg;
if (y>=n)
  {x=n-1; y=dg-x;}

ch[r1]=r;
for (ll i=0; i<=3; i++)
  if (exist(x+i, y+3-i))
    {
    if (!ask(x, y, x+i, y+3-i))
      ch[r1]^=1;
    i=4;
    }
ch[r1^1]=ch[r1]^1;
show();
}

void digs()
{
d.resize(2*n-1);
for (ll i=0; i<n; i++)
  for (ll j=0; j<n; j++)
    d[i+j]=f[i][j];
for (ll i=0; i<d.size()-3; i++)
  {
  set <ll> s;
  for (ll j=i; j<i+4; j++)
    s.insert(d[j]);
  if (s.size()!=3)
    ko(i);
  }
}

void show_me()
{
if (!viv)
  return;
cout<<"Showing:"<<endl;
for (ll i=0; i<n; i++)
  {
  for (ll j=0; j<n; j++)
    cout<<f[i][j]<<' ';
  cout<<endl;
  }
cout<<"______"<<endl;
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
f.resize(n);
for (auto &v:f)
  v.resize(n);
f[0][0]=1;
f[0][1]=2;
for (ll i=2; i<n; i+=2)
  cmp(0, i, 0, -2);
for (ll i=2; i<n; i+=2)
  cmp(i, 0, -2, 0);
for (ll i=1; i<n; i++)
  for (ll j=1; j<n; j++)
    if (i<n-1||j<n-1)
      if ((i^j^1)&1)
        cmp(i, j, -1, -1);

for (ll i=3; i<n; i+=2)
  cmp(0, i, 0, -2);
cmp(2, 1, -2, 0);
cmp(1, 0, 1, 1);
for (ll i=3; i<n; i+=2)
  cmp(i, 0, -2, 0);

for (ll i=1; i<n; i++)
  for (ll j=1; j<n; j++)
    if (i!=2||j!=1)
      if ((i^j)&1)
        cmp(i, j, -1, -1);

ch.resize(4);
for (ll i=0; i<4; i++)
  ch[i]=i;

if (viv)
  show_me();


for (ll i=1; i<n; i++)
  for (ll j=0; j<n-1; j++)
    cross(i, j);

digs();

    return 0;
}