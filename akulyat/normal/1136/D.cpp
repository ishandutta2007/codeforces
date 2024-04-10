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
vector <long> reb[gs+10];
vector <long> rreb[gs+10];
vector <ll> col,tc, q, st, p, best;
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

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
q.resize(n);
ll nex=0;
st.resize(n);
for (auto &i:q)
  cin>>i, i--, st[i]=nex, nex++;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[b].push_back(a);
  rreb[a].push_back(b);
  }
col.assign(n, -1);
best.resize(n, 0);

vector <bool> stay(n, false);
reverse(q.begin(), q.end());
ll sh=0;
ll nast=q[0];
ll ans=0;
for (auto i:q)
  {
  ll ost=sh;
  for (auto s:rreb[i])
    if (stay[s])
      ost--;
//  cout<<i<<' '<<ost<<endl;
  if (ost)
    stay[i]=true, sh++;
  else
    ans++;
  if (i==nast)
    stay[i]=true, sh++, ans--;
  }
cout<<ans<<endl;


    return 0;
}