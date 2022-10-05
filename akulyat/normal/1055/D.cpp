#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long        ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const ll kk=1000;
const ll ml=kk*kk;
const ll mod=ml*kk+7;
const ll inf=ml*ml*ml+7;


ll n,i,j,cou=0;
vector <string> s,t,tw;
string mains,maint;
string suf,pr;
bool viv=false;
bool cont;

vector <ll> z_function(const string &s)
{
ll n=s.size();
vector <ll> z(n);
ll l=0, r=0;
for (ll i=1; i<n; i++)
  {
  if (i<=r)
    z[i]=min(z[i-l], r-i+1);
  while (i+z[i]<n&&s[z[i]]==s[i+z[i]])
    z[i]++;
  if (i+z[i]-1>r)
    l=i, r=i+z[i]-1;
  }
return z;
}

void bad()
{
cout<<"NO";
exit(0);
}

void read()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (ll i=0; i<n; i++)
  {
  string a;
  cin>>a;
  s.push_back(a);
  }
for (ll i=0; i<n; i++)
  {
  string a;
  cin>>a;
  t.push_back(a);
  }
}

void work(string s, string t)
{
ll n=s.size();
ll l=mod, r=-mod;
for (ll i=0; i<n; i++)
  if (s[i]!=t[i])
    l=min(l, i),
    r=max(r, i);
if (l==mod)
  {tw.push_back(s); return;}
if (cou==0)
  {
  for (ll i=l; i<=r; i++)
    mains+=s[i],
    maint+=t[i];
  for (ll i=0; i<l; i++)
    pr+=s[i];
  for (ll i=r+1; i<n; i++)
    suf+=s[i];
  reverse(suf.begin(), suf.end());
  }
else
  {
  string locs,loct;
  for (ll i=l; i<=r; i++)
    locs+=s[i],
    loct+=t[i];
  if (locs!=mains||loct!=maint)
    bad();

  string lpr,lsuf;
  for (ll i=0; i<l; i++)
    lpr+=s[i];
  for (ll i=r+1; i<n; i++)
    lsuf+=s[i];
  reverse(lsuf.begin(), lsuf.end());

  string coml,comr;
  while (pr.size()&&lpr.size()&&pr.back()==lpr.back())
    coml+=pr.back(), pr.pop_back(), lpr.pop_back();
  while (suf.size()&&lsuf.size()&&suf.back()==lsuf.back())
    comr+=suf.back(), suf.pop_back(), lsuf.pop_back();
  reverse(coml.begin(), coml.end());
  reverse(comr.begin(), comr.end());
  pr=coml;
  suf=comr;
  }
cou++;
}

void find_seg()
{
for (ll i=0; i<n; i++)
  work(s[i], t[i]);
reverse(suf.begin(), suf.end());
}

void add()
{
mains=pr+mains+suf;
maint=pr+maint+suf;
//cout<<"Main strings "<<mains<<' '<<maint<<endl;
}

void check_twince()
{
for (auto s:tw)
  {
  vector <ll> z=z_function(mains+'#'+s);
  for (auto v:z)
    if (v>=mains.size())
      bad();
  }
}

void change()
{
for (ll i=0; i<n; i++)
  {
  vector <ll> z=z_function(mains+'#'+s[i]);
  for (ll j=0; j<s[i].size(); j++)
    if (z[j+mains.size()+1]>=mains.size())
      {
      for (ll u=j; u<j+mains.size(); u++)
        {
        s[i][u]=maint[u-j];
        }
      j=s[i].size();
      }
  if (s[i]!=t[i])
    bad();
  }
}

void write()
{
cout<<"YES"<<endl;
cout<<mains<<endl;
cout<<maint<<endl;
}

int main()
{
read();
find_seg();
add();
check_twince();
change();
write();

    return 0;
}