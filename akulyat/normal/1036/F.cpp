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
const long double eps=1e-8;

ll n,i,j;
vector <ll> m;
set<ll> s;
bool viv=false;

vector <long long> erat(long long last)
{
vector <bool> bad;
vector <long long> r;
for (long long i=0; i<last+10; i++)
  bad.push_back(true);
for (long long i=2; i<=last; i++)
  if (bad[i])
    {
    long long j=2;
    while (j*i<=last)
      {
      bad[j*i]=false;
      j++;
      }
    r.push_back(i);
    }
return r;
}

void solve(ll n)
{
ll ans=n;
ans-=floor(sqrt(n));
ans-=(upper_bound(m.begin(), m.end(), n)-m.begin());
cout<<ans<<'\n';
}

ll power(ll v, ll st)
{
ll res=1;
for (ll i=0; i<st; i++)
  res*=v;
return res;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=1; i<=1000; i++)
  s.insert(i*i);
vector <ll> p=erat(70);
p.erase(p.begin());

for (auto d:p)
  {
  set <ll> add;
  ll j=1;
  ll st=power(j, d);
  ld double_st=pow((ld)j, d);
  while (double_st-eps<inf-7)
    {
    if (s.find(j)==s.end())
      m.push_back(st);
    add.insert(st);
    j++;
    st=power(j, d);
    double_st=pow((ld)j, d);
    }
  for (auto i:add)
    s.insert(i);
  }
sort(m.begin(), m.end());
/*
cout<<m.size()<<endl;
for (auto i:m)
  if (i<=1000)
    cout<<i<<' ';
cout<<endl;
// */
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  solve(a);
  }





    return 0;
}