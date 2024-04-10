#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long long K=2;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

struct vertex
{
ll next[K];
ll leaf;
ll p;
ll pch;
ll link;
ll go[K];
ll zn;
};

vertex t[7*ml];
ll n,i,j,sz;
vector <ll> m,x;
bool viv=false;

void zap(ll v, ll p, ll pch)
{
for (ll i=0; i<K; i++)
  t[v].next[i]=-1;
t[v].p=p;
t[v].pch=pch;
}

void build()
{
zap(0, 0, 0);
sz=1;
}

void add_string(ll num)
{
ll zn=num;
vector <ll> bin(30);
for (ll i=0; i<30; i++)
  {
  bin[i]=num&1;
  num/=2;
  }
reverse(bin.begin(), bin.end());

ll v=0;
for (auto i:bin)
  if (t[v].next[i]!=-1)
    {
    v=t[v].next[i];
//    cout<<i<<' ';
    }
  else
    {
    t[v].next[i]=sz;
    zap(sz, v, i);
    v=sz;
    sz++;
//    cout<<'h'<<i<<' ';
    }
//cout<<endl;
t[v].leaf++;
t[v].zn=zn;
}

void era(ll v)
{
if ((!(t[v].next[0]+1))&&(!(t[v].next[1]+1))&&(!t[v].leaf)&&(v))
  {
//  cout<<"Kik "<<v<<' ';
  t[t[v].p].next[t[v].pch]=-1;
  era(t[v].p);
  }
}

ll ans(ll num)
{
//cout<<"In "<<num<<' ';
vector <ll> bin(30);
for (ll i=0; i<30; i++)
  {
  bin[i]=num&1;
  num/=2;
  }
reverse(bin.begin(), bin.end());

ll v=0;
ll r=0;
for (auto i:bin)
  {
  r*=2;
  if (t[v].next[i]!=-1)
    v=t[v].next[i];
  else
    {
    v=t[v].next[i^1];
    r++;
    }
//  cout<<v<<' ';
  }
t[v].leaf--;
era(v);
//cout<<"Out "<<r<<endl;
return r;
}



int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  x.push_back(a);
  }

build();
for (auto i:x)
  add_string(i);
//for (i=0; i<sz; i++)
//  cout<<i<<' '<<t[i].p<<' '<<t[i].pch<<endl;



for (auto i:m)
  cout<<ans(i)<<' ';




    return 0;
}