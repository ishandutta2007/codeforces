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
const long long gs=200*kk;

ll n,i,j;
vector <pll> m;
vector <ll> col;
vector <ll> e1[gs+10];
vector <ll> e2[gs+10];
vector <bool> was1,was2;
set <ll> s1,s2;
map <ll, ll> mp1,mp2;
bool viv=false;

void DFS(long v, long c)
{
col[v]=c;
ll x=m[v].F;
ll y=m[v].S;
if (!was1[x])
  for (auto s:e1[x])
    {
    was1[x]=true;
    if (col[s]==-1)
      DFS(s, c);
    }
if (!was2[y])
  for (auto s:e2[y])
    {
    was2[y]=true;
    if (col[s]==-1)
      DFS(s, c);
    }
}



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  s1.insert(a);
  s2.insert(b);
  m.push_back({a, b});
  }
i=0;
for (auto v:s1)
  mp1[v]=i, i++;
i=0;
for (auto v:s2)
  mp2[v]=i, i++;

for (auto &i:m)
  i.F=mp1[i.F], i.S=mp2[i.S];

for (i=0; i<n; i++)
  e1[m[i].F].push_back(i),
  e2[m[i].S].push_back(i);
for (i=0; i<s1.size(); i++)
  was1.push_back(false);
for (i=0; i<s2.size(); i++)
  was2.push_back(false);



ll tc=0;
for (i=0; i<n; i++)
  col.push_back(-1);
for (i=0; i<n; i++)
  if (col[i]==-1)
    DFS(i, tc), tc++;

vector <ll> kol(tc, 0);
set <ll> var1[tc],var2[tc];
for (i=0; i<n; i++)
  kol[col[i]]++;

for (i=0; i<n; i++)
  var1[col[i]].insert(m[i].F),
  var2[col[i]].insert(m[i].S);

vector <ll> st;
st.push_back(1);
for (i=1; i<=250*kk; i++)
  st.push_back((st.back()*2)%mod);
ll ans=1;
for (i=0; i<tc; i++)
  {
  ll mn=0;
  mn=st[var1[i].size()+var2[i].size()];
  if (kol[i]<var1[i].size()+var2[i].size())
    mn--;
  mn+=mod;
  mn%=mod;
  ans*=mn;
  ans%=mod;
  }
cout<<ans<<endl;

/*
for (i=0; i<tc; i++)
  {
  cout<<i<<"__";
  cout<<kol[i]<<':';
  for (auto j:var1[i])
    cout<<j<<' ';
  cout<<"and ";
  for (auto j:var2[i])
    cout<<j<<' ';
  cout<<endl;
  }
*/

    return 0;
}