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
vector <ll> m, all, suf;
vector <vector <pll> > d;
bool viv=false;

void calc()
{
reverse(all.begin(), all.end());
suf.push_back(0);
for (ll i=0; i<all.size(); i++)
  suf.push_back(max(suf.back(), all[i]));
//reverse(suf.begin(), suf.end());
reverse(all.begin(), all.end());
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
d.resize(n);
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  d[i].push_back({a, -1});
  }
ll q;
cin>>q;
for (ll i=0; i<q; i++)
  {
  ll ty;
  cin>>ty;
  if (ty==1)
    {
    ll p, x;
    cin>>p>>x;
    p--;
    d[p].push_back({x, i});
    all.push_back(-10);
    }
  else
    {
    ll x;
    cin>>x;
    all.push_back(x);
    }
  }
calc();

vector <ll> ans;
for (ll i=0; i<n; i++)
  {
  ll b=d[i].back().F;
  ll t=d[i].back().S;
  ll b2=-10;
  b2=suf[q-1-t];
  if (viv)
    cout<<i<<' '<<t<<' '<<b<<' '<<b2<<endl;
  ans.push_back(max(b, b2));
  }
for (auto i:ans)
  cout<<i<<' ';







    return 0;
}