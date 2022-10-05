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

void solve(ll v)
{
ll ans=0;
if (v&1)
  ans++, v-=9;
if ((v/2)&1)
  ans++, v-=6;

if (v<0)
  {
  cout<<-1<<endl;
  return;
  }
ans+=v/4;
cout<<ans<<'\n';


}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  solve(a);
  }


    return 0;
}