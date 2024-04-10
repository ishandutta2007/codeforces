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

struct mine
{
  ll sum, min, max;
};

mine t[300*kk];
ll n,i,j, s;
vector <ll> m, k, pref;
bool viv=false;

void upd(ll v);

void write();

void build()
{
s=1;
while (s<n)
  s<<=1;
for (ll i=0; i<n; i++)
  t[s+i].sum=m[i],
  t[s+i].min=m[i],
  t[s+i].max=m[i];
for (ll i=n; i<s; i++)
  t[s+i].min=inf,
  t[s+i].max=inf;
for (ll i=s-1; i>0; i--)
  upd(i);
}

void upd(ll v)
{
if (v>=s)
  return;
t[v].sum=t[2*v].sum;
t[v].sum+=t[2*v+1].sum;
t[v].min=t[2*v].min;
t[v].max=t[2*v+1].max;
if (t[v].max==inf)
  t[v].max=t[2*v].max;
}

void make(ll v, ll tl, ll tr, ll val)
{
if (v>=2*s)
  return;
if (t[v].min>=val)
  return;
tr=min(tr, n-1);
t[v].min=val;
t[v].max=val;
t[v].sum=t[v].min*(tr-tl+1);
if (viv)
  cout<<"Ok "<<v<<' '<<t[v].sum<<endl;
}

void push(ll v, ll tl, ll tr)
{
ll tm=tl+tr>>1;
make(2*v, tl, tm, t[v].min);
make(2*v+1, tm+1, tr, t[v].min);
}



void add(ll l, ll r, ll v, ll tl, ll tr, ll val)
{
if (r<tl||tr<l)
  return;
if (t[v].min>=val)
  return;
if (viv)
  cout<<"In "<<tl<<' '<<tr<<endl;
push(v, tl, tr);
if (l<=tl&&tr<=r&&t[v].max<=val)
  {
  make(v, tl, tr, val);
  return;
  }
ll tm=tl+tr>>1;
add(l, r, 2*v, tl, tm, val);
add(l, r, 2*v+1, tm+1, tr, val);
upd(v);
}

ll get(ll l, ll r, ll v, ll tl, ll tr)
{
if (r<tl||tr<l)
  return 0;
push(v, tl, tr);
if (l<=tl&&tr<=r)
  return t[v].sum;
ll tm=tr+tl>>1;
ll ans=0;
ans+=get(l, r, 2*v, tl, tm);
ans+=get(l, r, 2*v+1, tm+1, tr);
return ans;
}

void read()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
k.push_back(0);
for (i=0; i<n-1; i++)
  {
  ll a;
  cin>>a;
  k.push_back(a);
  }
for (ll i=1; i<n; i++)
  k[i]+=k[i-1];
for (ll i=0; i<n; i++)
  m[i]-=k[i];
pref.push_back(0);
for (auto i:k)
  pref.push_back(pref.back()), pref.back()+=i;
}

void write()
{
if (!viv)
  return;
for (ll i=1; i<n+s; i++)
  {
  cout<<"{";
  cout<<t[i].sum<<' ';
  cout<<t[i].min<<' ';
  cout<<t[i].max<<' ';
  cout<<"}";
  cout<<endl;
  }
}

void add()
{
ll pl,  val;
cin>>pl>>val;
pl--;
ll was=get(pl, pl, 1, 0, s-1);
was+=val;
if (viv)
  cout<<"Make "<<pl<<' '<<n-1<<' '<<was<<endl;
add(pl, n-1, 1, 0, s-1, was);
}

ll sum()
{
ll l, r;
cin>>l>>r;
l--, r--;
ll ans=0;
ans+=pref[r+1];
ans-=pref[l];
ans+=get(l, r, 1, 0, s-1);
return ans;
}

void solve()
{
ll q;
cin>>q;
write();
while (q)
  {
  string ty;
  cin>>ty;
  if (ty[0]=='+')
    add();
  else
    cout<<sum()<<endl;
  q--;
  write();
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
read();
build();
solve();





    return 0;
}