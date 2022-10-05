#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j;
vector <pair <string, ll> > m;
map <pll, ll> mp;
bool viv=false;


string ll_to_str(long long v)
{
string s="";
if (v==0)
  return "0";
bool obr=false;
if (v<0)
  obr=true;
v=abs(v);
while (v>0)
  {
  short e=v%10;
  s+=char('0'+e);
  v/=10;
  }
reverse(s.begin(), s.end());
if (obr)
  s='-'+s;
return s;
}

ll str_to_ll(string s)
{
ll r=0;
ll u=1;
while (s.size())
  {
  r+=(s.back()-'0')*u;
  u*=10;
  s.pop_back();
  }
return r;
}

pll kod(ll v)
{
ll v1=v;
ll z=0;
ll zn=0;
ll u=1;
while (v1)
  {
  z+=(v1%10)*u;
  u*=10;
  v1/=10;
  zn++;
  if (mp.find({z, zn})==mp.end())
    return {z, zn};
  }
}




int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  reverse(s.begin(), s.end());
  s.pop_back();
  s.pop_back();
  s.pop_back();
  s.pop_back();
  reverse(s.begin(), s.end());
  m.push_back({s, s.size()});
  }
/*
for (auto i:m)
  cout<<i.F<<' '<<i.S<<endl;
*/
for (i=1989; i<ml; i++)
  mp[kod(i)]=i;
vector <ll> fir;
fir.push_back(0);
fir.push_back(1989);
ll u=10;
for (i=0; i<13; i++)
  {
  fir.push_back(fir.back()+u);
  u*=10;
  }
for (auto v:m)
  {
  if (mp.find({str_to_ll(v.F), v.S})!=mp.end())
    cout<<mp[{str_to_ll(v.F), v.S}]<<endl;
  else
    {
    ll st=fir[v.S];
    string s=v.F;
    while (st>str_to_ll(s))
      s='1'+s;
    cout<<s<<endl;
    }
  }




    return 0;
}
/*
15
aaaa15
aaaa2015
aaaa1
aaaa9
aaaa0
aaaa99
aaaa999
aaaa9999
aaaa00
aaaa000
aaaa01
aaaa239
aaaa11111240
aaaa0000000
aaaa00000000
*/