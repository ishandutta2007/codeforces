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


ll n,i,j,k;
vector <ll> m;
bool viv=false;


int main()
{
cin>>n>>k;
for (i=0; i<k; i++)
  m.push_back(0);
for (i=0; i<n; i++)
  {
  ll a, b;
  cin>>a>>b;
  a--; b--;
  for (ll j=a; j<=b; j++)
    m[j]++;
  }
vector <ll> ans;
for (i=0; i<k; i++)
  if (m[i]==0)
    ans.push_back(i);

cout<<ans.size()<<endl;
for (auto i:ans)
  cout<<i+1<<' ';


    return 0;
}