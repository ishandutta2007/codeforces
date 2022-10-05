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
const long long gs=500*kk;

long n,m,i,j, len;
vector <long> reb[gs+10];
vector <ll> col,tc, kids, maxi;
bool viv=false;

void DFS(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c+1);
    }
  }
}

vector <ll> pord()
{
vector <pll> tos;
for (ll i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.begin(), tos.end());
vector <ll> res;
for (auto i:tos)
  res.push_back(i.S);
return res;
}

ll d(ll v)
{
v+=1;
cout<<'d'<<' '<<v<<endl;
ll ans;
cin>>ans;

if (ans==0)
  {
  cout<<'!'<<' '<<v<<endl;
  exit(0);
  }

return ans;
}

ll s(ll v)
{
v+=1;
cout<<'s'<<' '<<v<<endl;
ll ans;
cin>>ans;
ans--;
return ans;
}

void check(ll v)
{
vector <pll> k;
kids[v]=1;
for (auto sos:reb[v])
  if (col[sos]>col[v])
    k.push_back({kids[sos], sos});
sort(k.rbegin(), k.rend());
if (k.size())
  {
  for (auto p:k)
    kids[v]+=p.F;
  maxi[v]=k[0].S;
  }
}

void work()
{
ll now=0;
ll to=len;
ll ost=n;
ll lev=len;
while (true)
  {
  ll nnow=now;
  ll steps=0;
  vector <ll> p;
  p.push_back(now);
  while (kids[nnow]*2>=ost&&kids[nnow]>1&&col[nnow]<lev)
    {
    nnow=maxi[nnow], steps++, p.push_back(nnow);
    if (viv)
      cout<<"OO, "<<nnow<<endl;
    }
  if (viv)
    {
    cout<<"Koko: ";
    for (auto i:p)
        cout<<i<<' ';
    cout<<endl;
    }
  ll have=d(nnow);
  ll was=len-col[now];
  /**
  a b
  a+b=steps;
  was-a-a+steps=have
  2*a=was+steps-have;
  **/
  now=p[(was+steps-have)/2];
  if (col[now]!=lev)
    now=s(now);
  ost=kids[now];
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>n;
m=n-1;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
col.assign(n, -1);
DFS(0, 0);
auto por=pord();
reverse(por.begin(), por.end());
kids.resize(n, 0);
maxi.resize(n, -1);
for (auto v:por)
  check(v);

len=d(0);
work();






    return 0;
}