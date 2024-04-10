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
vector <ll> m,m1;
bool viv=false;
set <ll> s;
map <ll, ll> mp;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  m1.push_back(a);
  s.insert(a);
  }
sort(m1.begin(), m1.end());

j=0;
for (auto i:s)
  {
  mp[i]=j;
  j++;
  }

for (i=0; i<n; i++)
  cout<<m1[(mp[m[i]]+1)%n]<<' ';



    return 0;
}