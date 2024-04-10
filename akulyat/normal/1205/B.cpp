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


ll n,i,j, v, e;
vector <ll> m, col;
vector <bool> ver;
vector <vector <ll>> reb;
bool viv=false;

void ans(ll res)
{
cout<<res<<endl;
exit(0);
}


void build()
{
vector <vector <ll>> kol(64);
for (ll i=0; i<n; i++)
  {
  ll j=0;
  ll x=m[i];
  while (x)
    {
    if (x&1)
      kol[j].push_back(i);
    x>>=1;
    j++;
    }
  }
for (auto i:kol)
  if(i.size()>=3)
    ans(3);
ver.resize(n);
reb.resize(n);
for (auto i:kol)
  if (i.size()>1)
    {
    reb[i[0]].push_back(i[1]);
    reb[i[1]].push_back(i[0]);
    e++;
    ver[i[0]]=1;
    ver[i[1]]=1;
    }
}

ll from(ll v)
{
vector <ll> lev(n, -1);
vector <ll> by(n, -1);
deque <ll> st;
st.push_back(v);
lev[v]=0;
while (st.size())
  {
  ll cur=st.front();
  st.pop_front();
  for (auto sos:reb[cur])
    {
    if (lev[sos]==-1)
      {
      st.push_back(sos);
      if (viv)
        cout<<"In "<<v<<" add "<<sos<<endl;
      lev[sos]=lev[cur]+1;
      by[sos]=cur;
      }
    }
  }

ll sh=ml;
for (ll i=0; i<n; i++)
  {
  for (auto sos:reb[i])
    if (lev[i]!=-1&&lev[sos]!=-1&&by[i]!=sos&&by[sos]!=i)
      {
      ll len=lev[i]+lev[sos];
      len++;
      if (len>2)
        sh=min(sh, len);
      }
  }

return sh;
}


void show()
{
if (!viv)
  return;
cout<<"BFS: ";
for (ll i=0; i<n; i++)
  cout<<from(i)<<' ';
cout<<endl;
for (ll i=0; i<n; i++)
  {
  cout<<i<<": ";
  for (auto sos:reb[i])
    cout<<sos<<' ';
  cout<<endl;
  }
}

void check()
{
v=0;
for (auto i:ver)
  v+=i;

ll sh=kk;
for (ll i=0; i<n; i++)
  if (ver[i])
    sh=min(sh, from(i));
if (sh>=kk)
  ans(-1);
show();
ans(sh);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
build();
check();



    return 0;
}
/**
7
3 6 12 24 48 96 65





**/