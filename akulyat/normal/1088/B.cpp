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
ll k;
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
set <ll> s;
for (auto i:m)
  s.insert(i);
m.clear();
m.push_back(0);
for (auto i:s)
  m.push_back(i);
while (m.size()<k+10)
  m.push_back(m.back());
vector <ll> ans;
for (i=0; i<m.size()-1; i++)
  m[i]=m[i+1]-m[i];
for (i=0; i<k; i++)
  ans.push_back(m[i]);
for (auto i:ans)
  cout<<i<<'\n';





    return 0;
}