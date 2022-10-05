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


ll n,i,j;
vector <pair <pll, pll> > m;
set <pll> s;
map <pll, ll> mp;
bool viv=false;


long long GCD(long long a, long long b)
{
if (a==0&&b==0)
  return 0;
while (a!=0&&b!=0)
  {
  if (a>=b)
    a%=b;
  else
    b%=a;
  }
return a+b;
}

pair<pll, ll> koef_line(pair<pll, pll> otr)
{
ll a,b,c;
b=otr.F.F-otr.S.F;
a=-(otr.F.S-otr.S.S);
c=-a*otr.F.F-b*otr.F.S;
return {{a, b}, c};
}

bool point_in_seg(ll x, ll y, pair<pll, pll> otr)
{
if (abs(otr.F.F-x)+abs(otr.S.F-x)==abs(otr.F.F-otr.S.F))
  if (abs(otr.F.S-y)+abs(otr.S.S-y)==abs(otr.F.S-otr.S.S))
    return true;
return false;
}

pll intersection(pair<pll, pll> o1, pair<pll, pll> o2)
{
ll a1, b1, c1;
auto koef1=koef_line(o1);
a1=koef1.F.F;
b1=koef1.F.S;
c1=koef1.S;

ll a2, b2, c2;
auto koef2=koef_line(o2);
a2=koef2.F.F;
b2=koef2.F.S;
c2=koef2.S;

pll bad={inf, inf}; //for non-integer & parallel;
if (a1*b2-a2*b1==0) //parallel
  return bad;

if ((b1*c2-b2*c1)%(a1*b2-a2*b1)!=0)  //non-integer x
  return bad;
ll x=(b1*c2-b2*c1)/(a1*b2-a2*b1);
if ((a1*c2-a2*c1)%(a2*b1-a1*b2)!=0)  //non-integer y
  return bad;
ll y=(a1*c2-a2*c1)/(a2*b1-a1*b2);

if (point_in_seg(x, y, o1)&&point_in_seg(x, y, o2))
  return {x, y};
return bad;
}





int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
ll ans=0;
for (i=0; i<n; i++)
  {
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ans+=GCD(abs(a-c), abs(b-d))+1;
  m.push_back({{a, b}, {c, d}});
  }


vector <ll> kol;
kol.push_back(0);
for (i=1; i<2*kk; i++)
  kol.push_back(kol.back()+i);
vector <ll> was(2*ml, 0);
for (i=0; i<kol.size(); i++)
  was[kol[i]]=i;

for (i=0; i<n; i++)
  for (j=i+1; j<n; j++)
    {
    pll t=intersection(m[i], m[j]);
    if (t.F!=inf||t.S!=inf)
      {
      s.insert(t);
      mp[t]++;
      }
    }
for (auto t:s)
  ans-=was[mp[t]];

cout<<ans;



    return 0;
}