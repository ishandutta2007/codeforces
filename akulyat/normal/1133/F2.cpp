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

long n,m,i,j,d;
vector <long> reb[gs+10];
vector <ll> col, col2,tc;
vector <pll> ans;
bool viv=false;

void DFS(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1&&s!=0)
    {
    DFS(s, c);
    }
  }
}

void DFS2(long v, long c)
{
col2[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col2[s]==-1&&s!=0)
    {
    ans.push_back({v, s});
    DFS2(s, c);
    }
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>d;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
col.assign(n, -1);
col2.assign(n, -1);
ll nex=0;
for (ll i=1; i<n; i++)
  if (col[i]==-1)
    DFS(i, nex), nex++;

set <ll> s;
for (auto sos:reb[0])
  s.insert(col[sos]);

if (s.size()>d||reb[0].size()<d)
  {
  cout<<"NO"<<endl;
  exit(0);
  }
cout<<"YES"<<endl;
vector <pll> can;
for (auto sos:reb[0])
  can.push_back({col[sos], sos});
can.push_back({mod, -1});
sort(can.begin(), can.end());

vector <ll> use;
ll ost=d;
col2[0]=0;
for (ll i=0; i<can.size()-1; i++)
  if (can[i].F!=can[i+1].F&&ost)
    use.push_back(can[i].S), col2[can[i].S]=1, ost--;
for (ll i=0; i<can.size()-1; i++)
  if (col2[can[i].S]==-1&&ost)
    use.push_back(can[i].S), col2[can[i].S]=1, ost--;

for (auto v:use)
  ans.push_back({0, v}), DFS2(v, 1);
for (auto i:ans)
  cout<<i.F+1<<' '<<i.S+1<<endl;





    return 0;
}