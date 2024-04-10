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

long n,m,i,j,k;
vector <long> reb[gs+10];
vector <ll> w[gs+10];
vector <ll> col,tc,from;
set <pll> s;
map <pll, ll> num;
bool viv=false;
vector <bool> was;
vector <ll> ans;


void add(ll v)
{
for (ll j=0; j<reb[v].size(); j++)
  {
  ll nv=col[v]+w[v][j];
  ll sos=reb[v][j];
  if (col[sos]>nv)
    {
    s.erase({col[sos], sos});
    col[sos]=nv;
    from[sos]=v;
    s.insert({col[sos], sos});
    }
  }
}

void Dij()
{
vector <ll> st;
for (auto &i:col)
  i=inf;
for (auto &i:from)
  i=inf;
col[0]=i;
add(0);
for (i=1; i<n; i++)
  s.insert({col[i], i});
while (k&&ans.size()<n-1)
  {
  ll fr=(*s.begin()).S;
  s.erase(s.begin());
  add(fr);
  ans.push_back(num[{from[fr], fr}]);
//  cout<<"Add "<<fr<<' '<<from[fr]<<endl;
  k--;
  }
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>k;
for (i=0; i<m; i++)
  {
  long a,b,c;
  cin>>a>>b>>c;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  num[{a, b}]=i;
  num[{b, a}]=i;
  w[a].push_back(c);
  w[b].push_back(c);
  was.push_back(false);
  }
col.assign(n, -1);
from.assign(n, -1);
tc.assign(n, -1);
Dij();

cout<<ans.size()<<endl;
for (auto i:ans)
  cout<<i+1<<' ';










    return 0;
}