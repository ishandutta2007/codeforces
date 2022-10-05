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

long n,m,i,j;
ll ANS;
vector <long> reb[gs+10];
map <pll, ll> mp;
vector <ll> col,tc,v,por,ans;
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

void prepare()
{
vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.begin(), tos.end());
for (auto i:tos)
  por.push_back(i.S);
reverse(por.begin(), por.end());
}

void work(ll v)
{
vector <ll> kids;
for (auto i:reb[v])
  if (col[i]>col[v])
    kids.push_back(i);
vector <ll> vars;
vars.push_back(0);
vars.push_back(0);
for (auto s:kids)
  vars.push_back(ans[s]-mp[{v, s}]);
sort(vars.rbegin(), vars.rend());
ANS=max(ans[v]+vars[0]+vars[1], ANS);
ans[v]+=vars[0];
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
m=n-1;
v.resize(n);
for (auto &i:v)
  cin>>i;
for (i=0; i<m; i++)
  {
  long long a,b,c;
  cin>>a>>b>>c;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  mp[{a, b}]=c;
  mp[{b, a}]=c;
  }
col.assign(n, -1);
tc.assign(n, -1);
DFS(0, 0);
prepare();
ans=v;
for (auto i:por)
  work(i);
cout<<ANS<<endl;







    return 0;
}