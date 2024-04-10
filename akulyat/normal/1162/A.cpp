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


ll n,i,j, h, m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>h>>m;
vector <ll> ans(n, h);
for (i=0; i<m; i++)
  {
  ll l, r, g;
  cin>>l>>r>>g;
  l--, r--;
  for (ll i=l; i<=r; i++)
    ans[i]=min(ans[i], g);
  }
ans[0]*=ans[0];
for (ll i=1; i<n; i++)
  ans[0]+=ans[i]*ans[i];
cout<<ans[0]<<endl;
    return 0;
}