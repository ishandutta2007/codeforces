#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <pll, ll> ppll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

struct mine
{
ll a,b,c;
};

bool cmp(mine a, mine b)
{
if (a.a<b.a)
  return true;
if (a.a>b.a)
  return false;
if (a.b<b.b)
  return true;
if (a.b>b.b)
  return false;
if (a.c<b.c)
  return true;
if (a.c>b.c)
  return false;
}

ll n,i,j;
vector <ll> m,asked;
map <set<ll> , ll> mp;
bool viv=false;

ll ask(ll a, ll b, ll c)
{
cout<<"? "<<a+1<<' '<<b+1<<' '<<c+1<<endl;
ll r;
cin>>r;
mp[{a, b, c}]=r;
return r;
}

void work5()
{
ll i,j,u;
set <set<ll> > vars;
for (i=0; i<5; i++)
  for (j=i+1; j<5; j++)
    for (u=j+1; u<5; u++)
      ask(i, j, u), vars.insert({i, j, u});
vector <ll> sum;
for (ll i=0; i<5; i++)
  {
  vector <ll> lsum;
  for (auto t:vars)
    if (!t.count(i))
      lsum.push_back(mp[t]);
  sort(lsum.begin(), lsum.end());
  sum.push_back(lsum.back()+lsum[0]);
  if (viv)
    {
    cout<<i<<": ";
    for (auto i:lsum)
      cout<<i<<' ';
    cout<<endl;
    }
  }
if (viv)
  {
  for (auto i:sum)
    cout<<i<<' ';
  cout<<endl;
  }
ll S=0;
for (auto i:sum)
  S+=i;
S/=4;
if (viv)
  cout<<S<<endl;
for (auto &i:sum)
  i=S-i;
for (auto i:sum)
  m.push_back(i);
}

void prepare()
{
vector <pll> tos;
for (ll i=0; i<3; i++)
  tos.push_back({m[i], i});
sort(tos.begin(), tos.end());
for (auto i:tos)
  asked.push_back(i.S);
}

void work(ll p)
{
ll ssum1=m[asked[0]]+m[asked[1]];
ll ssum2=m[asked[1]]+m[asked[2]];
ll gsum1=ask(asked[0], asked[1], p);
ll gsum2=ask(asked[1], asked[2], p);
if (ssum1!=gsum1)
  {
  ll v=0;
  if (ssum1<gsum1)
    v=gsum1-m[asked[0]];
  else
    v=gsum1-m[asked[1]];
  m[p]=v;
  return;
  }
if (ssum2!=gsum2)
  {
  ll v=0;
  if (ssum2<gsum2)
    v=gsum2-m[asked[1]];
  else
    v=gsum2-m[asked[2]];
  m[p]=v;
  return;
  }


m[p]=m[asked[1]];
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
work5();
while(m.size()<n)
  m.push_back(-1);
prepare();
for (ll i=5; i<n; i++)
  work(i);
cout<<"! ";
for (auto i:m)
  cout<<i<<' ';





    return 0;
}