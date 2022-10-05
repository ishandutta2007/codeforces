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
ll n,d,x,y;
cin>>n>>x>>y>>d;
if (abs(x-y)%d==0)
  cout<<(abs(x-y)-1+d)/d<<endl;
else
  {
  ll ans=inf;
  if (abs(n-y)%d==0)
    ans=min(ans, abs(n-y)/d+(abs(n-x)+d-1)/d);
  if (abs(1-y)%d==0)
    ans=min(ans, abs(1-y)/d+(abs(1-x)+d-1)/d);
  if (ans==inf)
    ans=-1;
  cout<<ans<<endl;
  }
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t)
  solve(), t--;

    return 0;
}