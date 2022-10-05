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
const long long mod=2*ml*kk+7;
const long long inf=ml*ml*ml+7;
const ll k=9;

ll n,i,j, q, s;
vector <ll> m, sh;
vector <ll> p[k];
vector <ll> t[k];
bool viv=false;

void show();

vector <bool> nonz(ll val)
{
vector <bool> res;
for (ll i=0; i<k; i++)
  {
  if (val%10)
    res.push_back(true);
  else
    res.push_back(false);
  val/=10;
  }
return res;
}

void make(ll num, ll v)
{
if (p[num][t[num][2*v]]<=p[num][t[num][2*v+1]])
  t[num][v]=t[num][2*v];
else
  t[num][v]=t[num][2*v+1];
}

void build(ll num)
{
s=1;
while (s<n+1)
  s<<=1;
t[num].resize(2*s);
for (ll i=0; i<n; i++)
  t[num][i+s]=i;
for (ll i=n; i<s; i++)
  t[num][i+s]=n;
for (ll i=s-1; i>0; i--)
  make(num, i);
}

void builder()
{
for (ll i=0; i<n; i++)
  {
  auto b=nonz(m[i]);
  for (ll j=0; j<k; j++)
    if (b[j])
      p[j].push_back(m[i]);
    else
      p[j].push_back(mod);
  }
for (ll i=0; i<k; i++)
  p[i].push_back(mod), build(i);
sh.push_back(20);
for (ll i=1; i<9; i++)
  sh.push_back(sh.back()*10);
}

void up(ll num, ll v)
{
v>>=1;
while (v)
  {
  make(num, v);
  v>>=1;
  }
}

void add(ll pl, ll val)
{
for (ll j=0; j<k; j++)
  p[j][pl]=mod;
auto b=nonz(val);
for (ll i=0; i<k; i++)
  if (b[i])
    p[i][pl]=val;
  else
    p[i][pl]=mod;
for (ll i=0; i<k; i++)
  up(i, s+pl);
}

ll cmp(ll num, ll a, ll b)
{
return p[num][a]<p[num][b]? a : b;
}

ll mini(ll l, ll r, ll v, ll tl, ll tr, ll num)
{
if (r<tl||tr<l)
  return n;
if (l<=tl&&tr<=r)
  return t[num][v];
ll tm=tl+tr>>1;
ll pl1=mini(l, r, 2*v, tl, tm, num);
ll pl2=mini(l, r, 2*v+1, tm+1, tr, num);
return cmp(num, pl1, pl2);
}

ll solve(ll l, ll r, ll num)
{
ll pl=mini(l, r, 1, 0, s-1, num);
if (p[num][pl]==mod)
  return mod;
ll pl1=mini(l, pl-1, 1, 0, s-1, num);
ll pl2=mini(pl+1, r, 1, 0, s-1, num);
pl1=cmp(num, pl1, pl2);
if (p[num][pl1]==mod)
  return mod;
return p[num][pl]+p[num][pl1];
}

void work()
{
ll ty;
cin>>ty;
if (ty==1)
  {
  ll pl, val;
  cin>>pl>>val;
  pl--;
  add(pl, val);
  show();
  }
else
  {
  ll l, r;
  cin>>l>>r;
  l--, r--;
  vector <ll> ans;
  for (ll i=0; i<k; i++)
    {
    ans.push_back(solve(l, r, i));
    if (ans.back()<sh[i])
      i=k;
    }
  ll res=mod;
  for (auto i:ans)
    res=min(res, i);
  if (res==mod)
    res=-1;
  cout<<res<<'\n';
  }
}

void show()
{
if (!viv)
  return;
cout<<endl;
cout<<"My Show:"<<endl;
for (ll i=0; i<5; i++)
  {
  for (auto v:p[i])
    cout<<v<<' ';
  cout<<endl;
  }
cout<<"________"<<endl<<endl;

}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>n>>q;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
builder();
show();
while (q--)
  work();






    return 0;
}