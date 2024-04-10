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
vector <pll> m1, m2;
map <pll, ll> mp;
bool viv=false;

vector <ll> work(vector <pll> m, bool b)
{
ll n=m.size();
ll was=mod;
if (b)
  was=-1;
vector <ll> res;

if (false)
  {
  cout<<"____________________"<<endl;
  for (auto p:m)
    {
    cout<<p.F<<' '<<p.S<<endl;
    }
  cout<<"____________________"<<endl;
  }

for (ll i=0; i<n; i++)
  {
  if (((m[i].S)<was)^(b))
    {
    res.push_back(m[i].S);
    res.push_back(m[i].F);
    was=m[i].F;
    }
  }
if (viv)
  {
  for (auto i:res)
    cout<<i<<' ';
  cout<<endl;
  }
return res;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a, b;
  cin>>a>>b;
//  a--, b--;
  mp[{a, b}]=i;
  if (a<b)
    m1.push_back({a, b});
  else
    m2.push_back({a, b});
  }
for (auto &p:m1)
  swap(p.F, p.S);
for (auto &p:m2)
  swap(p.F, p.S);
sort(m1.rbegin(), m1.rend());
sort(m2.begin(), m2.end());

auto ans1=work(m1, 0);
auto ans2=work(m2, 1);
if (ans1.size()<ans2.size())
  swap(ans1, ans2);
cout<<ans1.size()/2<<endl;
for (ll i=0; i<ans1.size(); i+=2)
  {
  pll p={ans1[i], ans1[i+1]};
  if (mp.find(p)==mp.end())
    swap(p.F, p.S);
  ll pl=mp[p];
  cout<<pl+1<<' ';
  }











    return 0;
}