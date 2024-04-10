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

long n,m,i,j,k,ans;
vector <long> reb[gs+10];
set <ll> all;
map <ll, vector <pll>> mp;
vector <ll> z,st;
long long col[gs+10];
long long tc[gs+10];
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


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  z.push_back(a);
  }
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  all.insert(z[a]^z[b]);
  mp[z[a]^z[b]].push_back({a, b});
  }
for (i=0; i<n; i++)
  col[i]=-1;

st.push_back(1);
for (i=0; i<ml; i++)
  st.push_back((st.back()*2)%mod);
ans=0;

ans=(((st[k]-all.size()+mod)%mod)*(st[n]))%mod;

for (auto x:all)
  {
  set <ll> ver;
  for (auto e:mp[x])
    ver.insert(e.F), ver.insert(e.S);
  for (auto v:ver)
    reb[v].clear(), col[v]=-1;
  for (auto e:mp[x])
    reb[e.F].push_back(e.S), reb[e.S].push_back(e.F);
  ll comp=0;
  for (auto v:ver)
    if (col[v]==-1)
      DFS(v,  1), comp++;
  comp+=n-ver.size();
  ans+=st[comp];
//  cout<<"Add "<<st[comp]<<" by xor value=="<<x<<endl;
  ans%=mod;
  }

cout<<ans;






    return 0;
}