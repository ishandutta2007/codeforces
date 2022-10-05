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
bool viv=false;

void solve()
{
ll n, x;
cin>>n>>x;
vector <pll> m(n);
for (auto &i:m)
  cin>>i.F>>i.S;

ll want=0;
for (auto i:m)
  want=max(want, i.F);

if (x<=want)
  {
  cout<<1<<endl;
  return;
  }

x-=want;
for (auto &i:m)
  i.F-=i.S;
sort(m.begin(), m.end());

if (m.back().F<=0)
  {
  cout<<-1<<endl;
  return;
  }

cout<<1+(x+m.back().F-1)/m.back().F<<endl;
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