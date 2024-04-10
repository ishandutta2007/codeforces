#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long       ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j,last;
vector <ll> m;
vector <ll> p,v,xc;
bool viv=false;
map <ll, ll> mp;

void write()
{
if (!viv)
  return;
cout<<"           ______ Started"<<endl;
for (i=0; i<p.size(); i++)
  cout<<"         "<<xc[i]<<' '<<p[i]<<' '<<v[i]<<endl;
cout<<"           ______ Ended"<<endl;
}

void new_v(ll x)
{
mp[x]=p.size();
xc.push_back(x);
p.push_back(p.size());
v.push_back(0);
}

pll tofa(ll v1)
{
while (p[p[v1]]!=p[v1])
  {
  v[v1]^=v[p[v1]];
  p[v1]=p[p[v1]];
  }
return {p[v1], v[v1]};
}

void merge(ll v1, ll v2, ll val)
{
if (viv)
  cout<<"Merge "<<v1<<' '<<v2<<' '<<val<<endl;
pll a1=tofa(v1);
pll a2=tofa(v2);
if (viv)
  {
  cout<<"They are"<<endl;
  cout<<a1.F<<' '<<a1.S<<' ';
  cout<<a2.F<<' '<<a2.S<<endl;
  }
if (a1.F==a2.F)
  return;
ll s=a2.F;
p[s]=v1;
v[s]=val^a2.S;
}

void add()
{
ll l,r,val;
cin>>l>>r>>val;
l^=last;
r^=last;
val^=last;
if (l>r)
  swap(l, r);
r++;
if (mp.find(l)==mp.end())
  new_v(l);
if (mp.find(r)==mp.end())
  new_v(r);
ll v1=mp[l];
ll v2=mp[r];
merge(v1, v2, val);
}

void len()
{
ll l,r; cin>>l>>r;
l^=last;
r^=last;
if (l>r)
  swap(l, r);
r++;
if (mp.find(l)==mp.end()||mp.find(r)==mp.end())
  {
  cout<<-1<<'\n';
  last=1;
  return;
  }
ll v1=mp[l];
ll v2=mp[r];
pll a1=tofa(v1);
pll a2=tofa(v2);
if (a1.F==a2.F)
  {
  cout<<(a1.S^a2.S)<<'\n';
  last=(a1.S^a2.S);
  return;
  }
cout<<-1<<'\n';
last=1;
}


int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
last=0;
while (t)
  {
  ll ty;
  cin>>ty;
  ty--;
  if (ty)
    len();
  else
    add();
  write();
  t--;
  }

    return 0;
}