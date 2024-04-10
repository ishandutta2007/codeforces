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
vector <ll> m[600*kk];
vector <ll> p[600*kk],can[600*kk];
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  a--;
  m[a].push_back(b);
  }
for (i=0; i<k; i++)
  sort(m[i].rbegin(), m[i].rend());
for (i=0; i<k; i++)
  {
  p[i].push_back(0);
  for (j=0; j<m[i].size(); j++)
    p[i].push_back(p[i].back()+m[i][j]);
  }
for (i=0; i<k; i++)
  {
  for (j=0; j<p[i].size(); j++)
    can[j].push_back(p[i][j]);
  }
ll ans=0;
for (i=0; i<n+1; i++)
  {
  sort(can[i].rbegin(), can[i].rend());
  while (can[i].size()&&can[i].back()<0)
    can[i].pop_back();
  ll lsum=0;
  for (auto j:can[i])
    lsum+=j;
  ans=max(ans, lsum);
  }
cout<<ans<<endl;





    return 0;
}