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

vector <ll> t;
ll n,i,j, l, q, sz;
vector <ll> p, m, aft, bef, near, v;
vector <vector <ll>> las, best;
string s;
bool viv=false;

void prepare()
{
p.push_back(p[0]);
aft.resize(n);
bef.resize(n);
for (ll i=0; i<n; i++)
  aft[p[i]]=p[i+1];
for (ll i=1; i<n+1; i++)
  bef[p[i]]=p[i-1];
p.pop_back();
las.resize(n);
for (ll i=0; i<n; i++)
  las[i].push_back(-1);
for (ll i=0; i<l; i++)
  {
  ll val=m[i];
  near.push_back(las[bef[val]].back());
  las[val].push_back(i);
  }
if (viv)
  {
  cout<<"Near"<<endl;
  for (auto i:near)
    cout<<i<<' ';
  cout<<endl;
  }

}

void count()
{
best.resize(20);
for (auto &v:best)
  v.resize(l);
for (ll i=0; i<l; i++)
  best[0][i]=i;
for (ll j=1; j<20; j++)
  {
  for (ll i=0; i<l; i++)
    {
    if (viv)
      cout<<j<<' '<<i<<' ';
    ll c=best[j-1][i];
    if (c==-1||near[c]==-1)
      best[j][i]=-1;
    else
      {
      ll b=near[c];
      if (viv)
        cout<<b<<' ';
      ll a=best[j-1][b];
      best[j][i]=a;
      }
    if (viv)
      cout<<best[j][i]<<endl;
    }
  }
for (ll i=0; i<l; i++)
  {
  ll from=i;
  ll ost=n-1;
  ll b=0;
  while (ost)
    {
    if (ost&1)
      if (from!=-1)
        {
        ll nex=near[from];
        if (nex!=-1)
          from=best[b][nex];
        else
          from=-1;
        }
    ost>>=1;
    b++;
    }
  v.push_back(from);
  }
if (viv)
  {
  cout<<"From "<<v.size()<<endl;
  for (auto i:v)
    cout<<i<<' ';
  cout<<endl;
  }

}

void build()
{
sz=1;
while (sz<l)
  sz<<=1;
while (v.size()<sz)
  v.push_back(-1);
t.resize(2*sz);
for (ll i=0; i<v.size(); i++)
  t[sz+i]=v[i];
for (ll i=sz-1; i>0; i--)
  t[i]=max(t[2*i], t[2*i+1]);
}

ll get(ll l, ll r, ll v, ll tl, ll tr)
{
if (r<tl||tr<l)
  return -1;
if (l<=tl&&tr<=r)
  return t[v];
ll tm=tl+tr>>1;
ll v1=get(l, r, 2*v, tl, tm);
ll v2=get(l, r, 2*v+1, tm+1, tr);
return max(v1, v2);
}

void work()
{
ll l, r;
cin>>l>>r;
l--, r--;
ll wasl=l;
l+=n-1;
if (l<=r)
  {
  if (get(l, r, 1, 0, sz-1)>=wasl)
    s+='1';
  else
    s+='0';
  }
else
  s+='0';
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>l>>q;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  p.push_back(a);
  }
for (i=0; i<l; i++)
  {
  ll a;
  cin>>a;
  a--;
  m.push_back(a);
  }
prepare();
count();
build();
while (q)
  work(), q--;
cout<<s<<endl;








    return 0;
}