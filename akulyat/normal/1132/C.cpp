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


ll n,i,j, q, l, ans, A;
vector <ll> m;
vector <pll> p;
vector <ll> kol[3];
bool viv=false;
vector <ll> add;

ll c(pll p, ll val)
{
ll l=p.F;
ll r=p.S;
r++;
ll k=0;
k+=kol[val][r];
k-=kol[val][l];
return k;
}

void work(pll p1, pll p2)
{
ll lans=ans;
if (viv)
  cout<<lans<<' ';
lans-=c(p1, 1);
if (viv)
  cout<<lans<<' ';
lans-=c(p2, 1);
if (viv)
  cout<<lans<<' ';
ll mir=min(p1.S, p2.S);
ll mal=max(p1.F, p2.F);
if (mal<=mir)
  {
  pll p={mal, mir};
  lans+=c(p, 1);
  if (viv)
    cout<<lans<<' ';
  lans-=c(p, 2);
  if (viv)
    cout<<lans<<' ';
  }
if (viv)
  cout<<lans<<endl;
A=max(A, lans);
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>l>>n;
add.resize(l+2, 0);
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  a--, b--;
  p.push_back({a, b});
  add[a]++;
  add[b+1]--;
  }
q=n;
n=l;
ll cur=0;
for (ll i=0; i<n; i++)
  {
  cur+=add[i];
  m.push_back(cur);
  }
if (viv)
  {
  for (auto i:m)
    cout<<i<<' ';
  cout<<endl;
  }
for (j=0; j<3; j++)
  {
  kol[j].push_back(0);
  for (ll i=0; i<n; i++)
    kol[j].push_back(kol[j].back()), kol[j].back()+=(m[i]==j);
  }
for (auto i:m)
  ans+=(i!=0);
for (ll i=0; i<q; i++)
  for (ll j=i+1; j<q; j++)
    {
    if (viv)
      cout<<i<<' '<<j<<':';
    work(p[i], p[j]);
    }
cout<<A;




    return 0;
}