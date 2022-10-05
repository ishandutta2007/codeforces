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


ll n,i,j;
vector <ll> m;
vector <ll> ans[200*kk];
bool viv=false;
set <ll> s;
map <ll, ll> mp;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  s.insert(a);
  }

j=0;
for (auto i:s)
  {
  mp[i]=j;
  j++;
  }

for (i=0; i<n; i++)
  m[i]=mp[m[i]];

vector <ll> col;
for (i=0; i<n; i++)
  col.push_back(-1);

ll kol=0;
for (i=0; i<n; i++)
  if (col[i]==-1)
    {
    ll cur=i;
    while (m[cur]!=i)
      {
      col[cur]=1;
      ans[kol].push_back(cur);
      cur=m[cur];
      }
    col[cur]=1;
    ans[kol].push_back(cur);
    cur=m[cur];
    kol++;
    }

cout<<kol<<endl;
for (i=0; i<kol; i++)
  {
  cout<<ans[i].size()<<' ';
  for (auto j:ans[i])
    cout<<j+1<<' ';
  cout<<'\n';
  }







    return 0;
}