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
vector <vector <pll>> reb;
vector <ll> col,tc;
bool viv=false;


void solve()
{
cin>>n>>m;
reb.clear();
reb.resize(3*n);
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back({b, i});
  reb[b].push_back({a, i});
  }
vector <bool> used(3*n, false);
vector <ll> mat;
for (ll i=0; i<3*n; i++)
  {
  if (!used[i])
    {
    bool was=false;
    for (auto s:reb[i])
      {
      if (!used[s.F]&&!was)
        {
        used[i]=true;
        used[s.F]=true;
        mat.push_back(s.S);
        was=true;
        }
      }
    }
  }

bool full=false;
if (mat.size()>=n)
  {
  cout<<"Matching"<<'\n';
  sort(mat.begin(), mat.end());
  if (!full)
    while (mat.size()>n)
      mat.pop_back();
  for (auto i:mat)
    cout<<i+1<<' ';
  cout<<'\n';
  }
else
  {
  cout<<"IndSet"<<'\n';
  vector <ll> ans;
  for (ll i=0; i<3*n; i++)
    if (!used[i])
      ans.push_back(i);
  if (!full)
    while (ans.size()>n)
      ans.pop_back();
  for (auto i:ans)
    cout<<i+1<<' ';
  cout<<'\n';
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t--)
  solve();







    return 0;
}