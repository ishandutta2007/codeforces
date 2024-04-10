#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const ll con=100*kk;

bool can[con];
ll n,i,j;
ull w;
vector <ll> m;
bool viv=false;

void build()
{
vector <ll> v;
for (ll i=0; i<7; i++)
  for (ll j=0; j<m[i]; j++)
    v.push_back(i+1);
sort(v.begin(), v.end());
if (viv)
  {
  for (auto i:v)
    cout<<i<<' ';
  cout<<endl;
  }
ull have=m[7];

ull las=0;
can[0]=true;
for (auto val:v)
  {
  for (ll j=con-1; j>=val; j--)
    {
    can[j]=can[j]|can[j-val];
    if (can[j])
      las=max(las, (ull)j);
    }
  }
ull ans=0;
for (ull i=0; i<=min(las, w); i++)
  if (can[i])
    {
    if (viv)
      cout<<i<<' ';
    ull add=w-i;
    add/=8;
    add=min(add, have);
    ans=max(ans, i+add*8);
    }
if (viv)
  cout<<endl;
cout<<ans<<endl;
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>w;
for (i=0; i<8; i++)
  {
  ull a;
  cin>>a;
  m.push_back(a);
  }

for (ll i=0; i<7; i++)
  {
  ll v=m[i]/8;
  v-=10;
  if (v<0)
    v=0;
  m[i]-=8*v;
  m[7]+=(i+1)*(v);
  }
build();




    return 0;
}
/**
3
0 4 1 0 0 9 8 3

3
0 4 0 0 0 9 8 3

1000000000000000000
1000000000000000 0 0 0 0 0 0 0

1000000000000000000
0 1000000000000000 0 0 0 0 0 0

1000000000000000000
1000000000000000 1000000000000000 1000000000000000 1000000000000000 1000000000000000 1000000000000000 1000000000000000 1000000000000000

100000000000000000
10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000

359999999999999999
10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000

360000000000000001
10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000 10000000000000000

**/