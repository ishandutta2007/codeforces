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


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
ll kol=0;
for (auto i:m)
  if (i<0)
    kol++;
vector <ll> bad;
vector <ll> good;
ll pl=-1;
if (kol&1)
  {
  ll ma=-inf;
  for (i=0; i<n; i++)
    if (m[i]<0)
      if (m[i]>ma)
        ma=m[i], pl=i;
  }

for (i=0; i<n; i++)
  if (m[i]==0||i==pl)
    bad.push_back(i);
  else
    good.push_back(i);

for (i=1; i<bad.size(); i++)
  cout<<1<<' '<<bad[i-1]+1<<' '<<bad[i]+1<<'\n';
for (i=1; i<good.size(); i++)
  cout<<1<<' '<<good[i-1]+1<<' '<<good[i]+1<<'\n';
if (!bad.empty()&&!good.empty())
  cout<<2<<' '<<bad.back()+1<<endl;




    return 0;
}