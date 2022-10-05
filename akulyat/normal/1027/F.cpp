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
const long long gs=500*kk*2;

long n,i,j;
set <long> all;
vector <long> ril;
vector <bool> used;
vector <pll> p;
vector <long> var[2*gs+10];
set <long> t[gs+10];
long col[gs+10];
bool viv=false;

void DFS(long v, long c)
{
col[v]=c;
t[c].insert(p[v].F);
t[c].insert(p[v].S);
if (!used[p[v].F])
  {
  used[p[v].F]=true;
  for (auto s:var[p[v].F])
    if (col[s]==-1)
      DFS(s, c);
  }
if (!used[p[v].S])
  {
  used[p[v].S]=true;
  for (auto s:var[p[v].S])
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
  all.insert(a);
  all.insert(b);
  p.push_back({a, b});
  }
for (auto v:all)
  ril.push_back(v);
for (auto &j:p)
  j.F=lower_bound(ril.begin(), ril.end(), j.F)-ril.begin(),
  j.S=lower_bound(ril.begin(), ril.end(), j.S)-ril.begin();

for (i=0; i<n; i++)
  var[p[i].F].push_back(i),
  var[p[i].S].push_back(i);
for (i=0; i<all.size(); i++)
  used.push_back(false);

for (i=0; i<n; i++)
  col[i]=-1;
ll tc=0;
for (i=0; i<n; i++)
  if (col[i]==-1)
    DFS(i, tc), tc++;

vector <ll> kol(tc, 0);
for (i=0; i<n; i++)
  kol[col[i]]++;

ll last=0;
for (i=0; i<tc; i++)
  {
  if (kol[i]>t[i].size())
    {cout<<"-1"<<endl; return 0;}
  if (kol[i]<t[i].size())
    t[i].erase(t[i].find(*t[i].rbegin()));
  ll z=*t[i].rbegin();
  last=max(last, z);
  }
cout<<ril[last]<<endl;
    return 0;
}