#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

ll n,i,j;
vector <ll> reb[3*ml];
vector <ll> m,ty,por;
long long col[ml+kk],z[ml+kk];
bool how[ml+kk];
bool viv=false;
map <string, ll> mp;

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

void simple()
{
for (i=n-1; i>=0; i--)
  {
  ll v=por[i];
//  cout<<"Work in "<<v<<' ';
  if (ty[v]==0)
    z[v]=m[v];
  if (ty[v]==1)
    z[v]=z[reb[v][0]]^1;
  if (ty[v]==2)
    z[v]=z[reb[v][0]]&z[reb[v][1]];
  if (ty[v]==3)
    z[v]=z[reb[v][0]]^z[reb[v][1]];
  if (ty[v]==4)
    z[v]=z[reb[v][0]]|z[reb[v][1]];
//  cout<<z[v]<<endl;
  }

}

void solve(ll v)
{
if (ty[v]==1)
  {
  how[reb[v][0]]=how[v];
  return;
  }
if (ty[v]==2)
  {
  if (z[reb[v][1]]==1)
    how[reb[v][0]]=how[v];
  if (z[reb[v][0]]==1)
    how[reb[v][1]]=how[v];
  return;
  }
if (ty[v]==3)
  {
  how[reb[v][0]]=how[v];
  how[reb[v][1]]=how[v];
  return;
  }
if (ty[v]==4)
  {
  if (z[reb[v][1]]==0)
    how[reb[v][0]]=how[v];
  if (z[reb[v][0]]==0)
    how[reb[v][1]]=how[v];
  return;
  }
how[reb[v][0]]=0;
if (ty[v]!=1)
  how[reb[v][1]]=0;
}



int main()
{
mp["IN"]=0;
mp["NOT"]=1;
mp["AND"]=2;
mp["XOR"]=3;
mp["OR"]=4;
cin>>n;
for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  ll a,b;
  b=0;
  cin>>a;
  if (s!="IN"&&s!="NOT")
    cin>>b;
  if (s!="IN")
    a--, b--;
  ty.push_back(mp[s]);
  if (s!="IN")
    {
    reb[i].push_back(a);
    if (b!=-1)
      reb[i].push_back(b);
    m.push_back(-1);
    }
  else
    m.push_back(a);
  }

for (i=0; i<n; i++)
  col[i]=-1;
DFS(0, 0);


vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.begin(), tos.end());

for (auto i:tos)
  por.push_back(i.S);

/*
cout<<"Poryadok"<<endl;
for (auto i:por)
  cout<<i<<' ';
cout<<endl;
// */
simple();

how[0]=true;
for (auto i:por)
  if (ty[i])
    solve(i);
for (i=0; i<n; i++)
  if (!ty[i])
    cout<<(how[i]^z[0]);
 /*
cout<<endl;
for (i=0; i<n; i++)
  cout<<z[i]<<' ';
cout<<endl;
for (i=0; i<n; i++)
  cout<<how[i]<<' ';
cout<<endl;
// */





    return 0;
}