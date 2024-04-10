#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

const ll kk=1000;
const ll ml=kk*kk;
const ll mod=ml*kk+7;
const ll inf=ml*ml*ml+7;

vector <ll> m;
ll want[ml];
ll kol[ml];
ll i,j,u,n, len, k, w, r, bad;
bool viv=false;

void badd()
{
cout<<-1<<endl;
exit(0);
}

void write(ll l, ll r)
{
ll ma=*max_element(m.begin(), m.end());
vector <ll> have(ma+10, 0);
vector <ll> cut;
ll rl=((l/k)*k);
ll rr=rl+k;
for (ll i=rl; i<l; i++)
  cut.push_back(i);
for (ll i=l; i<r; i++)
  if (have[m[i]]==want[m[i]]&&cut.size()<r-rr)
    cut.push_back(i);
  else
    have[m[i]]++;
cout<<cut.size()<<endl;
for (auto i:cut)
  cout<<i+1<<' ';
cout<<endl;
exit(0);
}

void work(ll l)
{
if (viv)
  cout<<"Start "<<l<<endl;
while (bad)
  {
  if (viv)
    cout<<"Add "<<r<<endl;
  if (viv)
    {
    cout<<"Had "<<endl;
    for (ll i=0; i<10; i++)
      cout<<kol[i]<<' ';
    cout<<endl;
    }

  if (r==len)
    badd();
  kol[m[r]]++;
  if (kol[m[r]]==want[m[r]])
    bad--;
  if (viv)
    {
    cout<<"Have "<<endl;
    for (ll i=0; i<10; i++)
      cout<<kol[i]<<' ';
    cout<<endl;
    }
  r++;
  }
ll lg=l-(l%k);
ll rg=lg+k;
ll cut=r-rg;
if (viv)
  cout<<lg<<' '<<rg<<' '<<l<<' '<<r<<' '<<cut<<endl;
if (cut<=m.size()-n*k)
  write(l, r);

if (kol[m[l]]==want[m[l]])
  bad++;
kol[m[l]]--;
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>len>>k>>n>>w;
for (ll i=0; i<len; i++)
  {
  ll a;
  cin>>a;
  a--;
  m.push_back(a);
  }
for (ll i=0; i<w; i++)
  {
  ll a;
  cin>>a;
  a--;
  want[a]++;
  }
for (auto i:want)
  if (i)
    bad++;
r=0;
for (ll i=0; i<len; i++)
  work(i);











    return 0;
}