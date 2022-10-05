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

ll n,m,i,j,ans,lans;
vector <long> reb[gs+10];
vector <ll> col,tc,p,v,l;
vector <bool> use;
bool viv=false;
map <ll, vector <ll> > mp;


void DFS(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1&&use[s])
    {
    DFS(s, c+1);
    }
  }
}

void BFS(long v)
{
vector <long> st;
st.push_back(v);
long s=0;
tc[v]=0;

while (s<st.size())
  {
  long e=st[s];
  long l=reb[e].size();
  for (long i=0; i<l; i++)
    {
    long s=reb[e][i];
    if (tc[s]==-1)
      {
      st.push_back(s);
      tc[s]=tc[e]+1;
      }
    }
  s++;
  }

}

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

void easy()
{
ll kol=0;
for (auto i:v)
  if (i-1)
    kol++;
if (kol)
  return;
cout<<0<<endl;
exit(0);
}

void parse(ll p)
{
ll val=v[p];
for (ll i=2; i<ceil(sqrt(val))+1; i++)
  if (i*i<=val&&val%i==0)
    {
    mp[i].push_back(p);
    if (i*i!=val)
      mp[val/i].push_back(p);
    while (!(val%i))
      val/=i;
    }
if (val!=1)
  mp[val].push_back(p);
}

vector <ll> sor(vector <ll> v)
{
vector <pll> tos;
for (auto i:v)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());
vector <ll> r;
for (auto i:tos)
  r.push_back(i.S);
return r;
}

void work (ll v)
{
ll la=-1, lb=-1;
for (auto s:reb[v])
  if (col[s]>col[v]&&use[s])
    {
              if (viv)
                cout<<"friend "<<v<<' '<<s<<endl;
    l[v]=max(l[v], 1+l[s]);
    if (l[s]>=la)
      lb=la, la=l[s];
    else
      if (l[s]>=lb)
        lb=l[s];
    }
lans=max(lans, l[v]);
if (la!=-1&&lb!=-1)
  lans=max(lans, 1+la+lb);
          if (viv)
            cout<<v<<' '<<l[v]<<' '<<la<<' '<<' '<<lb<<endl;
}


void solve(ll d)
{
for (auto v:mp[d])
  use[v]=true;
for (auto v:mp[d])
  l[v]=1;
          if (viv)
            {
            cout<<d<<": ";
            for (auto v:mp[d])
              cout<<v<<' ';
            cout<<endl;
            }
for (auto v:mp[d])
  if (col[v]==-1)
    DFS(v, 0);
vector <ll> por=sor(mp[d]);
lans=0;
for (auto v:por)
  work(v);
ans=max(ans, lans);
for (auto v:mp[d])
  use[v]=false;
for (auto v:mp[d])
  col[v]=-1;
          if (viv)
            cout<<d<<' '<<lans<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/// //////////////////////////////////////////////////////////////////////////////////////////////
p=erat(200*kk);
cin>>n;
m=n-1;
v.resize(n);
for (auto &i:v)
  cin>>i;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
easy();
col.assign(n, -1);
tc.assign(n, -1);
l.assign(n, 1);
use.assign(n, false);
for (ll i=0; i<n; i++)
  parse(i);
for (auto d:p)
  solve(d);
cout<<ans<<endl;

    return 0;
}