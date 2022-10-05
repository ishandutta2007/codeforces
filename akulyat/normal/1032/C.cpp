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
vector <ll> m,ans;
vector <bool> can[5];
bool viv=false;

void ask(ll a, ll b)
{
can[b][a]=false;
for (ll j=0; j<5; j++)
  if (can[j][a-1])
    {
    if (m[a]>m[a-1]&&b>j)
      can[b][a]=true;
    if (m[a]<m[a-1]&&b<j)
      can[b][a]=true;
    if (m[a]==m[a-1]&&b!=j)
      can[b][a]=true;
    }
}

void bad()
{
cout<<-1;
exit(0);
}


void write()
{
ll from=-1;
for (j=0; j<5; j++)
  if (can[j][n-1])
    from=j;
if (from==-1)
  bad();
ans.push_back(from);
for (i=n-2; i>=0; i--)
  {
  ll last=from;
  from=-1;
  for (j=0; j<5; j++)
    if (can[j][i])
      {
      if (m[i]<m[i+1]&&j<last)
        from=j, j=5;
      if (m[i]>m[i+1]&&j>last)
        from=j, j=5;
      if (m[i]==m[i+1]&&j!=last)
        from=j, j=5;
      }
  if (from==-1)
    bad();
  ans.push_back(from);
  }
for (auto &i:ans)
  i++;
reverse(ans.begin(), ans.end());
for (auto i:ans)
  cout<<i<<' ';
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  m.push_back(a);
  for (j=0; j<5; j++)
    can[j].push_back(true);
  }

for (i=1; i<n; i++)
  for (j=0; j<5; j++)
    ask(i, j);

write();



    return 0;
}