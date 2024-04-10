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
vector <pll> st;
vector <ll> t;
bool viv=false;

void read()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  st.push_back({a, i});
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  t.push_back(a);
  }
sort(st.begin(), st.end());
sort(t.begin(), t.end());
}

void bad()
{
cout<<"NO";
exit(0);
}

void work()
{
set <pair <pll, ll> > s1;
set <pair <pll, ll> > s2;
for (ll i=0; i<n; i++)
  {
  if (st[i].F<t[i])
    s1.insert({{st[i].F, t[i]}, st[i].S});
  if (st[i].F>t[i])
    s2.insert({{st[i].F, t[i]}, st[i].S});
  }
vector <pair <pll, ll>> ans;
//viv=true;
while (s1.size()||s2.size())
  {
/**
  if (viv)
    {
    cout<<"New step ("<<s.size()<<"): ";
    for (auto p:s)
      cout<<p.F.F<<' '<<p.F.S<<' '<<p.S<<"; ";
    cout<<endl;
    }
**/
  if (s1.empty()||s2.empty())
    bad();
  auto p1=*(s1.begin());
  auto p2=*(s2.begin());
  s1.erase(p1);
  s2.erase(p2);
  ll d=min(p1.F.S-p1.F.F, p2.F.F-p2.F.S);
  if (viv)
    cout<<"delta="<<d<<endl;
  if (p1.F.F>p2.F.F||p1.F.F==p2.F.F&&d>0)
    bad();
  if (d<0)
    bad();
  if (d>0)
    ans.push_back({{p1.S, p2.S}, d});
  p1.F.F+=d;
  p2.F.F-=d;
  if (p1.F.F!=p1.F.S)
    s1.insert(p1);
  if (p2.F.F!=p2.F.S)
    s2.insert(p2);
  }
cout<<"YES"<<endl;
cout<<ans.size()<<endl;
for (auto p:ans)
  cout<<p.F.F+1<<' '<<p.F.S+1<<' '<<p.S<<'\n';
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
read();
work();




    return 0;
}