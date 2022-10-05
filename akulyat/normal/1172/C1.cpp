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
const long long mod=998244353;
const long long inf=ml*ml*ml+7;


ll n,i,j, pos;
vector <ll> w;
vector <bool> t;
ll s[2];
bool viv=false;

long long obr(long long v, long long mod)
{
long long i=0;
long long st=mod-2;
vector <long long> bin;
long long l=0;
while(st>0)
  {
  bin.push_back(st&1);
  st/=2;
  l++;
  }

vector <long long> sq;
sq.push_back(v);
for (i=1; i<l; i++)
  {
  long long s=sq.back();
  s*=s;
  s%=mod;
  sq.push_back(s);
  }

long long ans=1;
for (i=0; i<l; i++)
  if (bin[i])
    {
    ans*=sq[i];
    ans%=mod;
    }
return ans;
}

pair <ll, pll> con(ll a, ll b, ll c)
{
return {a, {b, c}};
}

pll umn(pll a, pll b)
{
a.F*=b.F;
a.F%=mod;
a.S*=b.S;
a.S%=mod;
return a;
}

pll sum(pll a, pll b)
{
a.F*=b.S;
b.F*=a.S;
a.S*=b.S;
a.F+=b.F;
a.F%=mod;
a.S%=mod;
return a;
}

ll solve(ll m, ll b, ll g, bool good)
{
map <pair<ll, pll>, pll> mp[pos+1];
mp[0][con(m, b, g)]={1, 1};
for (ll i=0; i<pos; i++)
  {
  if (viv)
    cout<<"I wait "<<mp[i].size()<<endl;
  for (pair <pair <ll, pll>, pll> v:mp[i])
    {
    pll val=v.S;
    ll a=v.F.F;
    ll b=v.F.S.F;
    ll c=v.F.S.S;
    ll all=a+b+c;
    if (viv)
      cout<<"Have on "<<i<<" step "<<'{'<<a<<' '<<b<<' '<<c<<'}'<<' '<<val.F<<"/"<<val.S<<endl;
    if (a)
      if (mp[i+1].find(con(a-1+2*good, b, c))==mp[i+1].end())
        mp[i+1][con(a-1+2*good, b, c)]=umn(val, {a, all});
      else
        mp[i+1][con(a-1+2*good, b, c)]=sum(mp[i+1][con(a-1+2*good, b, c)], umn(val, {a, all}));
    if (b)
      if (mp[i+1].find(con(a, b-1, c))==mp[i+1].end())
        mp[i+1][con(a, b-1, c)]=umn(val, {b, all});
      else
        mp[i+1][con(a, b-1, c)]=sum(mp[i+1][con(a, b-1, c)], umn(val, {b, all}));
    if (c)
      if (mp[i+1].find(con(a, b, c+1))==mp[i+1].end())
        mp[i+1][con(a, b, c+1)]=umn(val, {c, all});
      else
        mp[i+1][con(a, b, c+1)]=sum(mp[i+1][con(a, b, c+1)], umn(val, {c, all}));
    if (viv)
      cout<<"MMMM"<<endl;
    }
  if (viv)
    cout<<"VSE"<<endl;
  }
if (viv)
  cout<<"Sovsem VSE"<<endl,
  cout<<"We saw "<<mp[pos].size()<<endl;
pll res={0, 1};
for (pair <pair <ll, pll>, pll> v:mp[pos])
  {
  if (viv)
    cout<<"Have on last step "<<'{'<<v.F.F<<' '<<v.F.S.F<<' '<<v.F.S.S<<'}'<<' '<<v.S.F<<"/"<<v.S.S<<endl;
  res=sum(res, umn(v.S, {v.F.F, 1}));
  }
ll lans=res.F;
lans*=obr(res.S, mod);
lans%=mod;
return lans;
}


ll sol(ll num)
{
ll ls[2];
ls[0]=s[0];
ls[1]=s[1];
ls[t[num]]-=w[num];
return solve(w[num], ls[0], ls[1], t[num]);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>pos;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  t.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  s[t[i]]+=a;
  w.push_back(a);
  }
vector <ll> ans;
for (ll i=0; i<n; i++)
  ans.push_back(sol(i));
for (auto i:ans)
  cout<<i<<'\n';





    return 0;
}