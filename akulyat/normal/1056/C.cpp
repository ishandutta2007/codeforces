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


ll n,i,j,ty,k;
vector <ll> m,reb;
bool viv=false;
ll last=-1;
set <pll> t;
set <pll> ost;
vector <bool> was;

void ask()
{
cin>>last;
last--;
was[last]=true;
t.erase({-m[last], last});
ost.erase({-m[last], last});
}

void step()
{
if (last!=-1&&reb[last]!=-1&&was[reb[last]]==false)
  {
  ll v=reb[last];
  t.erase({-m[v], v});
  was[v]=true;
  cout<<v+1<<endl;
  }
else
  {
  if (t.size())
    {
    ll v=(*t.begin()).S;
    t.erase(t.begin());
    was[v]=true;
    cout<<v+1<<endl;
    }
  else
    {
    ll v=(*ost.begin()).S;
    was[v]=true;
    ost.erase(ost.begin());
    cout<<v+1<<endl;
    }
  }
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
n*=2;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
reb.assign(n, -1);
was.assign(n, false);
for (i=0; i<k; i++)
  {
  ll a,b;
  cin>>a>>b;
  a--; b--;
  ll c=m[a]-m[b];
  reb[a]=b;
  reb[b]=a;
  m[a]=c;
  m[b]=-c;
  if (c>=0)
    t.insert({-c, a});
  else
    t.insert({c, b});
  }
for (i=0; i<n; i++)
  if (reb[i]==-1)
    ost.insert({-m[i], i});

cin>>ty;
ty--;
ty^=1;
for (i=0; i<n; i++)
  {
  if (ty)
    step();
  else
    ask();
  ty^=1;
  }

    return 0;
}