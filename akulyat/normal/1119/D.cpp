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


ll n,i,j, counter, q;
vector <ll> m, ans;
bool viv=false;
vector <pll> v;

void read()
{
cin>>n;
set <ll> s;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  s.insert(a);
  }
for (auto i:s)
  m.push_back(i);
n=m.size();

vector <ll> rl;
for (ll i=1; i<n; i++)
  rl.push_back(m[i]-m[i-1]);
m=rl;
}

void work()
{
ll l, r;
cin>>l>>r;
r-=l;
l=0;
v.push_back({r+1, counter});
counter++;
}


void prepare()
{
vector <ll> sum(q+1);
vector <ll> norm(q);
ans.resize(q);
for (auto val:m)
  {
  if (viv)
    cout<<"Go with "<<val<<"   ";
  ll z=lower_bound(v.begin(), v.end(), make_pair(val, inf))-v.begin();
  if (viv)
    cout<<z<<endl;
  sum[z]+=val;
  if (z>0)
    norm[z-1]++;
  }
ll cur=1;
for (ll i=norm.size()-1; i>=0; i--)
  {
  cur+=norm[i];
  ans[i]+=v[i].F*cur;
  }
cur=0;
for (ll i=0; i<q; i++)
  {
  cur+=sum[i];
  ans[i]+=cur;
  }
}



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
read();
cin>>q;
ll rq=q;
while (rq)
  work(), rq--;
sort(v.begin(), v.end());
prepare();


vector <ll> wans(q);
for (ll i=0; i<q; i++)
  wans[v[i].S]=ans[i];

for (auto i:wans)
  cout<<i<<' ';
cout<<endl;


    return 0;
}