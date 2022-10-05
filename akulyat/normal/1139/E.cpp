#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long    ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j,k,d, ans;
vector <pll> m;
vector <ll> q, wr, p;
vector <bool> used;
vector <ll> reb[10*kk];
set <pll> s;
bool viv=false;

void read()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back({a, 0});
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a; a--;
  m[i].S=a;
  }

cin>>d;
vector <bool> add(n, true);
for (ll i=0; i<d; i++)
  {
  ll num;
  cin>>num;
  num--;
  q.push_back(num);
  add[num]=false;
  }
for (ll i=0; i<n; i++)
  if (add[i])
    q.push_back(i), add[i]=false;
reverse(q.begin(), q.end());

used.resize(n, false);
p.resize(n, -1);
}

void clean()
{
for (ll i=0; i<n; i++)
  used[i]=false;
}

bool kuhn(ll v)
{
if (used[v])
  return false;
used[v]=true;
for (auto s:reb[v])
  if (p[s]==-1||kuhn(p[s]))
    {
    p[s]=v;
    return true;
    }
return false;
}



void work(pll pr)
{
reb[pr.F].push_back(pr.S);
bool cont=true;
while (cont)
  {
  cont=false;
  if (kuhn(ans))
    ans++, cont=true;
  clean();
  }
wr.push_back(ans);
}


void write()
{
wr.pop_back();
reverse(wr.begin(), wr.end());
while(wr.size()>d)
  wr.pop_back();
for (auto i:wr)
  cout<<i<<endl;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
read();
wr.push_back(0);
for (auto i:q)
  work(m[i]);
write();




    return 0;
}